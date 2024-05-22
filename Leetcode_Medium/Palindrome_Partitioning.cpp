/* Given a string s, partition s such that every substring of the partition is a palindrome.
Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
 
Constraints:
1 <= s.length <= 16
s contains only lowercase English letters. */

using namespace std;
#include <string>
#include <vector>

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> vstr;
        findSubs(s, res, vstr, 0);
        return res;
    }
private:
    void findSubs(string& s, vector<vector<string>>& res, vector<string> vstr, int index) {
        if (index == s.size()) {
            res.push_back(vstr);
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            string tmp = s.substr(index, i - index + 1);
            if (isPalindrome(tmp)) {
                vstr.push_back(tmp);
                findSubs(s, res, vstr, i + 1);
                vstr.pop_back();
            }
        }
    }

    bool isPalindrome(string str) {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            if (str[left] != str[right]) {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};