
# Push_swap using Radix sort

Push_swap is a project that involves sorting a list of integers using a limited set of operations. The goal is to sort the list with the fewest possible number of operations.

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
    <td><a target="_blank" href="https://bluegales.github.io/push-swap-pain/?&nbr=14,69,67,30,74,25,13,72,44,47,94,78,81,77,19,50,1,46,23,34,73,54,42,10,5,84,21,64,18,75,53,36,66,86,79,91,4,2,51,31,57,55,11,85,40,28,88,63,12,39,56,76,65,97,70,29,35,83,27,87,8,62,68,24,26,17,92,22,38,16,60,52,3,99,41,71,43,61,49,82,98,7,80,37,6,100,58,9,59,15,45,90,89,20,93,33,96,48,32,95&cmd=dkkddkkddkddkkkdkdkdkdddkdkddkkdddkkddkkkkkkdddkdkddkkdkkkkkdddddkddddddkkkkkkkddkdkdddkkkkdkdkkdddkjeeeejjeejeejjejjejjjjeeejjejjejjjjejeeejejeejeejedddddddddddddddddddddddddkkkddkkkkkkkkddkdkkdkddddddkdkddkdkkdddkkdkdkkddddeejeejjejjejeeeejejejjejjejejejejeejeejejjjeejejejddddddddddddddddddddddddkdkdkdkkddkddkkkdkkdkdkdddkkdkkdkdkdkdkdkdkkdkkdddeeejjejjjeeejjjeejeejejjeejjeejeeejjeejejjejeeejjeejddddddddddddddddddddddddkddkkkkddkdddddddkkkdkkkdkddkdkkkkddkdkkkkkdddddjejjeeeejejjeejejjejjjeejejeeejeejejjeejeejejejjeeejdddddddddddddddddddddddddkdkkdkkkdddkdkdkdkdkkddkkddkdkddkkdkkddkddkkdkdjeeeejjeejeeeejjeeejeejeejeeejejejeejeejjejejeejjjeeddddddddddddddddddddkkddkkkdkkdkkdkdkkkdkkdkkdkkdkkkdkkdkdkkkdkdkdkkejjejejejeejjejeejjeejjeejjejeejjeejjejejeejejejejejejejjeejejjedddddddddddddddddddddddddddddddddkkdkdkdjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj">link</a></td>
  </tr>
  <tr>
    <td>500</td>
    <td>5739-5741</td>
    <td><10000</td>
    <td>4/5</td>
    <td><a target="_blank" href="https://bluegales.github.io/push-swap-pain/?&nbr=48,89,19,237,235,13,383,305,194,423,430,325,229,499,171,21,404,265,133,178,38,66,167,65,254,441,230,337,181,64,427,335,491,90,239,35,432,131,333,4,264,388,177,323,424,444,346,243,309,148,270,359,407,290,369,83,414,339,485,207,199,214,395,366,179,45,500,159,259,6,277,233,357,271,216,203,460,412,126,74,104,169,375,86,477,37,208,341,228,377,220,494,292,60,401,173,219,81,157,144,222,174,486,365,417,298,25,353,304,231,61,122,14,102,141,462,209,224,308,343,187,232,468,22,17,348,53,315,67,472,351,195,490,234,331,150,382,182,372,34,284,258,260,483,319,334,310,356,403,5,75,82,318,449,469,492,113,289,138,433,336,196,317,410,189,23,57,316,394,236,30,9,442,201,250,172,448,52,471,70,475,106,97,135,215,321,438,18,293,421,294,354,241,240,200,151,166,263,376,134,99,291,434,447,286,379,186,274,20,29,3,338,295,116,110,328,252,400,31,385,364,26,204,463,330,458,55,245,11,54,68,218,352,72,164,392,49,496,398,373,355,130,437,121,212,456,33,197,459,399,306,389,32,88,311,396,206,257,461,101,15,435,217,273,191,327,77,154,378,326,454,440,479,287,205,464,168,176,8,387,2,146,24,62,7,428,495,344,422,411,249,211,158,267,56,137,16,79,188,416,480,80,409,307,446,349,36,408,345,147,50,221,465,368,10,119,185,210,436,242,367,370,73,426,457,431,251,192,76,332,386,425,455,153,329,12,361,253,402,58,193,43,184,213,391,107,467,415,128,453,109,390,105,497,261,272,47,269,393,120,190,451,123,470,117,87,227,360,443,149,324,476,406,165,71,363,136,371,262,125,39,118,280,248,127,163,108,198,340,487,255,299,180,92,161,275,314,96,489,313,256,114,244,450,28,312,202,46,142,279,175,85,170,380,439,69,93,100,139,347,112,300,283,322,285,129,183,111,482,124,473,278,281,266,419,103,320,156,115,429,98,342,296,405,78,268,413,362,303,466,1,301,238,420,44,282,40,474,493,350,143,246,51,162,498,384,478,41,95,226,63,381,27,418,155,288,484,297,445,160,452,276,374,247,91,397,42,302,59,152,488,145,84,94,223,132,140,481,358,225&cmd=dkkkkkkkdkdkkkkkdkkdddkkdkdkkdkkkdkkdkkdddkkdddkkddkkdkkdkkkkdkdkkdkkdkkkkdkdddddkkdkkdkdkddddkkkkkddddkkdkkdkkdddkdkddkkdddkdkkkdkkddkddddddddkkdddkkkddkkdkkdkddkdkkkddddkdkddddkdkdkkkkddkkddkddkdkddkkdkdkdddkkdkdddddkkdddkddkkkdddddddkddkkdkkddkkkkdkddkddkkkkkkkkkkdddddkkkddddkddddkdkddkkkdkdkdkddddkkdkddkkdkkddkkdddkdkdkkkddddkkkkdkkddkkdkkkkkdkkdkkkdkkkddkkdkkkdkkdddkkkdkdkkdddkkdddkkkddkkddkkdddddddddkkkddkkkdkkddkdkkkkddkdkdkkddkkdddkddkdkdkkddddddkdkdkddddkkdkkkdkddkkddddkkkddkddkddkddkdkeejejejjeejjejjejjeeejeeejjjeejjeejjjeejejjeejejjjjjjejjjeejjjejjeejeeeeejjjjejeeeeejejjeejejeejeejejejjejjjjejjejjeejjeeejejjeeeejeejejjejjjejjjjjjeeeejjejjeeejeeeeeeejejjjjjjjjeejjeeejeeeeeejeeeeeejejjeeejjejjjjejjejjejjeejjjjjjeeeejeeejjeejejejejeddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkkdkkkkkdkddddddkdkkkkkdkdddkkdkdddkdddkkkkdkkkkddddkddkkkkkdkdkdkkdkkdkddkdkdkkkdddkkkkkkddkdkkkkkdkdkddddkdkkkdkdddddkkddkdddkkkkkdddddkkdkddkkddddddkddkdkkdkkkdddkdkkddkddkkdddkdkkdddkdddkddkdkddkkkkddddkkdkkddkkdkdkkkddkdkkkkkdkkkdddddkkkdddkddkjjjejeejeejjeejeejjeejeeejjeeeejjjjjjjeeeeeeeeejjjjeejjeejeejejeeejeeejejjejejejeejeeejejjeejjjeejjjjeejjjjjejjjjjejeejjejejeeeejjejejjejjjeeejjjjeeejjjjejjeejjjejeeeeeeeejejeeejjeejjejjeejjejejejjeeeeejjeeejejjeejjeeejjejeejjjejejjjejejjeeejejjjejjeddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkkddkkdkdkdkkkkddkkddkkdkdkdkddkkkdkkkdkkddkddddkkdkkddddkkkdddkddddkddkkkdkkdddkdkdkkddkkdkkdkkddkddkkdddkkkddkdkddkddkkdkkddkddkdkdkkkdkkddkkkkdddkdkkdkkkkkdkkkkdkdddkkdkdkkkddkddkdddkddddddkdddkdddkddkdkkkdddddkkdddkkkkddkkdkkdkkdkdkkkdddkdkkddkkkjeeeeejejjjjejjejeejjejjjeejjjeeejjjeeejjjejeejejeejejejjeejeeejjjjeeejjjejeejjejeejjjeejejeejejejeejjeejeejjjjeejeeeeeejjjejejeeeejjejejeejjeejjeejeeejeeejjeejjjjeejeeejjjjjjeeejjjjjejjeeeeeejjejjejjejejejjjjjjjejjjjejeejeeeeejjjeeeeeeejeeejjjeeejejejddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkkkkkdkkdkkdkkdddddkkkddkkdkkkkkdkdddddkkdkdkkkdkkdddkdddddddkdkddkdkdkdddkdkdkkdkdkddkkkkkddkddkkdkddkdkkkkkddkkdddkdkddkdkkddkkdkddkkkddkkkkkkdkddkdkddkddkddkddkkddkkkdkdkdkkdkddddkddddkkkkddddkkdddkkkddkkdkdkkdkdkkkkddddkddkddkkkkkddkddkkdddkkejeejjjeejjjjjjeejjeeeejejeejeejejjjeeejeejeejjeejjejjjejejeeeejjjjejejjeeeejeeejejjjjeejejeejejejjeejeeejjjeejejjeejejjejeeejjeeeejjjejejeejjjeeejjjeejjeejjjejejeejjjjejeeeejeeeejjjjeeejjeejejeeeejjejjjjjejejjjejjeeeejeeejeeejejjeejejeejejejjeejjjjjejdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkdkkdddkkdddkdddkkkdkkkkkdddkkddkkdkkkdkddkddkkdddkkddkkkkddkkkkkkkdddkkddkkdkdkkddkkkdddddddkdddddkdkkdkkkkdkkkdkdddkddkkkkkkkdkdkdkdddkkkdddkkdddkdkkddkkdkdkdkdkkkdkdddkkkddddkkkkddkddkkkdkddddkkkdddkkkkdkddkkkkdddkdkkkkdkdkkdkdkkkddkkddkddkddddjejeejejejejeejjejjjjjjejeeeeejejjeejeejeeejjjejejjjejeeeejjjeejejejjeeejeejjjjeejjjjeeeeeeejjjjjjejejeeejeejjjejjjejjejeeeeejjejjjejejeeeeejjjejjjeeeeejeejejjjjeeejeeejjejjejjejeejeejjejjjejeeejjjejjeejejjeejjjeejejjjeeeeejjjjjjeeeeejejjeejjeejeejeejjejjedddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkddkkkkddddkkdkdkkdkkdkdkddkdkdkddkkdkdkdkkdkddkkddkddkdkdkddkkkddkkdkdddkdkkkkkkkddddkkdkkddkdkkkkkdddkkdddkkdkdkkdkddkddkkddkddkdkkdkdkkkkdkdddkkkdddkkkddkdkdddkkkkkddkkdkkdddkkkddkkkdddkkkddkkkdddkdkddkkdkddkkkdkkddkdkkkddkdkdkdkkkkddkdddkkeejjeejjjjeejejejjjeeejeeejjjeejeejjejjejeeejejjjeejeejjejejejejeeejejjjejejjejejeejeejjejejjjeejejjejeeejejejjejejejeejejeejjejejejejejejeejejjjejejjeeeejjjejeeeejjejjeejejjjeejejjeejejjjejeeeejejjjejejejeejjeejjejejejejeejejjjjeeejeejjejejjeeeejjeejeejjjddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkdkdkkddkkdddkdkkddkddkkdkdkkdkddddkkkdkkdddkkkdkkddkkddkddkdkkddkkdddkkkdddkkdkdkkdkddkddkdkdkkdkkddkkdkddkdkdkdddkkkdkkkkddkddkkddkdkdkkkkddddddkkkddkdkdkdkkdkkkddkdkkkkddddkkdkkddkkkddkkdkddkkdkdkdkkkkdddkkkkkdkddkkkdddkdddkkkkdkkkddkkkkddkdejjeejjejjeejjeejeejejejeejjejejejejjjeeejejjeejjjeeeejjeejjejjejejeejejeejjejjeeejjeejjejjeeejjeejjeejjjjeejjeejejejjeejjeejeejjejejeejjeejjeejjeejjeejejejejjejejeejejejjejjeeeejjejjejjeejeejeejjjejejjeejejejeejjeejeejjjjeejejejeejejjeejejjejejeejjejeejejddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkdkddkdkkkdddkkdkddkkkdddkdkdkkddkdkkkdddkkdddkkkdkddkdkkddkdkdkkkddkkddkkddddkkkddkdkdkkddkddkkkdkdkkddddkkdkdkdkdkdkdkkdkddkdkkkddkdkddkkddkkdddkkddkkkddkkdkddkkdddkkddkkddkkdkkdkdkdddkkddkkkkdddkkdddkkdkkddkkkdkkkdkkdkkdkdkkdkdkkdkkdkkkkdkdkjeejjejeejejjeejejejjeejejejejejejejejejejjejeejjeejjeejejjeejejejejejejejejjejejeejjeejejjejeejejejejejjeejjejeejejjeejjeejjejejeejejjejeejjejejejeejejejejejejjejejejeejjeejjeejejjejeejjeejejjejejejeejejjejejejejejejejejejejeejejjejejejeejejejjejejeejejejdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddkkdkddkkdkdkddkkdkddkdkkddkdkkddkkddkdkkdkddkdkdkdkdkdkkddkkddkdkkdkdkddkkddkdkkddkkdkdkddkdkdkkdkdkddkkdkddkdkdkdkkddkkddkdkdkdkkdkdkdkddkkdkdkddkkddkdkdkkdkdkdkdkddkdkkddkkdkdkdkdkddkkddkkddkdkdkkdkdkdkdkdkddkkddkkddkkdkdkdkddkdjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjjj">link</a></td>
  </tr>
</table>

## Usage

To use the push_swap program, compile it with the `make` command and then run it with the list of integers to be sorted as arguments. For example:

`./push_swap 3 1 2` 

If you get any error, try to run it in bash instead zsh

to test with some random numbers:

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
    -   A PDF on using LIS sort for push_swap: [https://v0tdou.csb.app/lis_sort.pdf](https://v0tdou.csb.app/lis_sort.pdf)
-   Insertion sort in small chunks:
    
    -   A tutorial on using insertion sort in small chunks for push_swap: [https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
    -   A video explanation of using insertion sort in small chunks: [https://youtu.be/ZHVk2blR45Q](https://youtu.be/ZHVk2blR45Q)
