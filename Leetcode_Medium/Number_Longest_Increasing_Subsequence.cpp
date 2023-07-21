/* Given an integer array nums, return the number of longest increasing subsequences.
Notice that the sequence has to be strictly increasing.

Example 1:
Input: nums = [1,3,5,4,7]
Output: 2
Explanation: The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].

Example 2:
Input: nums = [2,2,2,2,2]
Output: 5
Explanation: The length of the longest increasing subsequence is 1, 
and there are 5 increasing subsequences of length 1, so output 5.
 
Constraints:
1 <= nums.length <= 2000
-106 <= nums[i] <= 106 */

using namespace std;
#include <vector>

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int res = 0;
        int len_max = 0;
        int len = nums.size();
        vector<int> lengths(len, 1);
        vector<int> count(len, 1);

        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    if (lengths[i] < lengths[j] + 1) {
                        lengths[i] = lengths[j] + 1;
                        count[i] = count[j];
                    }
                    else if (lengths[i] == lengths[j] + 1) {
                        count[i] += count[j];
                    }
                }
            }
        }

        for (int i = 0; i < len; ++i) {
            len_max = max(len_max, lengths[i]);
        }
        
        for (int i = 0; i < len; ++i) {
            if (lengths[i] == len_max) {
                res += count[i];
            }
        }
        return res;
    }
};