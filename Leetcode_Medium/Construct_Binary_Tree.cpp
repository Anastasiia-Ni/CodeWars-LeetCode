/* Given two integer arrays inorder and postorder where inorder is the inorder 
traversal of a binary tree and postorder is the postorder traversal of the same tree, 
construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
Output: [-1]
 
Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree. */

using namespace std;
#include <vector>
#include <unordered_map>

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();       
        if (len == 0) 
            return nullptr;
        
        unordered_map<int, int> my_map;
        int ip = len - 1;
        for (int i = 0; i < len; i++)
            my_map[inorder[i]] = i;

        return buildT(0, len - 1, postorder, ip, my_map);
    }

    TreeNode* buildT(int start, int end, vector<int> const &postorder, int &ip, unordered_map<int, int> &my_map) {
        if (start > end)
            return nullptr;
        TreeNode* root = new TreeNode(postorder[ip--]);

        int i = my_map[root->val];
        root->right = buildT(i + 1, end, postorder, ip, my_map);
        root->left = buildT(start, i - 1, postorder, ip, my_map);

        return root;
    }
};