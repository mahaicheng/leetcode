/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if (head == nullptr)
        {
            return head;
        }
        if (head->val == val)
        {
            ListNode *old = head;
            head = head->next;
            delete old;
            head = removeElements(head, val);
        }
        else
        {
            head->next = removeElements(head->next, val);
        }
        return head;
    }
};
// @lc code=end
