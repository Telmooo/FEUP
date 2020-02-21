# Dynamic Programming

## Calculating Factorial using Recursive Method
1. Time Complexity: Linear (n)
2. Space Complexity: Linear (n)
#### Remarks
Recursive method to calculate the factorial of a number is heavier in memory than the iterative counterpart.
In order to calculate the factorial of a number **n** there is need to allocate memory for **n** function calls, while
the same time complexity.

## Calculating Factorial with Iterative Method
1. Time Complexity: Linear (n)
2. Space Complexity: Constant (1)
#### Remarks
While having the same time complexity as the recursive counterpart, this solution doesn't waste allocating memory
for the function.

## Change

Data (input):<br>
m: total change<br>
**V** = {v<sub>1</sub>, v<sub>2</sub>, ..., v<sub>n</sub>}, |**V**| = n<br>

Decisive variables:<br>
**X** = {x<sub>1</sub>, x<sub>2</sub>, ..., x<sub>n</sub>}, |**X**| = n<br>

Function goal:<br>
min ∑<sup>n</sup><sub>i=1</sub> x<sub>i</sub>

Restrictions:<br>
∑<sup>n</sup><sub>i=1</sub> x<sub>i</sub> * v<sub>i</sub> = m
