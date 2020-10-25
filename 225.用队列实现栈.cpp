/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

// @lc code=start
#include<queue>

using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        queue<int> &validQ = first_.empty() ? second_ : first_;
        validQ.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> &emptyQ = first_.empty() ? first_ : second_;
        queue<int> &notEmptyQ = first_.empty() ? second_ : first_;

        while (notEmptyQ.size() > 1)
        {
            emptyQ.push(notEmptyQ.front());
            notEmptyQ.pop();
        }
        int last = notEmptyQ.front();
        notEmptyQ.pop();
        return last;
    }

    /** Get the top element. */
    int top() {
        queue<int> &validQ = first_.empty() ? second_ : first_;
        return validQ.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return first_.empty() && second_.empty();
    }
private:
    queue<int> first_;
    queue<int> second_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
