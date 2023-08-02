/* Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
 
Constraints:
1 <= nums.length <= 6
-10 <= nums[i] <= 10
All the integers of nums are unique.*/

using namespace std;
#include <vector>

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> tmp;

        dfs(result, tmp, nums);
        return result;
    }

    void dfs(vector<vector<int>> &result, vector<int> &tmp, vector<int>& nums) {
        if (tmp.size() == nums.size()) {
            result.push_back(tmp);
            return ;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (find(tmp.begin(), tmp.end(), nums[i]) == tmp.end()) {
                tmp.push_back(nums[i]);
                dfs(result, tmp, nums);
                tmp.pop_back();
            }
        }
    }
};