/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start

#include<stack>

using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        inStack_.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outStack_.empty())
        {
            moveItems();
        }
        int x = outStack_.top();
        outStack_.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (outStack_.empty())
        {
            moveItems();
        }
        return outStack_.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack_.empty() && outStack_.empty();
    }

private:
    void moveItems()
    {
        while (!inStack_.empty())
        {
            outStack_.push(inStack_.top());
            inStack_.pop();
        }
    }

private:
    stack<int> inStack_;
    stack<int> outStack_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
