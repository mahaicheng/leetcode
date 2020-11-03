/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int cadidate;
        int count = 0;
        for (const int &n : nums)
        {
            if (n == cadidate)
            {
                ++count;
            }
            else
            {
                --count;
                if (count <= 0)
                {
                    cadidate = n;
                    count = 1;
                }
            }
        }
        return cadidate;
    }
};
// @lc code=end
