/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
#include<string>
#include<limits>
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        while (x != 0)
        {
            result = result * 10 + x % 10;
            x /= 10;
        }

        if (result > INT_MAX || result < INT_MIN)
        {
            return 0;
        }
        return result;
    }
};
// @lc code=end

