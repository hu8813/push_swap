
# Push_swap

Push_swap is a project that involves sorting a list of integers using a limited set of operations. The goal is to sort the list with the fewest possible number of operations.

## Usage

To use the push_swap program, compile it with the `make` command and then run it with the list of integers to be sorted as arguments. For example:

`./push_swap 3 1 2` 

If you get any error, try to run it in bash instead zsh

to test with some random numbers:

`make test` 

to test with n random numbers:

`make test size=n`  i.e. `make test size=5` 

This will output if the program passes the test, amount of operations necessary to sort, if there are any memory leaks.

Optionally, you can use the `checker` program to verify that the list is correctly sorted after the operations are applied. To do this, run the `checker` program with the list of integers and the list of operations as arguments. 

## Visualize the results

Run `bash visualizer.sh` to get a link that shows the visualization
edit the file to change the numbers to sort, i.e. NBR_COUNT=100 to sort 100 numbers and visualize it

## Resources

Useful resources for understanding and implementing sorting algorithms for the Push_swap project:

-   Radix sort:
    
    -   A tutorial on using radix sort with push_swap: [https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)
    -   A video explanation of radix sort: [https://youtu.be/XiuSW_mEn7g](https://youtu.be/XiuSW_mEn7g)
-   LIS sort (Longest Increasing Subsequence sort):
    
    -   Wikipedia page on longest increasing subsequence: [https://en.wikipedia.org/wiki/Longest_increasing_subsequence](https://en.wikipedia.org/wiki/Longest_increasing_subsequence)
    -   A PDF on using LIS sort for push_swap: [https://v0tdou.csb.app/lis_sort.pdf](https://v0tdou.csb.app/lis_sort.pdf)
-   Insertion sort in small chunks:
    
    -   A tutorial on using insertion sort in small chunks for push_swap: [https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
    -   A video explanation of using insertion sort in small chunks: [https://youtu.be/ZHVk2blR45Q](https://youtu.be/ZHVk2blR45Q)
