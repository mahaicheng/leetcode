/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
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
#include<queue>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> results;
        queue<TreeNode*> up, down;
        if (root == nullptr)
        {
            return results;
        }
        up.push(root);
        while (!up.empty() || !down.empty())
        {
            queue<TreeNode*> &currQ = up.empty() ? down : up;
            queue<TreeNode*> &nextQ = up.empty() ? up : down;
            results.push_back(vector<int>());

            while (!currQ.empty())
            {
                TreeNode *cur = currQ.front();
                currQ.pop();
                results.back().push_back(cur->val);
                if (cur->left != nullptr)
                {
                    nextQ.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    nextQ.push(cur->right);
                }
            }
        }
        return results;
    }
};
// @lc code=end

