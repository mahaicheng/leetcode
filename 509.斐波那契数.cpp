/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include<unordered_map>

using namespace std;

class Solution {
public:
    int fib(int N) {
        if (N == 0 || N == 1)
        {
            return N;
        }
        auto iter = resultCache_.find(N);
        if (iter != resultCache_.end())
        {
            return iter->second;
        }
        long long result = fib(N -1) + fib(N - 2);
        resultCache_[N] = result;
        return result;
    }
private:
    unordered_map<int, long long> resultCache_;
};
// @lc code=end

