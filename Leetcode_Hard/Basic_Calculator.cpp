/* Given a string s representing a valid expression, implement a basic calculator to evaluate it, 
and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings 
as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
 
Constraints:
1 <= s.length <= 3 * 105
s consists of digits, '+', '-', '(', ')', and ' '.
s represents a valid expression.
'+' is not used as a unary operation (i.e., "+1" and "+(2 + 3)" is invalid).
'-' could be used as a unary operation (i.e., "-1" and "-(2 + 3)" is valid).
There will be no two consecutive operators in the input.
Every number and running calculation will fit in a signed 32-bit integer. */

using namespace std;
#include <string>
#include <stack>

class Solution {
public:
    int calculate(string s) {
        stack<int> tmp;
        int res = 0, num = 0, sign = 1;

        for (char c : s) {
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '+' || c == '-') {
                res += num * sign;
                num = 0;
                sign = (c == '+' ? 1 : -1);
            }
            else if (c =='(') {
                tmp.push(res);
                tmp.push(sign);
                res = 0;
                sign = 1;
            }
            else if (c == ')') {
                res += num * sign;
                num = 0;
                res *= tmp.top();
                tmp.pop();
                res += tmp.top();
                tmp.pop();
            }
        }
        return res + num * sign;
    }
};