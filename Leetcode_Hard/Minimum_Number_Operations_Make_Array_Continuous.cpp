/* You are given an integer array nums. In one operation, you can replace any element in nums with any integer.
nums is considered continuous if both of the following conditions are fulfilled:
All elements in nums are unique.
The difference between the maximum element and the minimum element in nums equals nums.length - 1.
For example, nums = [4, 2, 5, 3] is continuous, but nums = [1, 2, 3, 5, 6] is not continuous.
Return the minimum number of operations to make nums continuous.

Example 1:
Input: nums = [4,2,5,3]
Output: 0
Explanation: nums is already continuous.

Example 2:
Input: nums = [1,2,3,5,6]
Output: 1
Explanation: One possible solution is to change the last element to 4.
The resulting array is [1,2,3,5,4], which is continuous.

Example 3:
Input: nums = [1,10,100,1000]
Output: 3
Explanation: One possible solution is to:
- Change the second element to 2.
- Change the third element to 3.
- Change the fourth element to 4.
The resulting array is [1,2,3,4], which is continuous.
 
Constraints:
1 <= nums.length <= 105
1 <= nums[i] <= 109 */

using namespace std;
#include <vector>

class Solution {
public:
    int minOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len1 = nums.size();
        int res = len1;

        for (int i = 1; i < nums.size();) {
            if (nums[i - 1] == nums[i])
                nums.erase(nums.begin() + i);
            else
                i++;
        }

        int len2 = nums.size();
        for (int i = 0, j = 0; i < len2; i++) {
            while (j < len2 && nums[j] - nums[i] <= len1 - 1)
                j++;
            res = min(res, len1 - (j - i));
        }

        return res;
    }
};