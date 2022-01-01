Tic-tac-toe is a simple game commonly played by children. Two players, X and O, take turns
marking the spaces in a 3x3 grid or board. The player who succeeds in placing three of their marks in a horizontal, vertical, or diagonal line wins the game. Player X is always the first to place a mark. The following example shows the progression of a game won by player X.
![image](https://user-images.githubusercontent.com/95399226/147858804-7c16d8b1-6dbb-4ed0-a613-de9156959f34.png)

                            Figure 1: Example of a tictactoe game
The game consists of two main components: the game controller or simply the controller and
the game logic. The controller is responsible for collecting players' input to determine the grid (or board) location a player wishes to place a mark in. It is also responsible for displaying the game board.
The controller is implemented by the main function of the game. The game logic contains a single function called playMove. This function determines, for each player input, if the move represented by the selected board coordinates are valid or not, if the game is over or not and accordingly plays the move.
The controller and the game logic interact using an object of the type GameState. This object stores the state of the game, including the board coordinates selected by a player, the marks at
each board location (i.e., X or O) , whether the move is valid or not, whose turn it is, whether the game is over or not, etc.

  ![image](https://user-images.githubusercontent.com/95399226/147858890-a2f2ada4-55ed-47f1-abb5-51369d102fa9.png)
                          
                          Figure 2: The game components

