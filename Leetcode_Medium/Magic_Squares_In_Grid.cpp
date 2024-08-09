/* A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 
such that each row, column, and both diagonals all have the same sum.

Given a row x col grid of integers, how many 3 x 3 contiguous magic square subgrids are there?

Note: while a magic square can only contain numbers from 1 to 9, grid may contain numbers up to 15.

Example 1:
Input: grid = [[4,3,8,4],[9,5,1,9],[2,7,6,2]]
Output: 1

Example 2:
Input: grid = [[8]]
Output: 0
 
Constraints:
row == grid.length
col == grid[i].length
1 <= row, col <= 10
0 <= grid[i][j] <= 15 */

#include <vector>
using namespace std;


class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int res = 0;
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }

        for (int i = 0; i <= grid.size() - 3; ++i) {
            for (int j = 0; j <= grid[0].size() - 3; ++j) {
                if (checkMagic(grid, i, j)) {
                    ++res;
                }
            }
        }

        return res;
    }

    bool checkMagic(vector<vector<int>> mat, int x, int y) {
        vector<int> count(10, 0);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                int num = mat[x + i][y + j];
                if (num < 1 || num > 9 || count[num] > 0) {
                    return false;
                }
                count[num]++;
            }
        }

        int sum = mat[x][y] + mat[x+1][y+1] + mat[x+2][y+2];
        if (mat[x][y+2] + mat[x+1][y+1] + mat[x+2][y] != sum) {
            return false;
        }

        for (int i = 0; i < 3; ++i) {
            if (mat[x+i][y] + mat[x+i][y+1] + mat[x+i][y+2] != sum)
                return false;
            if (mat[x][y+i] + mat[x+1][y+i] + mat[x+2][y+i] != sum)
                return false;
        }
        return true;
    }
};