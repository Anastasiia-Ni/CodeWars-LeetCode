/* Given an integer array nums and an integer k, return the number of good subarrays of nums.
A good array is an array where the number of different integers in that array is exactly k.
For example, [1,2,3,1,2] has 3 different integers: 1, 2, and 3.
A subarray is a contiguous part of an array.

Example 1:
Input: nums = [1,2,1,2,3], k = 2
Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

Example 2:
Input: nums = [1,2,1,3,4], k = 3
Output: 3
Explanation: Subarrays formed with exactly 3 different integers: [1,2,1,3], [2,1,3], [1,3,4].
 
Constraints:
1 <= nums.length <= 2 * 104
1 <= nums[i], k <= nums.length */

using namespace std;
#include <vector>
#include <unordered_map>

class Solution {
 public:
  int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map <int, int> freq;
        int res = 0;

        for (int i1 = 0, i2 = 0, j = 0; j < nums.size(); ++j) {
            ++freq[nums[j]];

            while (freq.size() > k) {
                --freq[nums[i2]];
                if (!freq[nums[i2]]) {
                    freq.erase(nums[i2]);
                }
                ++i2;
                i1 = i2;
            }

            while (freq[nums[i2]] > 1) {
                --freq[nums[i2]];
                ++i2;
            }

            if (freq.size() == k) {
                res += (i2 - i1 + 1);
            }
        }

        return res;
    }
};