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


expected_output1="Part 1: Enqueues - Queue values:1020304050"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output1" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 1 - Part 1 Enqueues - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 1 - Part 1 Enqueues - Expected '$expected_output1' but got: $newOutput"
  returnStatus=1
fi


expected_output2="Part 2: Dequeues - Queue values:304050"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output2" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 2 - Part 2 Dequeues - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 2 - Part 2 Dequeues - Expected '$expected_output2' but got: $newOutput"
  returnStatus=1
fi


expected_output3="Part 3: Enqueues - Queue values:30405060"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output3" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 3 - Part 3 Enqueues - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 3 - Part 3 Enqueues - Expected '$expected_output3' but got: $newOutput"
  returnStatus=1
fi


expected_output4="Could not remove node - queue empty"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output4" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 4 - Part 4 Failed Dequeue - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 4 - Part 4 Failed Dequeue - Expected '$expected_output4' but got: $newOutput"
  returnStatus=1
fi


echo


expected_output5="Time complexity of Queue print operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output5" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 5 - Queue Print Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 5 - Queue Print Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


expected_output6="Time complexity of Queue enqueue operation: O(1)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 6 - Queue Enqueue Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 6 - Queue Enqueue Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


expected_output7="TTime complexity of Queue Dequeue operation: O(1)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 7 - Queue Dequeue Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 7 - Queue Dequeue Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


eval "$normalFormat"

echo
exit $returnStatus
