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
expected_output1="Could not insert node at location 2"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output1" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 1 - Failed Insert at Index 2 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 1 - Failed Insert at Index 2 - Expected '$expected_output1' but got: $output"
  returnStatus=1
fi


expected_output2="Could not insert node at location 5"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output2" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 2 - Failed Insert at Index 5 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 2 - Failed Insert at Index 5 - Expected '$expected_output2' but got: $output"
  returnStatus=1
fi


expected_output3="Part 1: Linked List values: red yellow chartreuse blue violet NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output3" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 3 - Part 1 List Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 3 - Part 1 List Output - Expected '$expected_output3' but got: $output"
  returnStatus=1
fi


expected_output4="Could not delete node at location 9"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output4" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 4 - Failed Delete at Index 9 - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 4 - Failed Delete at Index 9 - Expected '$expected_output4' but got: $output"
  returnStatus=1
fi


expected_output5="Part 2: Linked List values: red yellow blue violet NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output5" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 5 - Part 2 List Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 5 - Part 2 List Output - Expected '$expected_output5' but got: $output"
  returnStatus=1
fi


expected_output6="Part 3: Linked List values: red orange yellow blue violet NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 6 - Part 3 List Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 6 - Part 3 List Output - Expected '$expected_output6' but got: $output"
  returnStatus=1
fi


expected_output7="Part 4: Linked List values: red orange yellow green blue violet NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output7" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 7 - Part 4 List Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 7 - Part 4 List Output - Expected '$expected_output7' but got: $output"
  returnStatus=1
fi


expected_output8="Part 5: Linked List values: red orange yellow green blue indigo violet NULL"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output8" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 8 - Part 5 List Output - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 8 - Part 5 List Output - Expected '$expected_output8' but got: $output"
  returnStatus=1
fi


echo


expected_output9="Time complexity of LinkedList print operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output9" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 9 - LinkedList Print Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 9 - LinkedList Print Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


expected_output10="Time complexity of LinkedList insertAtLocation operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output10" <<< "$output"; then
  eval "$passFormat"
  echo "Test #10 - LinkedList insertAtLocation Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #10 - LinkedList insertAtLocation Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


expected_output11="Time complexity of LinkedList deleteAtLocation operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output11" <<< "$output"; then
  eval "$passFormat"
  echo "Test #11 - LinkedList deleteAtLocation Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test #11 - LinkedList deleteAtLocation Complexity - Expected correct time complexity message but got: $output"
  returnStatus=1
fi


eval "$normalFormat"

echo
exit $returnStatus
