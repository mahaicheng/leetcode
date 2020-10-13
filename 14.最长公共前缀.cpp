/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
#include <string>
#include <limits>
#include <vector>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (strs.empty())
        {
            return "";
        }
        int maxLen = numeric_limits<int>::max();
        for (const string &str : strs)
        {
            maxLen = std::min(maxLen, static_cast<int>(str.size()));
        }

        string result;
        for (unsigned idx = 0; idx < maxLen; ++idx)
        {
            char c;
            bool isFirst = true;
            bool stop = false;
            for (string &str : strs)
            {
                if (isFirst)
                {
                    c = str[idx];
                    isFirst = false;
                }
                else
                {
                    if (str[idx] != c)
                    {
                        stop = true;
                        break;
                    }
                }
            }
            if (!stop)
            {
                result.push_back(c);
            }
            else
            {
                break;
            }
        }
        return std::move(result);
    }
};
// @lc code=end
