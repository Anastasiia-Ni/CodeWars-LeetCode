/* Given a string s, remove duplicate letters so that every letter appears once and only once. 
You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"

Example 2:
Input: s = "cbacdcbc"
Output: "acdb"
 
Constraints:
1 <= s.length <= 104
s consists of lowercase English letters. */

using namespace std;
#include <vector>
#include <string>

class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> count(26, 0);
        vector<bool> used(26, false);
        string result;

        for (char c : s) 
            count[c - 'a']++;
        
        for (char c : s) {
            count[c - 'a']--;
            if (!used[c - 'a']) {
                while (!result.empty() && result.back() > c && count[result.back() - 'a'] > 0) {
                    used[result.back() - 'a'] = false;
                    result.pop_back();
                }
                result.push_back(c);
                used[c - 'a'] = true;
            }
        }
        return result;
    }
};