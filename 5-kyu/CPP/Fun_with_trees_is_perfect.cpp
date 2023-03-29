/* A perfect binary tree is a binary tree in which all interior nodes have two children
    and all leaves have the same depth or same level.

    You are given a class called TreeNode. Implement the method isPerfect which determines
    if a given tree denoted by its root node is perfect.

    Note: TreeNode class contains helper methods for tree creation,
    which might be handy for your solution.
    Feel free to update those methods, but make sure you keep their signatures intact
    (since they are used from within test cases) */

#include <string.h>

class TreeNode
{
public:
    static bool isPerfect(TreeNode *root)
    {
        if (!root)
            return (true);
        if (countChildren(root->left) != countChildren(root->right))
            return false;
        return isPerfect(root->left) && isPerfect(root->right);
    }

    static int countChildren(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + countChildren(root->right) + countChildren(root->left);
    }

    static TreeNode *leaf()
    {
        return new TreeNode();
    }

    static TreeNode *join(TreeNode *left, TreeNode *right)
    {
        return (new TreeNode())->withChildren(left, right);
    }

    TreeNode *withLeft(TreeNode *left)
    {
        this->left = left;
        return this;
    }

    TreeNode *withRight(TreeNode *right)
    {
        this->right = right;
        return this;
    }

    TreeNode *withChildren(TreeNode *left, TreeNode *right)
    {
        this->left = left;
        this->right = right;
        return this;
    }

    TreeNode *withLeftLeaf()
    {
        return withLeft(leaf());
    }

    TreeNode *withRightLeaf()
    {
        return withRight(leaf());
    }

    TreeNode *withLeaves()
    {
        return withChildren(leaf(), leaf());
    }

private:
    TreeNode *left;
    TreeNode *right;

    TreeNode()
        : left(NULL), right(NULL)
    {
    }
};