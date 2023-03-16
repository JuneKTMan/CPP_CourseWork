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
expected_output1="Part 1: Linked List values: NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output1" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 1 - Part 1 Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 1 - Part 1 Output - Expected '$expected_output1' but got: $output"
  returnStatus=1
fi


expected_output2="Part 2: Linked List values: 90 80 70 60 50 40 30 20 10 NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output2" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 2 - Part 2 Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 2 - Part 2 Output - Expected '$expected_output2' but got: $output"
  returnStatus=1
fi


expected_output3="Part 3: Linked List values: 90 80 70 60 50 40 30 20 10 100 NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output3" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 3 - Part 3 Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 3 - Part 3 Output - Expected '$expected_output3' but got: $output"
  returnStatus=1
fi


expected_output4="Part 4: Linked List values: 80 70 60 50 40 30 20 10 100 NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output4" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 4 - Part 4 Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 4 - Part 4 Output - Expected '$expected_output4' but got: $output"
  returnStatus=1
fi


expected_output5="Part 5: Linked List values: 80 70 60 50 40 30 20 10 NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output5" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 5 - Part 5 Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 5 - Part 5 Output - Expected '$expected_output5' but got: $output"
  returnStatus=1
fi


echo


expected_output6="Time complexity of LinkedList print operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 6 - LinkedList Print Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 6 - LinkedList Print Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


expected_output7="Time complexity of LinkedList insertAtBeginning operation: O(1)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output7" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 7 - LinkedList insertAtBeginning Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 7 - LinkedList insertAtBeginning Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


expected_output8="Time complexity of LinkedList insertAtEnd operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output8" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 8 - LinkedList insertAtEnd Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 8 - LinkedList insertAtEnd Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


expected_output9="Time complexity of LinkedList deleteAtBeginning operation: O(1)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output9" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 9 - LinkedList deleteAtBeginning Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 9 - LinkedList deleteAtBeginning Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


expected_output10="Time complexity of LinkedList deleteAtEnd operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output10" <<< "$output"; then
  eval "$passFormat"
  echo "Test #10 - LinkedList deleteAtEnd Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #10 - LinkedList deleteAtEnd Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


eval "$normalFormat"

echo
exit $returnStatus
