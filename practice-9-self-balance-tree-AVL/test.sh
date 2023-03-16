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

output=$(./a$fileExtension) # must ignore extra whitespace
newOutput=""
while read line
do
  newOutput=$newOutput$(echo "$line" | xargs)
done <<< "$output"


expected_output1="Could not insert - possible duplicate: 40"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output1" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 1 - Failed insert (40) - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 1 - Failed insert (40) - Expected '$expected_output1' but got: $newOutput"
  returnStatus=1
fi


expected_output2="Found the following value in the tree: 60Could not find the following value in the tree: 75"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output2" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 2 - Part 2 Searches - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 2 - Part 2 Searches - Expected '$expected_output2' but got: $newOutput"
  returnStatus=1
fi


echo


expected_output3="Could not insert - possible duplicate: 70"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output3" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 3 - Failed insert (70) - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 3 - Failed insert (70) - Expected '$expected_output3' but got: $newOutput"
  returnStatus=1
fi


expected_output4="Found the following value in the tree: 90Could not find the following value in the tree: 25"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output4" <<< "$newOutput"; then
  eval "$passFormat"
  echo "Test # 4 - Part 4 Searches - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 4 - Part 4 Searches - Expected '$expected_output4' but got: $newOutput"
  returnStatus=1
fi

echo


expected_output5="Time complexity of Self-Balanced Binary Search Tree print operation: O(N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output5" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 5 - Self-Balanced Print Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 5 - Self-Balanced Print Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


expected_output6="Time complexity of Self-Balanced Binary Search Tree insert operation: O(log N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output6" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 6 - Self-Balanced Insert Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 6 - Self-Balanced Insert Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


expected_output7="Time complexity of Self-Balanced Binary Search Tree search operation: O(log N)"

# Use contains so we ignore additional output or input prompts
if grep -q "$expected_output7" <<< "$output"; then
  eval "$passFormat"
  echo "Test # 7 - Self-Balanced Search Complexity - Pass: Output is correct"
else
  eval "$failFormat"
  echo "Test # 7 - Self-Balanced Search Complexity - Expected correct time complexity message but got: $newOutput"
  returnStatus=1
fi


eval "$normalFormat"

echo
exit $returnStatus
