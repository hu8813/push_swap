
# Push_swap using Radix sort

Push_swap is a project that involves sorting a list of integers using a limited set of operations. The goal is to sort the list with the fewest possible number of operations.

## Sorting results and points


<table>
  <tr>
    <th>Input Size</th>
    <th>Minimum Operations</th>
    <th>Maximum Operations</th>
    <th>Points</th>
  </tr>
  <tr>
    <td>3</td>
    <td>1</td>
    <td>2</td>
    <td></td>
  </tr>
    <tr>
    <td>5</td>
    <td>5</td>
    <td>10</td>
    <td></td>
  </tr>
  <tr>
    <td>100</td>
    <td>855</td>
    <td>857</td>
    <td>4/5</td>
  </tr>
  <tr>
    <td>500</td>
    <td>5739</td>
    <td>5741</td>
    <td>4/5</td>
  </tr>
</table>

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

Run `bash visualizer.sh` to get an online link that shows the visualization.

Edit the NBR_COUNT variable in visualizer.sh file to change the numbers to sort, i.e. NBR_COUNT=100 to sort 100 numbers and visualize it

GitHub Page of this Visualizer: [https://github.com/Bluegales/push-swap-pain](https://github.com/Bluegales/push-swap-pain)

OR

There is another, a better visualizer in python, but this needs tkinter library, which can not be installed on school pc as it needs root.

If you want to test on private pc, you can install the push-swap-gui python program from [https://pypi.org/project/push-swap-gui/](https://pypi.org/project/push-swap-gui/). This program allows you to see the sorting process of the Push_swap project in a graphical interface, making it easier to understand how the algorithms work. Simply follow the instructions on the website to install and run the program. If you get tkinter error, means you need to install tkinter via `sudo apt install python3-tk`

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
