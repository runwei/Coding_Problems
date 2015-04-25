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

mutex m;
condition_variable c;
bool isodd=true;

thread odd([&](){
	for (int i=1;i<10;i+=2) {
		unique_lock<mutex>l(m);
		c.wait(l,[&](){return isodd;});
		cout<<i<<endl;
		isodd=!isodd;
		l.unlock();
		c.notify_one();
	}
});

thread even([&](){
	for (int i=2;i<=10;i+=2) {
		unique_lock<mutex> l(m);
		c.wait(l,[&](){return !isodd;});
		cout<<i<<endl;
		isodd=!isodd;
		l.unlock();
		c.notify_one();
	}
});

int main() {
	odd.join();
	even.join();
	// vector<int> arr {1,4,6,8};
	// vector<int> ret=findmissingnum(arr,4);
	// for (auto &num:ret) cout<<num;
	return 0;
}

