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

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

struct Interval {
	int start,end,cost;
	Interval (const int start=0,const int end=0,const int cost=0):start(start),end(end),cost(cost) {}
};
int findlastpossible(const vector<Interval> &arr, int i);
int non_overlapingjobs(vector<Interval> &arr) {
	auto f=[](Interval p1, Interval p2) {return p1.end<p2.end;};
	if (arr.empty()) return 0;
	int n=arr.size();
	int value[n]; fill_n(value,n,0);
	sort(arr.begin(),arr.end(),f);
	for (int i=0;i<n;i++) {
		if (i==0) value[0]=arr[0].cost;
		else {
			int ind=findlastpossible(arr,i);
			int lastcost=ind==-1?0:value[ind];
			value[i]=max(value[i-1],lastcost+arr[i].cost);
		}
	}
	return value[n-1];
}

int findlastpossible(const vector<Interval> &arr, int i) {
	if (arr[0].end>arr[i].start) return -1;
	int left=0, right=i;
	while (left+1<right) {
		int mid=(left+right)/2;
		if (arr[mid].end<=arr[i].start) left=mid;
		else right=mid;
	}
	return left;
}


int main() {
	vector<Interval> arr {{1,3,2},{3,4,3},{2,5,4},{4,6,1}};
	cout<<non_overlapingjobs(arr);
	
	return 0;
}