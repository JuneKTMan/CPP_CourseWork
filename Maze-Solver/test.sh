#Needs to have the following two input files in test-files folder root:
#   test_maze1.txt
#   test_maze2.txt

#Needs to have the following two sample solution files in test-files folder root:
#   solution_maze1.txt
#   solution_maze2.txt

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
./test-files/test_maze1.txt
./test-files/solved_test_maze1.txt
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi


output=$(cat ./test-files/solved_test_maze1.txt)

newOutput=""
while read line
do
  newOutput=$newOutput$(echo "$line" | xargs)
done <<< "$output"

# Need to read in solution file line by line and check it
testOneStatus=0
badLine=""
while read line
do
  newLine=$(echo $line | xargs)
  if grep -q "$newLine" <<< "$newOutput"; then
    continue
  else
    testOneStatus=1
    badLine="$line"
    break
  fi
done < ./test-files/solution_maze1.txt

if [ $testOneStatus -eq 0 ] ; then
  eval "$passFormat"
  echo "Test #1 - Maze #1 - Pass: Normal Output is correct"
else
  eval "$failFormat"
  echo "Test #1 - Maze #1 - - Fail: Normal Output Missing Expected line: `echo $badLine`"
  returnStatus=1
fi

echo


./a$fileExtension > /dev/null 2>&1 <<'EOF'
./test-files/test_maze2.txt
./test-files/solved_test_maze2.txt
EOF

if [ $? -eq 0 ] ; then
  eval "$passFormat"
  echo "Pass: Program exited zero"
else
  eval "$failFormat"
  echo "Fail: Program did not exit zero"
  returnStatus=1
fi


output2=$(cat ./test-files/solved_test_maze2.txt)

newOutput2=""
while read line
do
  newOutput2=$newOutput2$(echo "$line" | xargs)
done <<< "$output2"

# Need to read in solution file line by line and check it
testTwoStatus=0
badLine=""
while read line
do
  newLine=$(echo $line | xargs)
  if grep -q "$newLine" <<< "$newOutput2"; then
    continue
  else
    testTwoStatus=1
    badLine="$line"
    break
  fi
done < ./test-files/solution_maze2.txt

if [ $testTwoStatus -eq 0 ] ; then
  eval "$passFormat"
  echo "Test #2 - Maze #2 - Pass: Normal Output is correct"
else
  eval "$failFormat"
  echo "Test #2 - Maze #2 - - Fail: Normal Output Missing Expected line: `echo $badLine`"
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
