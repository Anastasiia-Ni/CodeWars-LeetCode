/* Given a binary tree root, a node X in the tree is named good if in the 
path from root to X there are no nodes with a value greater than X.

Return the number of good nodes in the binary tree.

Input: root = [3,1,4,3,null,1,5]
Output: 4
Explanation: Nodes in blue are good.
Root Node (3) is always a good node.
Node 4 -> (3,4) is the maximum value in the path starting from the root.
Node 5 -> (3,4,5) is the maximum value in the path
Node 3 -> (3,1,3) is the maximum value in the path.

The number of nodes in the binary tree is in the range [1, 10^5].
Each node's value is between [-10^4, 10^4]. */


 /*Definition for a binary tree node.*/

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
    int goodNodes(TreeNode* root) {
        if (root == nullptr)
        return (countNodes(root, root->val));
    }
    
    int countNodes(TreeNode* root, int value) {
        if (root == nullptr)
            return (0);
        int max = (value >= root->val) ? value : root->val;
        return ((root->val >= value) + countNodes(root->left, max) + countNodes(root->right, max));
    }
};
