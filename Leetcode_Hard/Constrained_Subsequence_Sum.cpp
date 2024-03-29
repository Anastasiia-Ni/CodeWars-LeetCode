/* Given an integer array nums and an integer k, return the maximum sum of a non-empty subsequence of that array such 
that for every two consecutive integers in the subsequence, nums[i] and nums[j], where i < j, the condition j - i <= k is satisfied.
A subsequence of an array is obtained by deleting some number of elements (can be zero) from the array, 
leaving the remaining elements in their original order.

Example 1:
Input: nums = [10,2,-10,5,20], k = 2
Output: 37
Explanation: The subsequence is [10, 2, 5, 20].

Example 2:
Input: nums = [-1,-2,-3], k = 1
Output: -1
Explanation: The subsequence must be non-empty, so we choose the largest number.

Example 3:
Input: nums = [10,-2,-10,-5,20], k = 2
Output: 23
Explanation: The subsequence is [10, -2, -5, 20].
 
Constraints:
1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104 */

using namespace std;
#include <vector>
#include <deque>

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        int sum = nums[0];
        vector<int> dp(nums.size(), 0);
        deque<int> deq;

        for (int i = 0; i < nums.size(); ++i) {
            if (!deq.empty() && i - deq.front() > k) {
                deq.pop_front();
            }

            if (deq.empty())
                dp[i] = nums[i];
            else
                dp[i] = max(0, dp[deq.front()]) + nums[i];

            while (!deq.empty() && dp[deq.back()] <= dp[i]) 
                deq.pop_back();   
            
            sum = max(sum, dp[i]);
            deq.push_back(i);
        }
        return sum;
    }
};