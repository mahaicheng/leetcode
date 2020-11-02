/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 */

// @lc code=start
#include<string>
#include<algorithm>

using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
        if (a.empty())
        {
            return b;
        }
        if (b.empty())
        {
            return a;
        }
        string result;

        int aIdx = a.size() - 1;
        int bIdx = b.size() - 1;
        int remain = 0;
        while (aIdx >= 0 || bIdx >= 0)
        {
            char aChar = aIdx >= 0 ? a[aIdx] : '0';
            char bChar = bIdx >= 0 ? b[bIdx] : '0';
            int sum = aChar - '0' + bChar - '0' + remain;
            result.push_back(sum % 2 + '0');
            remain = sum / 2;
            --aIdx;
            --bIdx;
        }
        if (remain > 0)
        {
            result.push_back(remain + '0');
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
// @lc code=end

