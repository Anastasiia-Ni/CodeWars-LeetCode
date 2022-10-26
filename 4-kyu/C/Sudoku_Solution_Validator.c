/* Sudoku Background

Sudoku is a game played on a 9x9 grid. The goal of the game 
is to fill all cells of the grid with digits from 1 to 9, 
so that each column, each row, and each of the nine 3x3 sub-grids 
(also known as blocks) contain all of the digits from 1 to 9. 

Sudoku Solution Validator

Write a function validSolution/ValidateSolution/valid_solution() 
that accepts a 2D array representing a Sudoku board, and returns 
true if it is a valid solution, or false otherwise. The cells of 
the sudoku board may also contain 0's, which will represent empty cells. 
Boards containing one or more zeroes are considered to be invalid solutions.

The board is always 9 cells by 9 cells, and every cell only contains 
integers from 0 to 9.

Examples

validSolution([
  [5, 3, 4, 6, 7, 8, 9, 1, 2],
  [6, 7, 2, 1, 9, 5, 3, 4, 8],
  [1, 9, 8, 3, 4, 2, 5, 6, 7],
  [8, 5, 9, 7, 6, 1, 4, 2, 3],
  [4, 2, 6, 8, 5, 3, 7, 9, 1],
  [7, 1, 3, 9, 2, 4, 8, 5, 6],
  [9, 6, 1, 5, 3, 7, 2, 8, 4],
  [2, 8, 7, 4, 1, 9, 6, 3, 5],
  [3, 4, 5, 2, 8, 6, 1, 7, 9]
]); // => true

validSolution([
  [5, 3, 4, 6, 7, 8, 9, 1, 2], 
  [6, 7, 2, 1, 9, 0, 3, 4, 8],
  [1, 0, 0, 3, 4, 2, 5, 6, 0],
  [8, 5, 9, 7, 6, 1, 0, 2, 0],
  [4, 2, 6, 8, 5, 3, 7, 9, 1],
  [7, 1, 3, 9, 2, 4, 8, 5, 6],
  [9, 0, 1, 5, 3, 7, 2, 1, 4],
  [2, 8, 7, 4, 1, 9, 6, 3, 5],
  [3, 0, 0, 4, 8, 1, 1, 7, 9]
]); // => false */

#include <stdbool.h>
#include <stdlib.h>

bool validSolution(unsigned int board[9][9]){
  int fail = 0;
  int i;
  int num;
  for (i = 0; i < 9 && !fail; i++) // check lines
  {
    int *p = calloc (10, sizeof(int));
    int j;
    for (j = 0; j < 9 && !fail; j++) 
    {
       int num = board[i][j] - 1;
       if (p[num] == 0)
           p[num] = 1;
       else
           fail = 1;  // return false;
    }
  }
  for (i = 0; i < 9 && !fail; i++) // check rows
  {
    int *p = calloc (10, sizeof(int));
    int j;
    for (j = 0; j < 9 && !fail; j++) 
    {
      int num = board[i][j] - 1; 
      if (p[num] == 0)
        p[num] = 1;
      else
        fail = 1;  // return false;
    }
  }
  for (i = 0; i < 9 && !fail; i += 3) //check 3х3 squares 
  {
    int j;
    for (j = 0; j < 9 && !fail; j += 3) 
    {
       int *p = calloc (10, sizeof(int));
       int k;
       for (k = i; k < i + 3 && !fail; k++) 
       {
          int n;
          for (n = j; n < j + 3 && !fail; n++) 
          {
            int num = board[k][n] - 1; 
            if (p[num] == 0)
               p[num] = 1;
             else
               fail = 1;
          }
        }
      }
   }
   return !fail;
}
