/* You have a pointer at index 0 in an array of size arrLen. At each step, you can move 1 position to the left, 
1 position to the right in the array, or stay in the same place 
(The pointer should not be placed outside the array at any time).

Given two integers steps and arrLen, return the number of ways such that your pointer is still at index 0 
after exactly steps steps. Since the answer may be too large, return it modulo 109 + 7.

Example 1:
Input: steps = 3, arrLen = 2
Output: 4
Explanation: There are 4 differents ways to stay at index 0 after 3 steps.
Right, Left, Stay
Stay, Right, Left
Right, Stay, Left
Stay, Stay, Stay

Example 2:
Input: steps = 2, arrLen = 4
Output: 2
Explanation: There are 2 differents ways to stay at index 0 after 2 steps
Right, Left
Stay, Stay

Example 3:
Input: steps = 4, arrLen = 2
Output: 8
 
Constraints:
1 <= steps <= 500
1 <= arrLen <= 106 */

using namespace std;
#include <vector>

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int const MOD = 1000000007;
        int pos = min(steps, arrLen - 1);
        vector<vector<int>> dp(steps + 1, vector<int>(pos + 1, 0));
        dp[0][0] = 1;

        for (int i = 1; i <= steps; ++i) {
            for (int j = 0; j <= pos; ++j) {
                dp[i][j] = dp[i - 1][j];
                if (j > 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
                if (j < pos)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
            }
        }
        
        return dp[steps][0];
    }
};