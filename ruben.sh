#!/bin/bash

# Parse command line arguments
if [ $# -lt 3 ]; then
    echo "Usage: $0 <min> <max> <count> [<flags>] [<type>]"
    echo "Flags: 1 = add non-valid char, 2 = add number outside range, 3 = add duplicate"
	echo "Type: 1 = args as one string, 2 = args as string & individual"
    exit 1
fi

min=$1
max=$2
count=$3
flag=${4:-0}
typ=${5:-0}
INT_MIN=-2147483648
INT_MAX=2147483647

GREEN="\033[32m"
YELLOW="\033[33m"
RED="\033[31m"
RESET="\033[0m"

# Check range
if [ "$min" -gt "$max" ]; then
    echo "Error: min is greater than max"
    exit 1
fi

# Generate random numbers
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
	output_desired="Error"
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
	output_desired="Error"
fi

# Add duplicate number
if [ "$flag" -eq 3 ]; then
    index1=$((RANDOM % count))
    index2=$((RANDOM % count))
    numbers[$index1]=${numbers[$index2]}
	output_desired="Error"
fi

# Adjust input (multiple arguments, string or mixed)
if [ "$typ" -eq 2 ]; then 
	group1=($(echo "${numbers[@]}" | cut -d' ' -f -$((count/2))))
	group2=($(echo "${numbers[@]}" | cut -d' ' -f $(((count/2)+1))-))
	output_desired="Error"
	#Uncomment the following line to output used arguments:
	#echo -e ${YELLOW}"./push_swap ${group1[@]} \"${group2[*]}\""${RESET}
	echo $(valgrind --log-file=testfile ./push_swap "${group1[@]}" "${group2[*]}" > /dev/null)
	output_new=$(./push_swap "${group1[@]}" "${group2[*]}" | ./checker "${group1[@]}" "${group2[*]}" 2>&1)
elif [ "$typ" -eq 1 ]; then 
	#Uncomment the following line to output used arguments:
	#echo -e ${YELLOW}"./push_swap \"${numbers[*]}\""${RESET}
	echo $(valgrind --log-file=testfile ./push_swap "${numbers[*]}" > /dev/null)
	output_new=$(./push_swap "${numbers[*]}" | ./checker "${numbers[*]}" 2>&1)
else 
	#Uncomment the following line to output used arguments:
	#echo -e ${YELLOW}"./push_swap ${numbers[@]}"${RESET}
	echo $(valgrind --log-file=testfile ./push_swap "${numbers[@]}" > /dev/null)
	output_new=$(./push_swap "${numbers[@]}" | ./checker "${numbers[@]}" 2>&1)
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
#cat testfile | grep --color -A2 "in use at exit"
