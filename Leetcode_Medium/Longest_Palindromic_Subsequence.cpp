/* Given a string s, find the longest palindromic subsequence's length in s.
A subsequence is a sequence that can be derived from another sequence by
deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: s = "bbbab"
Output: 4
Explanation: One possible longest palindromic subsequence is "bbbb".

Example 2:
Input: s = "cbbd"
Output: 2
Explanation: One possible longest palindromic subsequence is "bb".

Constraints:
1 <= s.length <= 1000
s consists only of lowercase English letters. */

using namespace std;
#include <string>
#include <vector>

class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        int len = s.size();
        vector<vector<int>> mp(len, vector<int>(len));

        for (int i = len - 1; i >= 0; i--)
        {
            mp[i][i] = 1;
            for (int j = i + 1; j < len; j++)
            {
                if (s[i] == s[j])
                    mp[i][j] = mp[i + 1][j - 1] + 2;
                else
                    mp[i][j] = max(mp[i + 1][j], mp[i][j - 1]);
            }
        }
        return mp[0][len - 1];
    }
};