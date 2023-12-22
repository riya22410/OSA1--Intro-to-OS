*************** Description of Q3 ***********************
This Bash script reads input from an `input.txt` file line by line, processes the data based on the specified operations, and then writes 
the results to an `output.txt` file within a directory named "Result". Here's a step-by-step explanation of how the code works:

1. `mkdir -p Result`: This line creates a directory named "Result" if it doesn't already exist. The `-p` option ensures that the command 
creates the directory and its parent directories if needed.

2. `while IFS=" " read -r x y operation; do`: This line starts a loop that reads each line from the `input.txt` file, splits it into three 
parts (`x`, `y`, and `operation`) based on space as the delimiter, and assigns them to the respective variables. `IFS=" "` sets the Internal 
Field Separator to space, ensuring that the input fields are split correctly.

3. The `case "$operation" in ... esac` construct checks the value of the `operation` variable and performs different actions based on its 
value:
   - If `operation` is "xor", it calculates the result of bitwise XOR (`x ^ y`) and assigns it to the `result` variable.
   - If `operation` is "product", it calculates the result of multiplication (`x * y`) and assigns it to the `result` variable.
   - If `operation` is "compare", it compares the values of `x` and `y` and assigns the larger value to the `result` variable.
   - If `operation` is anything else, it prints an error message and continues to the next iteration of the loop using the `continue` 
   command.

4. After determining the result based on the operation, the script writes the `result` to the `output.txt` file within the "Result" 
directory using the command `echo "$result" >> Result/output.txt`. The `>>` operator appends the result to the file without overwriting 
its contents.

5. The loop continues to the next line in the `input.txt` file until all lines have been processed.

6. Once the loop has processed all lines, the script completes execution.

In summary, this Bash script reads input data from `input.txt`, performs different operations based on the specified operation type, and 
writes the results to `output.txt` within the "Result" directory. It handles various operation types and skips unknown operation types while 
processing the input data.
