/* Given an integer n, return a list of all possible full binary trees with n nodes. 
Each node of each tree in the answer must have Node.val == 0.
Each element of the answer is the root node of one possible tree. 
You may return the final list of trees in any order.
A full binary tree is a binary tree where each node has exactly 0 or 2 children.

Example 1:
Input: n = 7
Output: [[0,0,0,null,null,0,0,null,null,0,0],[0,0,0,null,null,0,0,0,0],[0,0,0,0,0,0,0],[0,0,0,0,0,null,null,null,null,0,0],[0,0,0,0,0,null,null,0,0]]

Example 2:
Input: n = 3
Output: [[0,0,0]]
 
Constraints:
1 <= n <= 20 */

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
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> result;

        if (n % 2 == 0)
            return {};

        if (n == 1)
            return {new TreeNode(0)};
            
        for (int i = 1; i < n; i += 2) {
            vector<TreeNode*> left_tree = allPossibleFBT (n - 1 - i);
            vector<TreeNode*> right_tree = allPossibleFBT (i);
            for (auto itl = left_tree.begin(); itl != left_tree.end(); ++itl) {
                for (auto itr = right_tree.begin(); itr != right_tree.end(); ++itr) {
                    TreeNode *root = {new TreeNode(0)};
                    root->left = *itl;
                    root->right = *itr;
                    result.push_back(root);
                }
            }
        }
        return result;
    }
};