/* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:
Input: nums = [3,2,3]
Output: [3]

Example 2:
Input: nums = [1]
Output: [1]

Example 3:
Input: nums = [1,2]
Output: [1,2]
 
Constraints:
1 <= nums.length <= 5 * 104
-109 <= nums[i] <= 109
 
Follow up: Could you solve the problem in linear time and in O(1) space? */

using namespace std;
#include <vector>

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ap = nums.size() / 3;
        vector<int> res;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            int nb = nums[i];
            int count = 0;
            while ((i + 1) < nums.size() && nb == nums[i + 1]) {
                count++;
                i++;
            }
            if (count >= ap)
                res.push_back(nums[i]);
        }
        return res;
    }
};