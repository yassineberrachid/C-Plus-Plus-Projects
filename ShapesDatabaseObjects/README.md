The project consists of two main parts. In the first part, you will write a command parser that provides a textual input interface to your program. The parser takes a sequence of commands as input. The commands create, delete modify and display shapes to be drawn on the screen. Each command consists of an operation keyword followed by arguments. The command and the arguments are separated by one or more spaces.
Thus, the program takes input from the standard input, parse it, verify that it is correct, prints a response or error message and either create, delete or modify Shape objects that represent the shapes specified in the command. The command parser loops, processing input as long as input is available.

The second part implements a simple database of objects that stores the created shapes. To do so, we implement a class called Shape that is used to store the shape properties. We also create and maintain a dynamically allocated array of pointers to Shape objects to keep track of Shape objects created and deleted.

        ![Capture](https://user-images.githubusercontent.com/95399226/147856026-e27c4b3d-d5f8-43a2-b65d-a23105ca0730.PNG)
                                                 Figure 1: Error-checking priorities   


        ![Uploading image.png…]()
                                                 Figure 2: Example of a sequence of commands inputed by the user
