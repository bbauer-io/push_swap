# push_swap
Given a stack of data, one empty stack, and a limited set of possible operations, push_swap efficiently sorts the data in the first stack.

To build:
```
git clone https://github.com/brianbauer42/push_swap.git
make
```
To receive sorting instructions for a set of numbers:
```
./push_swap 4 67 3 87 23
```
Or:
```
ARG="4 67 3 87 23"; ./push_swap $ARG
```
To verify that the instructions are good:
```
./push_swap $ARG | ./checker
```
To count number of instructions:
```
ARG="4 67 3 87 23" ; ./push_swap $ARG | wc -l
```
For 100 random ints, less than 700 operations should be required.  
For 500 random ints, fewer than 5300 operations.

To see a detailed printout of each stack for every move, add the -v option when calling ./push_swap. (not compatible for passing data to the checker)

Note: There can be no duplicate inputs or the program will report an error.

Operations allowed:  
*sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).  
*sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).  
*ss : sa and sb at the same time.  
*pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.  
*pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.  
*ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.  
*rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.  
*rr : ra and rb at the same time.  
*rra : reverse rotate a - shift down all elements of stack a by 1. The flast element becomes the first one.  
*rrb : reverse rotate b - shift down all elements of stack b by 1. The flast element becomes the first one.  
*rrr : rra and rrb at the same time.
