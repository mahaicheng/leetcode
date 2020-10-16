/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <tuple>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    bool isBalanced(TreeNode *root)
    {
        auto result = isBalancedHelper(root);
        return get<0>(result);
    }

private:
    tuple<bool, int> isBalancedHelper(TreeNode *root)
    {
        if (root == nullptr)
        {
            return make_tuple(true, 0);
        }
        auto leftResult = isBalancedHelper(root->left);
        auto rightResult = isBalancedHelper(root->right);
        if (!get<0>(leftResult) || !get<0>(rightResult))
        {
            return make_tuple(false, -1);
        }
        if (abs(get<1>(leftResult) - get<1>(rightResult)) > 1)
        {
            return make_tuple(false, -1);
        }
        return make_tuple(true, 1 + max(get<1>(leftResult), get<1>(rightResult)));
    }
};
// @lc code=end
