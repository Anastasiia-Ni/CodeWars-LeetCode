/* Given an integer n, break it into the sum of k positive integers, where k >= 2, 
and maximize the product of those integers.
Return the maximum product you can get.

Example 1:
Input: n = 2
Output: 1
Explanation: 2 = 1 + 1, 1 × 1 = 1.

Example 2:
Input: n = 10
Output: 36
Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 
Constraints:
2 <= n <= 58 */


using namespace std;
#include <vector>

class Solution {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3)
            return n - 1;

        int res = 1;
        while (n > 4) {
            res *= 3;
            n -= 3;
        }
        res *= n;

        return res;
    }
}; // time: O(n), space: O(1)

class Solution2 {
public:
    int integerBreak(int n) {
        if (n == 2 || n == 3)
            return n - 1;

        if (n == 4)
            return n;
        
        vector<int> prod(n + 1, 0);
        prod[1] = 1;
        prod[2] = 1;
        prod[3] = 2;
        prod[4] = 4;

        for (int k = 5; k <= n; ++k) {
            prod[k] = 3 * max(prod[k - 3], k - 3);
        }

        return prod.back();
    }
}; // time: O(n), space: O(n)