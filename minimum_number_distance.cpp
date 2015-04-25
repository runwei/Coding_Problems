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

int minimum_number_distance(int a[],int n, int num1, int num2) {
	int pos1=-1, pos2=-1, mindist=INT_MAX;
	for (int i=0;i<n;i++){
		if (a[i]==num1) {
			pos1=i;
			if (pos2!=-1) mindist=min(mindist,pos1-pos2);
		} else if (a[i]==num2) {
			pos2=i;
			if (pos1!=-1) mindist=min(mindist,pos2-pos1);
		}
	}
	return mindist;
}

int main() {
	int a[] {2,5,3,5,4,4,2,3};
	cout<<minimum_number_distance(a,8,2,3);
	
	return 0;
}

