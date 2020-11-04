/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 外观数列
 */

// @lc code=start
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
        {
            return "1";
        }
        string desc = countAndSay(n - 1);
        vector<string> group;
        char c = '\0';
        for (char i : desc)
        {
            if (c != i)
            {
                group.push_back(string());
            }
            group.back().push_back(i);
            c = i;
        }
        string result;
        for (string g : group)
        {
            result.push_back(g.size() + '0');
            result.push_back(g.front());
        }
        return result;
    }
};
// @lc code=end
