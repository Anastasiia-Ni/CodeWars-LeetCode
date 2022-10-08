/* Given an integer array nums of length n and an integer target, 
find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 
Constraints:
3 <= nums.length <= 1000
-1000 <= nums[i] <= 1000
-104 <= target <= 104 */

using namespace std;
#include <vector>

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3)
            return 0;
        sort(nums.begin(), nums.end());
        int sum = nums[0] + nums[1] + nums[2];
        for (int f = 0; f < nums.size() - 2; f++) {
            if (f > 0 && nums[f] == nums[f - 1])
                continue;
            int s = f + 1;
            int t = nums.size() - 1;
            while (s < t) {
                int tmp = nums[f] + nums[s] + nums[t];
                if (tmp == target)
                    return tmp;
                if (abs(target - tmp) < abs(target - sum))
                    sum = tmp;
                if (tmp > target)
                    t--;
                else
                    s++;
            }
        }        
        return sum;
    }
};