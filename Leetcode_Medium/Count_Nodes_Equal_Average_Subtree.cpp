/* Given the root of a binary tree, return the number of nodes where the value
of the node is equal to the average of the values in its subtree.
Note:
The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
A subtree of root is a tree consisting of root and all of its descendants.

Example 1:
Input: root = [4,8,5,0,1,null,6]
Output: 5
Explanation: 
For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
For the node with value 0: The average of its subtree is 0 / 1 = 0.
For the node with value 1: The average of its subtree is 1 / 1 = 1.
For the node with value 6: The average of its subtree is 6 / 1 = 6.

Example 2:
Input: root = [1]
Output: 1
Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.
 
Constraits:
The number of nodes in the tree is in the range [1, 1000].
0 <= Node.val <= 1000*/

using namespace std;
#include <map>

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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        if (root) {
            avarage(root, ans);
        }
        return ans;
    }

    pair<int, int> avarage(TreeNode* root, int &ans) {
        if (!root)
            return {0, 0};

        pair<int, int> left_tree = avarage(root->left, ans);
        pair<int, int> right_tree = avarage(root->right, ans);

        int sum = left_tree.first + right_tree.first + root->val;
        int count = left_tree.second + right_tree.second + 1;

        ans += (sum / count == root->val);      
        
        return {sum, count};
    }
};