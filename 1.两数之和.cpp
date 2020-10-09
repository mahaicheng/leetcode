/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <vector>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num2Idx;
        for (int idx = 0; idx < nums.size(); ++idx)
        {
            auto iter = num2Idx.find(target - nums[idx]);
            if (iter != num2Idx.end())
            {
                return vector<int>{iter->second, idx};
            }
            num2Idx[nums[idx]] = idx;
        }
        return vector<int>();
    }
};
// @lc code=end

