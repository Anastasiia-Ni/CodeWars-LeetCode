/* Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
You must do it in place.

Example 1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example 2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]
 
Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-2**31 <= matrix[i][j] <= 2**31 - 1 */


using namespace std;
#include <vector>

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int size_col = matrix.size();
        int size_row = matrix[0].size(); 
        vector<int> col(size_col, 0);
        vector<int> row(size_row, 0);
        for (int i = 0; i < size_col; ++i) {
            for (int j = 0; j < size_row; ++j) {
                if (!matrix[i][j]) {
                    col[i] = 1;
                    row[j] = 1;
                }
            }
        }

        for (int i = 0; i < size_col; ++i) {
            for (int j = 0; j < size_row; ++j) {
                if (col[i] || row[j]) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};