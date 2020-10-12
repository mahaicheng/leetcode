/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <limits>

using namespace std;

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValidBSTHelper(root, numeric_limits<long>::min(), numeric_limits<long>::max());
    }
private:
    bool isValidBSTHelper(TreeNode *root, const long min, const long max)
    {
        if (root == nullptr)
        {
            return true;
        }
        if (root->val <= min || root->val >= max)
        {
            return false;
        }
        return isValidBSTHelper(root->left, min, root->val) && isValidBSTHelper(root->right, root->val, max);
    }
};
// @lc code=end

