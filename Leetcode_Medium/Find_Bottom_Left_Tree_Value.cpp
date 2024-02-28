/* Given the root of a binary tree, return the leftmost value in the last row of the tree.
*/

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
    int findBottomLeftValue(TreeNode* root) {
        if (!root)
            return 0;
        vector<vector<int>> sn;
        int depth = 0;
        fillVector(root, sn, depth);
        return sn[sn.size() - 1][0];
    }

    void fillVector(TreeNode* root, vector<vector<int>>& sn, int depth) {
        if (!root)
            return;
        if (sn.size() <= depth) {
            sn.push_back({});
        }
        sn[depth].push_back(root->val);
        fillVector(root->left, sn, depth + 1);
        fillVector(root->right, sn, depth + 1);
    }
};