/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

// @lc code=start
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        if (nums_.find(n) != nums_.end())
        {
            return false;
        }

        int orig = n;
        long result = 0;
        while (n > 0)
        {
            long tmp = n % 10;
            n = n / 10;
            result += tmp * tmp;
        }
        if (result == 1)
        {
            return true;
        }
        nums_.insert(orig);
        return isHappy(result);
    }

private:
    unordered_set<int> nums_;
};
// @lc code=end
