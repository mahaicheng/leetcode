/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include<algorithm>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (unique(nums.begin(), nums.end()) != nums.end())
        {
            return true;
        }
        return false;
    }
};
// @lc code=end

