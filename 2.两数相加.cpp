/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode *head = nullptr;
        ListNode *tail = nullptr;
        int remain = 0;
        while (l1 != nullptr && l2 != nullptr)
        {
            int val = l1->val + l2->val + remain;
            ListNode *newNode = new ListNode();
            newNode->val = val % 10;
            remain = val / 10;
            if (head == nullptr)
            {
                head = newNode;
                tail = head;
            }
            else
            {
                tail->next = newNode;
                tail = tail->next;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 != nullptr || l2 != nullptr)
        {
            ListNode *list = (l1 == nullptr) ? l2 : l1;
            while (list != nullptr)
            {
                int val = list->val + remain;
                ListNode *newNode = new ListNode();
                newNode->val = val % 10;
                remain = val / 10;
                tail->next = newNode;
                tail = tail->next;
                
                list = list->next;
            }
        }
        if (remain != 0)
        {
            ListNode *newNode = new ListNode();
            newNode->val = remain;
            tail->next = newNode;
            tail = newNode;
        }
        return head;
    }
};
// @lc code=end
