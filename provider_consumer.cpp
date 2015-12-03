/*
http://www.fgdsb.com/2015/01/03/provider--consumer/
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

