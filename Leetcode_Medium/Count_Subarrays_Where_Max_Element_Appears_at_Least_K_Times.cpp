/* You are given an integer array nums and a positive integer k.
Return the number of subarrays where the maximum element of nums appears at least k times in that subarray.
A subarray is a contiguous sequence of elements within an array.

Example 1:
Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].

Example 2:
Input: nums = [1,4,2,1], k = 3
Output: 0
Explanation: No subarray contains the element 4 at least 3 times.
 
Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 106
1 <= k <= 105
*/

using namespace std;
#include <vector>

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_el = *max_element(nums.begin(), nums.end());
        long long res = 0;
        int count = 0;
        int len = nums.size();

        for (int i = 0, j = 0; j < len; j++) {
            if (nums[j] == max_el) {
                count++;
            }
            while (count >= k && i <= j) {
                if (nums[i] == max_el) {
                    count--;
                }
                res += (len - j);
                i++;
            }

        }
        return res;
    }
};