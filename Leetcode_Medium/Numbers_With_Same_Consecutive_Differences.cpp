/* Return all non-negative integers of length n such that 
the absolute difference between every two consecutive digits is k.

Note that every number in the answer must not have leading zeros. 
For example, 01 has one leading zero and is invalid.

You may return the answer in any order.

Example 1:
Input: n = 3, k = 7
Output: [181,292,707,818,929]
Explanation: Note that 070 is not a valid number, because it has leading zeroes.

Example 2:
Input: n = 2, k = 1
Output: [10,12,21,23,32,34,43,45,54,56,65,67,76,78,87,89,98]

Constraints:
2 <= n <= 9
0 <= k <= 9 */

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for (int i = 0; i < 10; i++) {
            std::string s;
            s += i + '0';
            recurcDiff(n, k, s, res);          
        }
        for (vector<int>::iterator it = res.begin(); it != res.end();) {
            int len = *it > 0 ? log10(*it) + 1 : 1;
            if (len < n)
                res.erase(it);
            else
                ++it;
        }
        return (res);
    }
    void recurcDiff(int n, int k, std::string &s, vector<int> &res)
    {
        if (s.size() == n) {
            res.push_back(stoi(s));
            return ;
        }
        char tmp1 = s.back() + k;
        char tmp2 = s.back() - k;
        if (tmp1 >= '0' && tmp1 <= '9') {
            s += tmp1;
            recurcDiff(n, k, s, res);
            s.pop_back();
        }
        if (tmp1 != tmp2 && tmp2 >= '0' && tmp2 <= '9') {
            s += tmp2;
            recurcDiff(n, k, s, res);
            s.pop_back();
        }
    }
};