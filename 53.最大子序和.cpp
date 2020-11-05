/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子序和
 */

// @lc code=start
#include<vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty())
        {
            return 0;
        }
        int left = 0;
        int sum = 0;
        int maxSum = INT_MIN;
        for (unsigned idx = 0; idx < nums.size(); ++idx)
        {
            sum += nums[idx];
            maxSum = max(sum, maxSum);
            if (sum <= 0)
            {
                while (left <= idx && sum <=0)
                {
                    sum -= nums[left++];
                }
            }
        }
        return maxSum;
    }
};
// @lc code=end

