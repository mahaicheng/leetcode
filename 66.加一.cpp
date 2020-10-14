/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;
        int last = 0;
        bool isFirst = true;
        for (auto iter = digits.crbegin(); iter != digits.crend(); ++iter)
        {
            int sum = last + (*iter);
            if (isFirst)
            {
                sum += 1;
                isFirst = false;
            }
            result.push_back(sum % 10);
            last = sum / 10;
        }
        if (last > 0)
        {
            result.push_back(last);
        }
        reverse(result.begin(), result.end());
        return std::move(result);
    }
};
// @lc code=end

