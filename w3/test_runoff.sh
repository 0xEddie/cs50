#!/bin/bash

# `echo -e` is used to simulate voter inputs with newline-separated values matching the program's expected prompt structure
# make test script executable `chmod +x test_runoff.sh` 
# then run it after compiling program

# Compile the program
make vote_sim

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Test cases
echo "Running test cases..."

# Test case 1: three voters, clear winner
echo "Test 1: Three voters, clear winner"
echo -e "3\nAlice\nBob\nCharlie\nAlice\nBob\nCharlie\nBob\nAlice\nCharlie\n" | ./runoff Alice Bob Charlie
echo "Expected: Alice"
echo

# Test case 2: three voters, tie
echo "Test 2: Three voters, tie"
echo -e "3\nAlice\nBob\nCharlie\nBob\nAlice\nCharlie\nCharlie\nAlice\nBob\n" | ./runoff Alice Bob Charlie
echo "Expected: Tie between Alice, Bob, and Charlie"
echo

# Test case 3: more candidates, runoff elimination
echo "Test 3: Runoff elimination"
echo -e "4\nAlice\nBob\nCharlie\nAlice\nCharlie\nBob\nCharlie\nAlice\nBob\nBob\nCharlie\nAlice\n" | ./runoff Alice Bob Charlie
echo "Expected: Charlie"
echo

# Test case 4: edge case with one voter
echo "Test 4: One voter"
echo -e "1\nAlice\nBob\nCharlie\n" | ./runoff Alice Bob Charlie
#!/bin/bash

# `echo -e` is used to simulate voter inputs with newline-separated values matching the program's expected prompt structure
# make test script executable `chmod +x test_runoff.sh` 
# then run it after compiling program

# Compile the program
make vote_sim

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Test cases
echo "Running test cases..."

# Test case 1: three voters, clear winner
echo "Test 1: Three voters, clear winner"
echo -e "3\nAlice\nBob\nCharlie\nAlice\nBob\nCharlie\nBob\nAlice\nCharlie\n" | ./runoff Alice Bob Charlie
echo "Expected: Alice"
echo

# Test case 2: three voters, tie
echo "Test 2: Three voters, tie"
echo -e "3\nAlice\nBob\nCharlie\nBob\nAlice\nCharlie\nCharlie\nAlice\nBob\n" | ./runoff Alice Bob Charlie
echo "Expected: Tie between Alice, Bob, and Charlie"
echo

# Test case 3: more candidates, runoff elimination
echo "Test 3: Runoff elimination"
echo -e "4\nAlice\nBob\nCharlie\nAlice\nCharlie\nBob\nCharlie\nAlice\nBob\nBob\nCharlie\nAlice\n" | ./runoff Alice Bob Charlie
echo "Expected: Charlie"
echo

# Test case 4: edge case with one voter
echo "Test 4: One voter"
echo -e "1\nAlice\nBob\nCharlie\n" | ./runoff Alice Bob Charlie
echo "Expected: Alice"
echo

# Test case 5: maximum number of voters and candidates
echo "Test 5: Maximum voters and candidates"
input="100"
for i in $(seq 1 100); do
    input+="\nAlice\nBob\nCharlie\n"
done
echo -e "$input" | ./runoff Alice Bob Charlie
echo "Expected: Alice"
echo

echo "Expected: Alice"
echo

# Test case 5: maximum number of voters and candidates
echo "Test 5: Maximum voters and candidates"
input="100"
for i in $(seq 1 100); do
    input+="\nAlice\nBob\nCharlie\n"
done
echo -e "$input" | ./runoff Alice Bob Charlie
echo "Expected: Alice"
echo

