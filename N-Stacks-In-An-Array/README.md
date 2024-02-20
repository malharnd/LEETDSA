# N-Stack Implementation

This repository contains a solution for implementing 'N' stacks using a single array of size 'S'. It supports two types of operations: pushing an element into a specific stack and popping the top element from a specific stack.

## Problem Statement

Design a data structure to implement ‘N’ stacks using a single array of size ‘S’. It should support the following operations:

- `push(X, M)`: Pushes an element `X` into the `M`th stack. Returns `True` if the element is pushed into the stack, otherwise `False`.
- `pop(M)`: Pops the top element from the `M`th stack. Returns `-1` if the stack is empty, otherwise, returns the popped element.

### Input Format

The input consists of the following parameters:

- `N`: Number of stacks.
- `S`: Size of the array.
- `Q`: Number of queries.
- Queries consist of a type `P` (1 for push, 2 for pop) and an element `X` (for push operation).

### Constraints

- `1 <= N <= S <= 1000`
- `1 <= Q <= 10^5`
- `1 <= P <= 2`
- `1 <= X <= 10^5`

### Sample Input 1:

- 3 6 5
- 1 10 1
- 1 20 1
- 1 30 2
- 2 1
- 2 2


### Sample Output 1:

True
True
True
20
30


##  Explanation

For the given input, the program performs operations on the stack as follows:
- `push(10, 1)`: Pushes element ‘10’ into the 1st stack, returning `True`.
- `push(20, 1)`: Pushes element ‘20’ into the 1st stack, returning `True`.
- `push(30, 2)`: Pushes element ‘30’ into the 2nd stack, returning `True`.
- `pop(1)`: Pops the top element from the 1st stack, returning `20`.
- `pop(2)`: Pops the top element from the 2nd stack, returning `30`.