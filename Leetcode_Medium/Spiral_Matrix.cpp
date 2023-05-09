/* Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100 */ 

using namespace std;
#include <vector>

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int istart = 0, iend = n - 1, jstart = 0, jend = m - 1;

        while (res.size() < m * n) {
            for (int i = istart; i <= iend && res.size() < m * n; i++)
                res.push_back(matrix[jstart][i]);
            for (int j = jstart + 1; j <= jend && res.size() < m * n; j++)
                res.push_back(matrix[j][iend]);
            for (int i = iend - 1; i >= istart && res.size() < m * n; i--)
                res.push_back(matrix[jend][i]);
            for (int j = jend - 1; j >= jstart + 1 && res.size() < m * n; j--)
                res.push_back(matrix[j][istart]);
            istart++;
            iend--;
            jstart++;
            jend--;
        }
        return res;
    }
};