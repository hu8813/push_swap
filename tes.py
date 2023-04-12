#!/usr/bin/env python3
import subprocess
import re

color = "\033[1;31m"
green = "\033[1;32m"
red = "\033[1;31m"
reset = "\033[0;0m"


def testcase(nbrs):
    result = subprocess.run(["valgrind", "--leak-check=full", "./push_swap", nbrs], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    print("Numbers:", nbrs)
    output = result.stderr.decode()
    print(output)
    memory_usage = re.search(r"in use at exit: (\d+) bytes in", output)
    if memory_usage:
        num_inuse = int(memory_usage.group(1))
    exists_error = re.search(r"Error\n", output)
    if exists_error:
        print(f"{green}OK{reset}", end=" ")
    if num_inuse:
        print(f"{red}MKO{reset} {num_inuse} bytes still reachable!", end="")
    print()
    
testcase("4 4 6")
testcase("6 4 4")
testcase("4 6 4")
testcase("6 3 4")
testcase("4 6 3")
testcase("4 6 3u")
testcase("4 6- 3")
testcase("2147483647 -2147483648")
testcase("0 1 2 3 4 5 6 7 8 9")
testcase("9 8 7 6 5 4 3 2 1 0")
testcase("5 3 1 2 4 6")
testcase("10000000000 20000000000 30000000000")
testcase("2 2 2 2 2 2 2")
testcase("10 9 8 7 6 5 4 3 2 1 0")

