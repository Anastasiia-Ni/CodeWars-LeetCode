/* Snail Sort

Given an n x n array, return the array elements arranged 
from outermost elements to the middle element, traveling clockwise.

array = [[1,2,3],
         [4,5,6],
         [7,8,9]]

snail(array) #=> [1,2,3,6,9,8,7,4,5]

For better understanding, please follow the numbers 
of the next array consecutively:

array = [[1,2,3],
         [8,9,4],
         [7,6,5]]

snail(array) #=> [1,2,3,4,5,6,7,8,9] */

#include <stdlib.h>

int *snail(size_t *outsz, const int **mx, size_t rows, size_t cols) {
  *outsz = rows * cols;
  int *sn = calloc(*outsz, sizeof(int));
  
  int istart = 0, iend = 0, jstart = 0, jend = 0;

  for (size_t k = 0, i = 0, j = 0; k < rows * cols; k++)
  {
    sn[k] = mx[i][j];
    if (i == istart && (j < cols - jend - 1))
      j++;
    else if ((j == cols - jend - 1) && (i < rows - iend - 1))
      i++;
    else if ((i == rows - iend - 1) && (j > jstart))
      j--;
    else
      i--;

    if ((j == jstart) && (i == istart + 1) && (jstart != cols - jend - 1))
    {
      istart++;
      jstart++;
      iend++;
      jend++;
    }
  }
  return sn;
}
