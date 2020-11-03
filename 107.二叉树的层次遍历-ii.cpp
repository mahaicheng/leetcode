/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
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
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == nullptr)
        {
            return result;
        }
        result.push_back(vector<int>());
        queue<TreeNode *> nodeQ;
        nodeQ.push(root);
        nodeQ.push(nullptr);
        while (!nodeQ.empty())
        {
            TreeNode *node = nodeQ.front();
            nodeQ.pop();

            if (node == nullptr)
            {
                if (!nodeQ.empty())
                {
                    result.push_back(vector<int>());
                    nodeQ.push(nullptr);
                }
                continue;
            }
            result.back().push_back(node->val);
            if (node->left != nullptr)
            {
                nodeQ.push(node->left);
            }
            if (node->right != nullptr)
            {
                nodeQ.push(node->right);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end
