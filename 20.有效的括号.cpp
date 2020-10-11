/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include<unordered_map>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
        {
            return false;
        }
        unordered_map<char, char> right2Left;
        right2Left[']'] = '[';
        right2Left['}'] = '{';
        right2Left[')'] = '(';

        stack<char> seq;

        for (unsigned idx = 0; idx < s.size(); ++idx)
        {
            auto iter = right2Left.find(s[idx]);
            if (iter != right2Left.end())
            {
                if (seq.empty())
                {
                    return false;
                }
                if (seq.top() == iter->second)
                {
                    seq.pop();
                }
                else
                {
                    return false;
                }

            }
            else
            {
                seq.push(s[idx]);
            }

        }
        if (seq.empty())
        {
            return true;
        }
        return false;
    }
};
// @lc code=end
