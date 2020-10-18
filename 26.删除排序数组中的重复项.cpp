/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

// @lc code=start
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int actLen = 0;
        for (unsigned right = 0; right < nums.size(); ++right)
        {
            if (nums[actLen] != nums[right])
            {
                nums[++actLen] = nums[right];
            }
        }
        return actLen+1;
    }
};
// @lc code=end
