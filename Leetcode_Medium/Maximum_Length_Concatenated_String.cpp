/* You are given an array of strings arr. 
A string s is formed by the concatenation of a subsequence of arr 
that has unique characters.
Return the maximum possible length of s.
A subsequence is an array that can be derived from another array by d
eleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: arr = ["un","iq","ue"]
Output: 4
Explanation: All the valid concatenations are:
- ""
- "un"
- "iq"
- "ue"
- "uniq" ("un" + "iq")
- "ique" ("iq" + "ue")
Maximum length is 4.

Example 2:
Input: arr = ["cha","r","act","ers"]
Output: 6
Explanation: Possible longest valid concatenations are "chaers" ("cha" + "ers") and "acters" ("act" + "ers").

Example 3:
Input: arr = ["abcdefghijklmnopqrstuvwxyz"]
Output: 26
Explanation: The only string in arr has all 26 characters.

Constraints:
1 <= arr.length <= 16
1 <= arr[i].length <= 26
arr[i] contains only lowercase English letters. */

using namespace std;
#include <vector>
#include <bits/stdc++.h>

class Solution {
public:
    int maxLength(vector<string>& arr) {
    vector <bitset<26> > mask = {bitset<26>()};
    int res = 0;
        
    for (int i = 0; i < arr.size(); i++) {
        bitset<26> a;
        for (int j = 0; arr[i][j]; j++)
            a.set(arr[i][j] - 'a');
        int n = a.count();
        if (n < arr[i].size())
            continue;
        for (int i = mask.size() - 1; i >= 0; --i) {
            bitset<26> cet = mask[i];
            if ((cet & a).any())
                continue;
            mask.push_back(cet | a);
            res = max(res, (int)cet.count() + n);
        }
    }
    return res;
    }
 
};