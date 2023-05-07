# UTF-8validator

This project was developed as part of the coursework for K04: Introduction to Programming, a course offered by National and Kapodistrian University of Athens. Throughout the course, we learned about the fundamentals of computer programming, including programming concepts.<br><br>
UTF-8validator is a C program that validates whether a given input stream is valid UTF-8 or not. It checks for invalid byte sequences, oversized code points, and other common errors.
<h2>Installation</h2>
To use UTF-8validator, you'll need a C compiler installed on your system. You can compile the program by running the following command in your terminal:<br>
<code> gcc UTF-8validator.c -o UTF-8validator </code>
<br>
This will generate an executable file named "UTF-8validator" in your current directory. <br>
<h2>Usage</h2>
Once you've compiled the program, you can use it to validate a UTF-8 encoded file or input stream by running: <br>
<code>./UTF-8validator < input_file </code> <br>
Replace "input_file" with the name of the file you want to validate. You can also pipe input to the program using standard input: <br>
<code>cat input_file | ./UTF-8validator</code><br><br>
The program will print error messages to standard output if it encounters any issues, and return an error code indicating the type of error it encountered. If the input is valid UTF-8, it will print a message indicating how many ASCII and multi-byte characters it found.<br>
<h2>Contributing</h2>
The program will print error messages to standard output if it encounters any issues, and return an error code indicating the type of error it encountered. If the input is valid UTF-8, it will print a message indicating how many ASCII and multi-byte characters it found.
