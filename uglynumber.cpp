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
#include<unordered_map>
#include<unordered_set>

#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

int uglynumber(int n) {
	int num[n],pos1=0,pos2=0,pos3=0,pos=0;
	num[0]=1;
	for (int i=1;i<n;i++) {
		int num2=num[pos1]*2;
		int num3=num[pos2]*3;
		int num5=num[pos3]*5;
		int bestnum=min(min(num2,num3),num5);
		num[++pos]=bestnum;
		if (bestnum==num2) ++pos1;
		if (bestnum==num3) ++pos2;
		if (bestnum==num5) ++pos3;
	}
	return num[n-1];
}

int main() {
	cout<<uglynumber(11);
	return 0;
}

