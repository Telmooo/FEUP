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
Let the coins available be stored in sequence:
C = {c<sub>1</sub>, c<sub>2</sub>, ..., c<sub>n</sub>}

Then the number of coins used for each can also be stored in a similiar sequence:
C<sub>used</sub> = {0, 0, ..., 0} with initial values as 0.<br>
And the amount left in each iteration has initial value A<sub>0</sub> = Total Amount.<br>
Now we can apply the iterative step:<br>
![](https://imgur.com/EmHHCso?raw=true)
