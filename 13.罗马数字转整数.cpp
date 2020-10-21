/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
#include <unordered_map>

using namespace std;

class Solution
{
public:
    Solution()
    {
        char2Num_['I'] = 1;
        char2Num_['V'] = 5;
        char2Num_['X'] = 10;
        char2Num_['L'] = 50;
        char2Num_['C'] = 100;
        char2Num_['D'] = 500;
        char2Num_['M'] = 1000;
    }
    int romanToInt(string s)
    {
        int result = 0;
        for (unsigned idx = 0; idx < s.size(); ++idx)
        {
            if (idx < s.size() - 1 && char2Num_[s[idx]] < char2Num_[s[idx + 1]])
            {
                result -= char2Num_[s[idx]];
            }
            else
            {
                result += char2Num_[s[idx]];
            }
        }
        return result;
    }

private:
    unordered_map<char, int> char2Num_;
};
// @lc code=end
