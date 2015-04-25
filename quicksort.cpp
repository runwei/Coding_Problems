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

void quicksort(vector<int> &arr) {
	auto partition=[&](int s, int e) {
		int pos=s;
		for (int i=s;i<e;i++) 
			if (arr[i]<=arr[e]) 
				swap(arr[i],arr[pos++]);
		swap(arr[e],arr[pos]);
		return pos;
	};
	function<void(int,int)> quicksorthelper=[&](int start, int end) {
		if (start<end){
			int ind=partition(start,end);
			quicksorthelper(start,ind-1);
			quicksorthelper(ind+1,end);
		}
	};

	quicksorthelper(0,arr.size()-1);
}


int main() {
	vector<int> arr {3,1,23,4,8,0,2,5};
	quicksort(arr);
	for (auto &num:arr) cout<<num<<" ";
}

