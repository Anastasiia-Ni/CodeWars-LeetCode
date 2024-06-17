/* Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
 
Constraints:
0 <= c <= 231 - 1 */

#include <math.h>

class Solution {
public:
    bool judgeSquareSum(int c) {
        int len = sqrt(c);
        long p1 = 0, p2 = len;
        while (p1 <= p2) {
            long long num = p1 * p1 + p2 * p2;
            if (num == c) return true;
            else if (num > c) --p2;
            else if (num < c) ++p1;
        }
        return false;
    }
};