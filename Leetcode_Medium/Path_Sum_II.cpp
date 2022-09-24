/* Given the root of a binary tree and an integer targetSum, 
return all root-to-leaf paths where the sum of the node 
values in the path equals targetSum. 
Each path should be returned as a list of the node values, 
not node references.

A root-to-leaf path is a path starting from the root 
and ending at any leaf node. A leaf is a node with no children.

Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 22

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: []

Example 3:
Input: root = [1,2], targetSum = 0
Output: [] */

using namespace std;
#include <vector>

// Definition for a binary tree node.
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
    vector<vector<int> > pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > res;
        vector<int> tmp;
        findSum(root, targetSum, tmp, res);
        return (res);
    }
    static void findSum(TreeNode* root, int targetSum, vector<int> &tmp,  vector<vector<int> > &res) {
        if (root == NULL)
            return ;
        if (root->val == targetSum && !root->left && !root->right) {
            tmp.push_back(root->val);
            res.push_back(tmp);
            tmp.pop_back();
            return;
        }
        else {
            tmp.push_back(root->val);
            findSum(root->left, targetSum - root->val, tmp, res);
            findSum(root->right, targetSum - root->val, tmp, res);
            tmp.pop_back();
        }
    }
};