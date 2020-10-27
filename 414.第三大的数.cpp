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
        sortedSet_.insert(nums.cbegin(), nums.cend());
        if (sortedSet_.size() < 3)
        {
            return *sortedSet_.crbegin();
        }
        auto begin = sortedSet_.crbegin();
        advance(begin, 2);
        return *begin;
    }
private:
    set<int> sortedSet_;
};
// @lc code=end
