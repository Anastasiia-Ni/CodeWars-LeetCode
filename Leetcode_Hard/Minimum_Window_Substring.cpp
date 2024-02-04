/* Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. 
If there is no such substring, return the empty string "".

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
 
Constraints:
m == s.length
n == t.length
1 <= m, n <= 105
s and t consist of uppercase and lowercase English letters.
*/

using namespace std;
#include <string>

class Solution {
public:
    string minWindow(string s, string t) {
        string::iterator left = s.begin(), right = s.begin(), start = s.begin();
        std::unordered_map<char, int> target, window;
        int formed = 0, min_len = INT_MAX;

        for (char ch : t) {
            target[ch]++;
        }

        int required = target.size();

        while (right != s.end()) {
            char cur = *right;
            window[cur]++;
            if (target.count(cur) && window[cur] == target[cur]) {
                formed++;
            }

            while (formed == required && left <= right) {
                if (right - left + 1 < min_len) {
                    min_len = right - left + 1;
                    start = left;
                }

                char l_char = *left;
                window[l_char]--;

                if (target.count(l_char) && window[l_char] < target[l_char]) {
                    formed--;
                }

                ++left;
            }
            ++right;
        }
        return min_len == INT_MAX ? "" : s.substr(start - s.begin(), min_len);

    }
};