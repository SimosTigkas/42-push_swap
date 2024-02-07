# 42-push_swap

## Description:
This project involves sorting a stack of integers in ascending order using specific operations on two stacks named a and b.

## Rules:
### The stacks:
   Stack a: Contains a random amount of negative and/or positive numbers without duplicates.
   Stack b: Initially empty.
### Operations:
**sa**: Swap the first 2 elements of stack a. \n
**sb**: Swap the first 2 elements of stack b. \n
**ss**: sa and sb simultaneously. \n
**pa**: Push the top element of stack b onto stack a. \n
**pb**: Push the top element of stack a onto stack b. \n
**ra**: Rotate up all elements of stack a by 1. \n
**rb**: Rotate up all elements of stack b by 1. \n
**rr**: ra and rb simultaneously. \n
**rra**: Reverse rotate down all elements of stack a by 1. \n
**rrb**: Reverse rotate down all elements of stack b by 1. \n
**rrr**: rra and rrb simultaneously. \n

## Usage:
**Program Name: push_swap**

***Arguments***: A list of integers representing stack a, with the first argument at the top of the stack.
***Output***: Display the smallest list of instructions to sort stack a, each instruction separated by a newline.

**Project Requirements**:
Makefile: Compile source files without relinking.
Source files: *.h and *.c files.
Makefile commands: all, clean, fclean, re.
External functions allowed: read, write, malloc, free, exit.
Custom ft_printf function or equivalent.
Libft usage authorized.
Rules and Constraints:
Global variables are forbidden.
Program must handle errors, including non-integer arguments, integers exceeding limits, and duplicates.
If no parameters are specified, the program should not output anything.
Output "Error" followed by a newline for encountered errors.
Ensure the sorted stack is displayed properly; otherwise, the grade will be 0.

## Notes:
The program must produce the smallest number of operations to sort the stack.
The effectiveness of the sorting algorithm will be evaluated based on the number of operations and the correctness of the sorting.
Utilize the provided checker_OS program for evaluation.
