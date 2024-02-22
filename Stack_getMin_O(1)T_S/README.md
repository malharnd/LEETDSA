# Stack Data Structure with Minimum Element Retrieval

This is a simple implementation of a stack data structure in Python that allows for operations such as push (adding an element), pop (removing the top element), top (retrieving the top element), and also provides a way to retrieve the minimum element in constant time.

## Functionality

### 1. `push(data)`

- **Description:** Adds an integer element to the stack.
- **Input:** An integer `data` to be pushed onto the stack.
- **Output:** None

### 2. `pop()`

- **Description:** Removes the top element from the stack.
- **Input:** None
- **Output:** None

### 3. `top()`

- **Description:** Retrieves the top element of the stack.
- **Input:** None
- **Output:** The top element of the stack.

### 4. `getMin()`

- **Description:** Retrieves the minimum element in the stack.
- **Input:** None
- **Output:** The smallest element present in the stack.

## Sample Input/Output

### Sample Input 1:

6
1 13
1 47
3
1 8
2
4

### Sample Output 1:

47
13

## Explanation

- Query 1: Pushes `13` onto the stack.
- Query 2: Pushes `47` onto the stack.
- Query 3: Prints the top element in the stack, which is `47`.
- Query 4: Pushes `8` onto the stack.
- Query 5: Pops the top element (`8`) from the stack.
- Query 6: Retrieves the minimum element in the stack, which is `13`.

## Constraints

- `1 <= Q <= 1000` (total number of queries)
- `1 <= query type <= 4`
- `-10^9 <= data <= 10^9` and `data != -1` (data pushed onto the stack)