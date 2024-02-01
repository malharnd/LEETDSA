# Rat in a Maze

Consider a rat placed at (0, 0) in a square matrix of order N * N. It has to reach the destination at (N - 1, N - 1). Find all possible paths that the rat can take to reach from source to destination. The directions in which the rat can move are 'U' (up), 'D' (down), 'L' (left), 'R' (right). Value 0 at a cell in the matrix represents that it is blocked and the rat cannot move to it, while value 1 at a cell in the matrix represents that the rat can travel through it.

## Example

### Input

N = 4
m[][] = {{1, 0, 0, 0},
         {1, 1, 0, 1}, 
         {1, 1, 0, 0},
         {0, 1, 1, 1}}

### Output

DDRDRR DRDDRR

Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

### Input

N = 2
m[][] = {{1, 0},
         {1, 0}}

### Output

-1

Explanation: No path exists and the destination cell is blocked.

## Approach

The problem can be solved using backtracking. We start from the source cell and explore all possible paths recursively by moving in all four directions (up, down, left, right). We mark the current cell as visited and continue exploring until we reach the destination cell or encounter a blocked cell. If we reach the destination cell, we add the current path to the list of valid paths. Finally, we return the list of valid paths in lexicographically increasing order.

## Complexity Analysis

The time complexity of this approach is O((3N^2)) and the auxiliary space complexity is O(L * X), where L is the length of the path and X is the number of paths.

## Constraints

- 2 ≤ N ≤ 5
- 0 ≤ m[i][j] ≤ 1
