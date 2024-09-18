/* Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"
 
Constraints:
1 <= nums.length <= 100
0 <= nums[i] <= 10**9 */

using namespace std;
#include <vector>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> nums_string(nums.size());

        for (int i = 0; i < nums.size(); ++i) {
            nums_string[i] = to_string(nums[i]);
        }

        sort(nums_string.begin(), nums_string.end(), [](string s1, string s2){ return s2 + s1 < s1 + s2;});
        string res = "";
        for (const string &s : nums_string) {
            res += s;
        }
        return res.find_first_not_of('0') == std::string::npos ? "0" : res;
    }
};