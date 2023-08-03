/* 
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. 
Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
 
Constraints:
0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].
*/

using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        string tmp;

        if (!digits.empty())
            combination(digits, result, tmp, 0);
        return result;
    }

private:
    vector<string> letters {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void combination(string &digits, vector<string> &result, string &tmp, int n) {
        if (tmp.size() == digits.size()) {
            result.push_back(tmp);
            return ;
        }
        string button = letters[digits[n] - '0'];
        for (char c : button) {
            tmp += c;
            combination(digits, result, tmp, n + 1);
            tmp.pop_back();
        }
    }
};