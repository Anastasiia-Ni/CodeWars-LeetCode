/* Write a function that accepts a square matrix (N x N 2D array) and returns 
the determinant of the matrix.

How to take the determinant of a matrix -- it is simplest to start with the smallest cases:

A 1x1 matrix |a| has determinant a.

A 2x2 matrix [ [a, b], [c, d] ] or
|a  b|
|c  d|
has determinant: a*d - b*c.

The determinant of an n x n sized matrix is calculated by reducing the problem to 
the calculation of the determinants of n matrices ofn-1 x n-1 size.

For the 3x3 case, [ [a, b, c], [d, e, f], [g, h, i] ] or
|a b c|  
|d e f|  
|g h i|  
the determinant is: a * det(a_minor) - b * det(b_minor) + c * det(c_minor) 
where det(a_minor) refers to taking the determinant of the 2x2 matrix created 
by crossing out the row and column in which the element a occurs:
|- - -|
|- e f|
|- h i|  
Note the alternation of signs.

The determinant of larger matrices are calculated analogously, e.g. 
if M is a 4x4 matrix with first row [a, b, c, d], then:

det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d * det(d_minor) */

#include <iostream>
#include <vector>

using namespace std;

void getNewMatrix(vector<vector<long long> > m, size_t size, size_t row, size_t col, vector<vector<long long> > &n)
{
    for (size_t i = 0, offset_row = 0; i < size - 1; i++) {
      if (i == row)
        offset_row = 1;    
      for (size_t j = 0, offset_col = 0; j < size - 1; j++) {
        if (j == col)
          offset_col = 1;
        n[i][j] = m[i + offset_row][j + offset_col];
      }
    }
}

long long determinant(vector<vector<long long> > m) {
    size_t size = m.size();
    long long det = 0;
    int degree = 1;
  
    if (size == 1)
      return (m[0][0]);
    if (size == 2)
      return (m[0][0] * m[1][1] - m[0][1] * m[1][0]);
    vector<vector<long long> > n;
    for (size_t j = 0; j < size - 1; j++){
      vector<long long> n1(size - 1);
      n.push_back(n1);
    }
    for (size_t i = 0; i < size; i++) {
      getNewMatrix(m, size, i, 0, n);
      det += degree * m[i][0] * determinant(n);
      degree = -degree;
    }
    return (det);
}

