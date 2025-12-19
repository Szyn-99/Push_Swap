#!/bin/bash
cd "$(dirname "$0")" || exit 1

cases=( "a" "111a11" "hello world" "" "0 0" "-01 -001" "111-1 2 -3" "-3 -2 -2" "\\n" "-2147483649" "-2147483650" "2147483648" "8 008 12" "10 -1 -2 -3 -4 -5 -6 90 99 10" "1 +1 -1" "3333-3333 1 4" "111a111 -4 3" "111111 -4 3 03" "2147483649" "2147483647+1" "0 1 2 3 4 5 0" "3 +3" "3+3" "42 42" "42 -42 -42 " "4222-4222" "99999999999999999999999999" "-99999999999999999999999999" "0 -0 1 -1" "0 +0 1 -1" "111+111 -4 3" "-" "+" "--123 1 321" "++123 1 321" "0000000000000000000000009 000000000000000000000009" "00000001 1 9 3" "00000003 003 9 1" "--21345" "1 01" "-000 -0000" "-00042 -000042" "42 a 41" "42 41 40 45 101 x 202 -1 224 3" "42 -2 10 11 0 90 45 500 -200 e" )

i=1
printf "Running control-error checks (1..%d)\\n\\n" "${#cases[@]}"
for arg in "${cases[@]}"; do
  rm -f test_check.txt
  if [ "$arg" = "" ]; then
    ./push_swap "" > /dev/null 2> test_check.txt || true
  elif [ "$arg" = "\\n" ]; then
    ./push_swap $'\\n' > /dev/null 2> test_check.txt || true
  else
    # eval preserves the spaces in multi-word test args
    eval ./push_swap $arg > /dev/null 2> test_check.txt || true
  fi

  if [ -s test_check.txt ]; then
    line=$(sed -n '/./{p;q;}' test_check.txt || true)
    if [ "$line" = "Error" ]; then
      printf "%02d: OK    -- arg=%s\\n" "$i" "$arg"
    else
      printf "%02d: FAIL  -- arg=%s (stderr not exactly 'Error'; first stderr line: '%s')\\n" "$i" "$arg" "$line"
    fi
  else
    printf "%02d: FAIL  -- arg=%s (no stderr output)\\n" "$i" "$arg"
  fi
  i=$((i+1))
done
