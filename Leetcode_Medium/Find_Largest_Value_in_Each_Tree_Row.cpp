/* Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: [1,3,9]

Example 2:
Input: root = [1,2,3]
Output: [1,3]
 
Constraints:
The number of nodes in the tree will be in the range [0, 104].
-231 <= Node.val <= 231 - 1 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

using namespace std;
#include <vector>

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        addValue(root, res, 0);
        return res;
    }

    void addValue(TreeNode* root, vector<int> &res, int d) {
        if (!root)
            return;
    
        if (d == res.size())
            res.push_back(root->val);
        else
            res[d] = max(res[d], root->val);

        addValue(root->left, res, d + 1);
        addValue(root->right, res, d + 1);
    }
};