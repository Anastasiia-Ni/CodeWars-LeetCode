/* Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
 
Constraints:
1 <= n <= 20 */

using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int nb = 1;
        for (int istart = 0, iend = n - 1, jstart = 0, jend = n - 1; istart <= iend && jstart <= jend; istart++, jstart++, iend--, jend--) {
            for (int k = istart; k <= iend; k++, nb++)
                res[jstart][k] = nb;
            for (int m = istart + 1; m <= iend; m++, nb++)
                res[m][jend] = nb;
            for (int k = iend - 1; k >= istart; k--, nb++)
                res[jend][k] = nb;
            for (int m = jend - 1; m >= jstart + 1; m--, nb++)
                res[m][istart] = nb;
        }
        return res;
    }
};