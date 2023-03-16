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

./a$fileExtension > /dev/null 2>&1

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi

output=$(./a$fileExtension) # must ignore extra whitespace
newOutput=""
while read line
do
  newOutput=$newOutput$(echo "$line" | xargs)
done <<< "$output"


expected_output1="Part 1: Pushes - Stack values:5040302010"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output1" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 1 - Part 1 Pushes - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 1 - Part 1 Pushes - Expected '$expected_output1' but got: $newOutput"
  returnStatus=1
fi


expected_output2="Part 2: Pops - Stack values:302010"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output2" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 2 - Part 2 Pops - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 2 - Part 1 Pops - Expected '$expected_output2' but got: $newOutput"
  returnStatus=1
fi


expected_output3="Part 3: Pushes - Stack values:60302010"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output3" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 3 - Part 3 Pushes - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 3 - Part 3 Pushes - Expected '$expected_output3' but got: $newOutput"
  returnStatus=1
fi


expected_output4="Could not remove node - stack empty"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output4" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 4 - Part 4 Failed Pop - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 4 - Part 4 Failed Pop - Expected '$expected_output4' but got: $newOutput"
  returnStatus=1
fi


echo


expected_output5="Time complexity of Stack print operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output5" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 5 - Stack Print Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 5 - Stack Print Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


expected_output6="Time complexity of Stack push operation: O(1)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 6 - Stack Push Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 6 - Stack Push Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


expected_output7="TTime complexity of Stack pop operation: O(1)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 7 - Stack Pop Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 7 - Stack Pop Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


eval "$normalFormat"

echo
exit $returnStatus
