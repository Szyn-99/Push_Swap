#!/bin/bash

CHECKER=./checker

echo "=============================="
echo " PUSH_SWAP CHECKER TEST SUITE "
echo "=============================="
echo

run_test () {
	echo "Test: $1"
	echo "Command:"
	echo "$2"
	echo "Expected: $3"
	echo -n "Result:   "
	eval "$2"
	echo
	echo "------------------------------"
}

# ------------------------------
# BASIC SORTED / UNSORTED
# ------------------------------

run_test \
"Already sorted (no ops)" \
"printf \"\" | $CHECKER 1 2 3 4" \
"OK"

run_test \
"Not sorted (no ops)" \
"printf \"\" | $CHECKER 2 1" \
"KO"

# ------------------------------
# SIMPLE OPERATIONS
# ------------------------------

run_test \
"sa sorts two numbers" \
"printf \"sa\n\" | $CHECKER 2 1" \
"OK"

run_test \
"ra sorts two numbers" \
"printf \"ra\n\" | $CHECKER 2 1" \
"OK"

run_test \
"rra sorts two numbers" \
"printf \"rra\n\" | $CHECKER 2 1" \
"OK"

run_test \
"Wrong operation order" \
"printf \"ra\n\" | $CHECKER 1 2" \
"KO"

# ------------------------------
# MULTIPLE OPERATIONS
# ------------------------------

run_test \
"Valid sequence" \
"printf \"pb\nsa\npa\n\" | $CHECKER 2 1" \
"OK"

run_test \
"Leaves stack B non-empty" \
"printf \"pb\n\" | $CHECKER 1 2" \
"KO"

# ------------------------------
# THREE NUMBERS
# ------------------------------

run_test \
"Sort 3 numbers" \
"printf \"sa\nra\n\" | $CHECKER 2 3 1" \
"OK"

run_test \
"Unsorted result" \
"printf \"sa\n\" | $CHECKER 3 1 2" \
"KO"

# ------------------------------
# INVALID INSTRUCTIONS
# ------------------------------

run_test \
"Invalid instruction" \
"printf \"invalid\n\" | $CHECKER 1 2" \
"Error"

run_test \
"Partial invalid instruction" \
"printf \"saa\n\" | $CHECKER 1 2" \
"Error"

# ------------------------------
# DUPLICATES
# ------------------------------

run_test \
"Duplicate numbers" \
"printf \"\" | $CHECKER 1 2 2" \
"Error"

# ------------------------------
# ARGUMENT ERRORS
# ------------------------------

run_test \
"Non-numeric argument" \
"printf \"\" | $CHECKER 1 a 2" \
"Error"

run_test \
"INT overflow" \
"printf \"\" | $CHECKER 2147483648" \
"Error"

run_test \
"INT underflow" \
"printf \"\" | $CHECKER -2147483649" \
"Error"

# ------------------------------
# EDGE CASES
# ------------------------------

run_test \
"Single number" \
"printf \"\" | $CHECKER 42" \
"OK"

run_test \
"No arguments" \
"$CHECKER" \
"(no output)"

echo
echo "======== END OF TESTS ========"

