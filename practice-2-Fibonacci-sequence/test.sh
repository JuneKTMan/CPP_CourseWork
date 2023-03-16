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


echo
output=$(./a$fileExtension)
expected_output1="Fibonacci sequence: 0 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output1" <<< "$output"; then
  eval "$passFormat"
  echo "Test #1 - Print Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #1 - Print Output - Expected '$expected_output1' but got: $output"
  returnStatus=1
fi

expected_output2="Time complexity of print operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output2" <<< "$output"; then
  eval "$passFormat"
  echo "Test #2 - Print Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #2 - Print Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


echo
expected_output3="Highest Fibonacci number: 6765"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output3" <<< "$output"; then
  eval "$passFormat"
  echo "Test #3 - Highest Fibonacci Number - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #3 - Highest Fibonacci Number - Expected '$expected_output3' but got: $output"
  returnStatus=1
fi

expected_output4="Time complexity of find highest operation: O(1)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output4" <<< "$output"; then
  eval "$passFormat"
  echo "Test #4 - Highest Fibonacci Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #4 - Highest Fibonacci Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


echo
expected_output5="Average of Fibonacci numbers: 843"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output5" <<< "$output"; then
  eval "$passFormat"
  echo "Test #5 - Average of Fibonacci Numbers - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #5 - Average of Fibonacci Numbers - Expected '$expected_output5' but got: $output"
  returnStatus=1
fi

expected_output6="Time complexity of find average operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test #6 - Average of Fibonacci Numbers Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #6 - Average of Fibonacci Numbers Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi

echo
if [ $returnStatus -eq 0 ] ; then
    eval "$passFormat"
    echo "All tests passed."
else
    eval "$failFormat"
    echo "One or more tests failed."
fi

eval "$normalFormat"

echo
exit $returnStatus
