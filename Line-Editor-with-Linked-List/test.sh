returnStatus=0

# Only show colours on local "Git Bash" terminal
passFormat="if [ $TERM = "xterm" ]; then tput sgr0 && tput setaf 2; fi"
failFormat="if [ $TERM = "xterm" ]; then tput sgr0 && tput setaf 1; fi"
normalFormat="if [ $TERM = "xterm" ]; then tput sgr0; fi"

# If not on Linux set output to .exe
unameValue="$(uname -s)"
echo "Testing OS Platform: $unameValue"
fileExtension=".exe"
if [  $unameValue = "Linux" ] || [  $unameValue = "Darwin" ] ; then
    fileExtension=".out"
fi

echo "Running tests..."
echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
EDIT output.txt
:I
one
two
three
four
five
six
:L
:L
:D 5
:L
:L
:I 3
333
:L
:E
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_1=$(cat output.txt)
echo $output_1

# don't worry about extra whitespace in the output
newOutput_1=""
while read line
do
  newOutput_1=$newOutput_1$(echo "$line" | xargs -0)
done <<< "$output_1"

expected_output_1="one"
expected_output_1=$expected_output_1"two"
expected_output_1=$expected_output_1"three"
expected_output_1=$expected_output_1"333"
expected_output_1=$expected_output_1"six"
expected_output_1=$expected_output_1":L"


# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_1" <<< "$newOutput_1"; then
  eval "$passFormat"
  echo "Test #1 - File 1 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #1 - File 1 - Unsolved - Expected '$expected_output_1' but got: $newOutput_1"
  returnStatus=1
fi

echo

./a$fileExtension > /dev/null 2>&1 <<'EOF'
EDIT output2.txt
:I
111
222
333
444
555
666
777
:L
:D 3 4
:I 3
threethreethree
:L 3
:L 4
:E
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output_2=$(cat output2.txt)

# don't worry about extra whitespace in the output
newOutput_2=""
while read line
do
  newOutput_2=$newOutput_2$(echo "$line" | xargs -0)
done <<< "$output_2"

expected_output_2="111"
expected_output_2=$expected_output_2"222"
expected_output_2=$expected_output_2"threethreethree"
expected_output_2=$expected_output_2"666"
expected_output_2=$expected_output_2"777"
expected_output_2=$expected_output_2":L"


# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output_2" <<< "$newOutput_2"; then
  eval "$passFormat"
  echo "Test #2 - File 2 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #2 - File 2 - Unsolved - Expected '$expected_output_2' but got: $newOutput_2"
  returnStatus=1
fi

#rm output.txt
#rm output2.txt

echo

eval "$normalFormat"

echo
exit $returnStatus
