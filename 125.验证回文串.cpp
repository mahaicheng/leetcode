/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
#include <string>

using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {
        if (s.empty())
        {
            return true;
        }
        int left = 0;
        int right = s.size() - 1;
        while (left < right)
        {
            while (!isalnum(s[left]) && left < right)
            {
                ++left;
            }
            while (!isalnum(s[right]) && left < right)
            {
                --right;
            }

            if (tolower(s[left]) != tolower(s[right]))
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    }
};
// @lc code=end
