/*
 * @lc app=leetcode.cn id=414 lang=cpp
 *
 * [414] 第三大的数
 */

// @lc code=start
#include <vector>
#include <set>

using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        long long m1 = -3e9, m2 = -3e9, m3 = -3e9;
        for (auto x : nums)
        {
            if (x == m1 || x == m2 || x == m3)
                continue;
            if (x > m1)
            {
                m3 = m2;
                m2 = m1;
                m1 = x;
            }
            else if (x > m2)
            {
                m3 = m2;
                m2 = x;
            }
            else if (x > m3)
                m3 = x;
        }
        if (m3 == -3e9)
            return m1;
        return m3;
    }
};
// @lc code=end
