/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        return isPalindrome(to_string(x));
    }
private:
    bool isPalindrome(string &&str)
    {
        unsigned left = 0;
        unsigned right = str.size() - 1;
        while (left < right)
        {
            if (str[left] != str[right])
            {
                return false;
            }
            ++left;
            --right;
        }
        return true;
    };
};
// @lc code=end

