/* Given the root of a binary search tree, return a balanced binary search tree with the same node values. 
If there is more than one answer, return any of them.

A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

Example 1:
Input: root = [1,null,2,null,3,null,4,null,null]
Output: [2,1,3,null,null,null,4]
Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

Example 2:
Input: root = [2,1,3]
Output: [2,1,3]
 
Constraints:
The number of nodes in the tree is in the range [1, 104].
1 <= Node.val <= 10**5 */

using namespace std;
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> nums;
    TreeNode* balanceBST(TreeNode* root) {
        fillVector(root);
        sort(nums.begin(), nums.end());
        return buildBST(0, nums.size() - 1);
    }

    void fillVector(TreeNode* root) {
        if (!root) {
            return;
        }
        nums.push_back(root->val);
        fillVector(root->left);
        fillVector(root->right);
    }

    TreeNode* buildBST(int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* node = new TreeNode(nums[mid]);

        node->left = buildBST(start, mid - 1);
        node->right = buildBST(mid + 1, end);

        return node;
    }
};