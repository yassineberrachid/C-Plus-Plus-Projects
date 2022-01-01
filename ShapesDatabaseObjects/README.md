The project consists of two main parts. In the first part, you will write a command parser that provides a textual input interface to your program. The parser takes a sequence of commands as input. The commands create, delete modify and display shapes to be drawn on the screen. Each command consists of an operation keyword followed by arguments. The command and the arguments are separated by one or more spaces.
Thus, the program takes input from the standard input, parse it, verify that it is correct, prints a response or error message and either create, delete or modify Shape objects that represent the shapes specified in the command. The command parser loops, processing input as long as input is available.

The second part implements a simple database of objects that stores the created shapes. To do so, we implement a class called Shape that is used to store the shape properties. We also create and maintain a dynamically allocated array of pointers to Shape objects to keep track of Shape objects created and deleted.
        
       ![Capture](https://user-images.githubusercontent.com/95399226/147856256-aa8a9caf-3c44-4cbc-b37d-204c54c70ffa.PNG)
_                                          Figure 1: Error checking priorities for user input
_       
       ![2](https://user-images.githubusercontent.com/95399226/147856269-2374dd76-3b3e-4d0a-b257-96387731f060.PNG)
                                          Figure 2: Example of a sequence of commands inputed by the user
                                         
                                         