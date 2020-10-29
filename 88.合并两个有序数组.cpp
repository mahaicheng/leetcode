/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int p1 = m - 1;
        int p2 = n - 1;
        int dst = m + n - 1;
        while (p1 >= 0 && p2 >= 0)
        {
            nums1[dst--] = (nums1[p1] > nums2[p2]) ? nums1[p1--] : nums2[p2--];
        }

        while (p2 >= 0)
        {
            nums1[dst--] = nums2[p2--];
        }
    }
};
// @lc code=end
