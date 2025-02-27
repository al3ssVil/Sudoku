# Sudoku Game (Interactive)

A C++ program where you can play Sudoku interactively. The program generates a random Sudoku puzzle on different difficulty levels (easy, medium, hard) and allows you to input your moves, providing guidance on which rows/columns to choose from.

## Description

This project is an interactive Sudoku game implemented in C++. The program generates a random Sudoku puzzle at one of three difficulty levels (easy, medium, hard). After that, you play the game by inputting your moves (numbers) into the grid, and the program provides feedback by suggesting on which row/column to place a number next.

There are no external dependencies, and it can be compiled and run on any system with a C++ compiler.

## Difficulty Levels

The program generates Sudoku puzzles at the following difficulty levels:

- **Easy**: A puzzle with fewer empty cells, making it easier to solve.
- **Medium**: A puzzle with a moderate number of empty cells, requiring more logical steps to solve.
- **Hard**: A puzzle with many empty cells, requiring more backtracking and deduction to solve.

## Example Gameplay

1. **Starting the Game**: When you start the game, you can select a difficulty level.
   
 ![image](https://github.com/user-attachments/assets/b484cc4c-c63c-4fd5-bce9-c3cfc929c1c8)

2. **Generate Puzzle**: After selecting the difficulty, the program will generate a random Sudoku puzzle and display it.

### Example Puzzle (Easy):
![image](https://github.com/user-attachments/assets/0455b8cc-f662-4a72-96bf-86ad608275d8)

## Example Gameplay

1. **Making a Move**: The program will ask you to enter a number (between 1 and 9) to place in an empty cell.

2. **Input**: After entering the number, the program will prompt you to provide the row and column (using 1-based indexing) where you want to place the number.

3. **Move Validation**: If the number you enter is correct for the given position, it will be placed in the Sudoku grid. If it's incorrect, the program will inform you that the move is invalid and ask you to try again. Your total number of mistakes will be counted and displayed.

4. **Progress**: The game will continue asking for your moves, keeping track of the errors, until the puzzle is completed.

5. **Completed Puzzle**: Once the puzzle is solved, the program will display the completed Sudoku grid and show the number of mistakes you made during the game.
