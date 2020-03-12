# Problem Sheet 3
---
## Exercise 1

---
## Exercise 2
#### a)
The numbers that can be written are:
- 12345
- 14523
- 12435
- 12453
- 14253
- 14235

#### b)
The output is:
```
12435

```
The function `write` puts the string without waiting, thus we get mixed numbers as the execution of the instructions is dependent on how to CPU processes the programs.

#### c)
We obtain two numbers:
```
123
145
```
As the function `printf` stores it in a buffer until it enters a newline or the program exits.
Thus, when forking the buffer is copied to child process, and upon exit it is printed each buffer.

#### d)
By switching the instruction `printf("1")` to `printf("1\n")` the buffer is empty when the fork happens, so the number 1 won't be repeated and the sequence will be dependent on who executes first. The output obtained was:
```
1
23
45
```
