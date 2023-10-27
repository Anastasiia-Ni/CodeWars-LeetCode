/* Given a string s, return the longest palindromic substring in s.

Example 1:
Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.

Example 2:
Input: s = "cbbd"
Output: "bb"
 
Constraints:
1 <= s.length <= 1000
s consist of only digits and English letters. */

using namespace std;
#include <string>

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) 
            return s;
            
        int start = 0;
        int max_len = 1;
        for (int i = 0; i < s.size(); ++i){
            int len = 1;
            while (i - len >= 0 && i + len < s.size()){
                if (s.at(i - len) == (s.at(i + len))){
                if (max_len < 2 * len + 1) {
                    max_len = 2 * len + 1;
                    start = i - len;                }
                }
                else
                    break;
                len++;
            }
            
            len = 1;
            while (i - len + 1 >= 0 && i + len < s.size()){
                if (s.at(i - len + 1) == s.at(i + len)){
                    if (max_len < 2 * len){
                        max_len = 2 * len;
                        start = i + 1 - len;
                    }
                }
                else
                    break;
                len++;
            }
        }
        return s.substr(start, max_len);
	}
};