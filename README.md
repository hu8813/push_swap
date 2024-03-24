# Push_swap using Radix sort

Push_swap is a project that involves sorting a list of integers using a limited set of operations. The goal is to sort the list with the fewest possible number of operations.

# overflow handling

Do not forget to check for error handling & leaks if a number is bigger/smaller than max/min long int or long long int (overflow) ! 

For testing error handling and finding memory leaks, use my tester here:

Link to the tester's repository: (https://github.com/hu8813/tester_push_swap)


## Sorting results and points


<table>
  <tr>
    <th>Input Size</th>
    <th>Average Operations</th>
    <th>Maximum Operations allowed</th>
    <th>Points</th>
     <th>Visualize</th>
  </tr>
  <tr>
    <td>3</td>
    <td>1-2</td>
    <td>3</td>
    <td></td>
    <td></td>
  </tr>
    <tr>
    <td>5</td>
    <td>5-10</td>
    <td>12</td>
    <td></td>
    <td></td>
  </tr>
  <tr>
    <td>100</td>
    <td>855-857</td>
    <td><1300</td>
    <td>4/5</td>
    <td><a target="_blank" href="https://patrick-hacks.github.io/push-swap-pain/?&nbr=14,69,67,30,74,25,13,72,44,47,94,78,81,77,19,50,1,46,23,34,73,54,42,10,5,84,21,64,18,75,53,36,66,86,79,91,4,2,51,31,57,55,11,85,40,28,88,63,12,39,56,76,65,97,70,29,35,83,27,87,8,62,68,24,26,17,92,22,38,16,60,52,3,99,41,71,43,61,49,82,98,7,80,37,6,100,58,9,59,15,45,90,89,20,93,33,96,48,32,95&cmd=dkkddkkddkddkkkdkdkdkdddkdkddkkdddkkddkkkkkkdddkdkddkkdkkkkkdddddkddddddkkkkkkkddkdkdddkkkkdkdkkdddkjeeeejjeejeejjejjejjjjeeejjejjejjjjejeeejejeejeejedddddddddddddddddddddddddkkkddkkkkkkkkddkdkkdkddddddkdkddkdkkdddkkdkdkkddddeejeejjejjejeeeejejejjejjejejejejeejeejejjjeejejejddddddddddddddddddddddddkdkdkdkkddkddkkkdkkdkdkdddkkdkkdkdkdkdkdkdkkdkkdddeeejjejjjeeejjjeejeejejjeejjeejeeejjeejejjejeeejjeejddddddddddddddddddddddddkddkkkkddkdddddddkkkdkkkdkddkdkkkkddkdkkkkkdddddjejjeeeejejjeejejjejjjeejejeeejeejejjeejeejejejjeeejdddddddddddddddddddddddddkdkkdkkkdddkdkdkdkdkkddkkddkdkddkkdkkddkddkkdkdjeeeejjeejeeeejjeeejeejeejeeejejejeejeejjejejeejjjeeddddddddddddddddddddkkddkkkdkkdkkdkdkkkdkkdkkdkkdkkkdkkdkdkkkdkdkdkkejjejejejeejjejeejjeejjeejjejeejjeejjejejeejejejejejejejjeejejjedddddddddddddddddddddddddddddddddkkdkdkdjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj">link</a></td>
  </tr>
  <tr>
    <td>500</td>
    <td>5739-5741</td>
    <td><10000</td>
    <td>4/5</td>
    <td></td>
  </tr>
</table>

## Usage

To use the push_swap program, compile it with the `make` command and then run it with the list of integers to be sorted as arguments. i.e.:

`./push_swap 3 1 2` 

To test with some random numbers:

`make test`  (will test with 10 numbers as default)

to test with n random numbers:

`make test size=n`  i.e. `make test size=5` 

This will output if the program passes the test, amount of operations necessary to sort, if there are any memory leaks.

Optionally, you can use the `checker` program to verify that the list is correctly sorted after the operations are applied. To do this, run the `checker` program with the list of integers and the list of operations as arguments. 

## Test and see how many points you can get

run: perl push_swap_tester.pl size_of_stack how_many_tests  

i.e. `perl push_swap_tester.pl 100 10` 

will run 10 different tests with 100 different numbers each time and show you how many points you can get during evaluation

Link to the repository: (https://github.com/lorenuars19/push_swap_tester) 

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
    
    -   A tutorial on using insertion sort in small chunks for push_swap: [https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
    -   A video explanation of using insertion sort in small chunks: [https://youtu.be/ZHVk2blR45Q](https://youtu.be/ZHVk2blR45Q)
