/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
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
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
        {
            return nullptr;
        }
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
private:
    TreeNode *sortedArrayToBSTHelper(vector<int> &nums, int left, int right)
    {
        int mid = (left + right) / 2;
        TreeNode *root = new TreeNode();
        root->val = nums[mid];
        if (left < mid)
        {
            root->left = sortedArrayToBSTHelper(nums, left, mid - 1);
        }
        if (mid < right)
        {
            root->right = sortedArrayToBSTHelper(nums, mid + 1, right);
        }
        return root;
    }
};
// @lc code=end

