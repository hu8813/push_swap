#!/bin/bash

# **************************************************************************** #
# Set variables
GREEN="\033[32m"
YELLOW="\033[33m"
RED="\033[31m"
RESET="\033[0m"
usage=${YELLOW}"Push_swap_tester\nUsage:"${RESET}"
      ./tester <min_value> <max_value> <numbers_to_generate>
      *optional arguments
"
# Set checker
if [ "$(uname -s)" = "Linux" ]; then
    checker="./checker_linux"
else
    checker="./checker_Mac"
fi

# Check if push_swap exists
if ! [ -e ./push_swap ]; then
  echo "Error: ./push_swap file not found"
  echo -e $usage   
  exit 1
fi

# Check if checker exists
if ! [ -e ${checker} ]; then
  echo "Error: ${checker} file not found"
  echo -e $usage   
  exit 1
fi

# Check argument range
if [ "$min" -gt "$max" ]; then
  echo "Error: min is greater than max"
  exit 1
fi

min=$((10#${1:-1}))
max=$((10#${2:-1000}))
count=$((10#${3:-10}))
INT_MIN=-2147483648
INT_MAX=2147483647

echo "Min: $min" "Max: $max" "Count: $count"

function run_test() {
    # Generate random numbers
    flag=$((10#${1:-0}))
    typ=$((10#${2:-0}))
    numbers=()
    output_desired=()
    for ((i=0; i<count; i++)); do
        num=$((RANDOM % (max - min + 1) + min))
        while [[ "${numbers[@]}" =~ "$num" ]]; do
            num=$((RANDOM % (max - min + 1) + min))
        done
        numbers+=("$num")
    done

    # Add non-valid character
    if [ "$flag" -eq 1 ]; then
        index=$((RANDOM % count))
        numbers[$index]='u'
        output_desired="$(echo sa | ${checker} $numbers[*] 2>&1)"

    fi

    # Add number outside range
    if [ "$flag" -eq 2 ]; then
        index=$((RANDOM % count))
        num=$((RANDOM % 2))
        if [ $num -eq 0 ]; then
            num=$((INT_MAX + 1 + RANDOM))
        else
            num=$((INT_MIN - 1 - RANDOM))
        fi
        numbers[$index]=$num
        output_desired="$(echo sa | ${checker} $numbers[*] 2>&1)"

    fi

    # Add duplicate number
    if [ "$flag" -eq 3 ]; then
        index1=$((RANDOM % count))
        index2=$((RANDOM % count))
        numbers[$index1]=${numbers[$index2]}
        output_desired="$(echo sa | ${checker} $numbers[*] 2>&1)"

    fi

    # Adjust input (multiple arguments, string or mixed)
    if [ "$typ" -eq 2 ]; then 
        group1=($(echo "${numbers[@]}" | cut -d' ' -f -$((count/2))))
        group2=($(echo "${numbers[@]}" | cut -d' ' -f $(((count/2)+1))-))
        #output_desired="$(echo sa | ${checker} $group1[@] $group2[*] 2>&1)"

        #Uncomment the following line to output used arguments:
        echo -e ${YELLOW}"./push_swap ${group1[@]} \"${group2[*]}\""${RESET}
        echo $(valgrind --log-file=testfile ./push_swap "${group1[@]}" "${group2[*]}" > /dev/null)
        output_new=$(./push_swap "${group1[@]}" "${group2[*]}" | ${checker} "${group1[@]}" "${group2[*]}" 2>&1)
    elif [ "$typ" -eq 1 ]; then 
        #Uncomment the following line to output used arguments:
        echo -e ${YELLOW}"./push_swap \"${numbers[*]}\""${RESET}
        echo $(valgrind --log-file=testfile ./push_swap "${numbers[*]}" > /dev/null)
        output_new=$(./push_swap "${numbers[*]}" | ${checker} "${numbers[*]}" 2>&1)
    else 
        #Uncomment the following line to output used arguments:
        echo -e ${YELLOW}"./push_swap ${numbers[@]}"${RESET}
        echo $(valgrind --log-file=testfile ./push_swap "${numbers[@]}" > /dev/null)
        output_new=$(./push_swap "${numbers[@]}" | ${checker} "${numbers[@]}" 2>&1)
    fi

    #Uncomment the following line to show checker result:
    #echo ${output_new}

    # Print Checks
    if [ "$output_new" = "$output_desired" -o "$output_new" = "OK" ]; then
        echo -e "Output:\t\t"${GREEN}"OK"${RESET}
    else
        echo -e "Output:\t\t"${RED}"KO"${RESET}
    fi
    echo -e "Valgrind:\t"$(awk '/in use at exit: 0 bytes/{f=1; printf "'"${GREEN}"'OK'"${RESET}"'\n"; exit} /in use at exit:/{f=1; printf "'"${RED}"'KO'"${RESET}"'\n"; exit} END{if(!f) printf "'"${RED}"'KO'"${RESET}"'\n"}' testfile)
    #Uncomment the following line to see valgrind results:
    if ! grep -q "in use at exit: 0" testfile; then
        cat testfile | grep --color -A2 "in use at exit"
    fi
}

run_test 0 0
run_test 0 1
run_test 0 2
run_test 1 0
run_test 1 1
run_test 1 2
run_test 2 0
run_test 2 1
run_test 2 2
run_test 3 0
run_test 3 1
run_test 3 2
