/*
Given a set of n jobs with [start time, end time, cost] find a subset so that no 2 jobs overlap and the cost is maximum.
DP+二分:
Sort the intervals based on end time
define p(i) for each interval, giving the biggest end point which is smaller than the start point of i-th interval. Use binary search to obtain nlogn
define d[i] = max(w(i) + d[p(i)], d[i-1]).

initialize d[0] = 0
The result will be in d[n] n- the number of intervals.
Overall complexity O(nlogn)
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

template <typename T>class block_queue {
    condition_variable _cond;
    mutex _mutex;
    std::queue<T> _data;
    public:
    void push(const T& value) {
        unique_lock<mutex> l(_mutex);
        _data.push(value);
        _cond.notify_one();
    }
   
    T pop() {
        unique_lock<mutex> l(_mutex);
        _cond.wait(l, [&](){ return !_data.empty(); });
        auto item = _data.front();
        _data.pop();
        return item;
    }
};
int main() {
    block_queue<int> q;
    int itemNum = 10;
   
    thread pro([&]{
        for(int i = 0; i < itemNum; ++i) {
            q.push(i);
            printf("push:%d\n",i);
        }
    });
    thread cus([&]{
        for(int i = 0; i < itemNum; ++i) {
            int n = q.pop();
            printf("pop:%d\n",n);
        }
    });
   
    cus.join();
    pro.join();
    return 0;
}

