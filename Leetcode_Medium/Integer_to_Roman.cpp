/* Given an integer, convert it to a roman numeral.

Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.

Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.

Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 
Constraints:
1 <= num <= 3999 */

using namespace std;
#include <map>

class Solution {
public:
    string intToRoman(int num) {
        string res;
        map<int, string> roman = {{1,"I"},{4,"IV"}, {5, "V"}, {9, "IX"}, {10, "X"}, {40, "XL"}, {50, "L"}, {90, "XC"}, {100, "C"}, {400, "CD"}, {500, "D"}, {900, "CM"}, {1000, "M"}};
        map<int, string>::const_iterator it = roman.end();
        --it;
        while (num) {
            if (num >= (it->first)) {
                res += it->second;
                num -= it->first;
            }
            else
                --it;
        }
        return res;
    }
};