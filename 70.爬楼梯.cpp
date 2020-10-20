/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n < 0)
        {
            return 0;
        }
        if (n <= 2)
        {
            return n;
        }

        long result = -1;
        auto iter = resultCache_.find(n);
        if (iter != resultCache_.end())
        {
            result = iter->second;
        }
        else
        {
            result = climbStairs(n - 1) + climbStairs(n - 2);
            resultCache_[n] = result;
        }
        return result;
    }

private:
    unordered_map<int, long> resultCache_;
};
// @lc code=end
