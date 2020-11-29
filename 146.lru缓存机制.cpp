/*
 * @lc app=leetcode.cn id=146 lang=cpp
 *
 * [146] LRU缓存机制
 */

// @lc code=start
#include <unordered_map>
#include <list>

using namespace std;

class LRUCache
{
public:
    LRUCache(int capacity) : capacity_(capacity)
    {
    }

    int get(int key)
    {
        auto iter = key2Iter_.find(key);
        if (iter == key2Iter_.end())
        {
            return -1;
        }
        int result = iter->second->second;
        put(key, result);
        return result;
    }

    void put(int key, int value)
    {
        auto node = make_pair(key, value);
        auto findIter = key2Iter_.find(key);
        if (findIter == key2Iter_.end())
        {
            if (valueList_.size() == capacity_)
            {
                auto iter = valueList_.begin();
                int delKey = iter->first;
                key2Iter_.erase(delKey);
                valueList_.erase(iter);
            }
        }
        else
        {
            valueList_.erase(findIter->second);
        }
        key2Iter_[key] = valueList_.insert(valueList_.end(), node);
    }

private:
    int capacity_;
    unordered_map<int, list<pair<int, int>>::const_iterator> key2Iter_;
    list<pair<int, int>> valueList_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
