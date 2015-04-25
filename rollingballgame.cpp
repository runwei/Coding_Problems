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

bool rollingballgame(const vector<vector<int> > &arr) {
	if (arr.empty() || arr[0].empty()) return false;
	int m=arr.size(); int n=arr[0].size();
	unordered_set<int> visited;
	queue<pair<int,int> > q;
	q.push({0,0});visited.insert(0);
	
	while (!q.empty()) {
		int x1=q.front().first;
		int x2=q.front().second;
		q.pop();
		if (x1==m-1 && x2==n-1) return true;
		int left=x2,right=x2, up=x1, down=x1;
		while(left-1>=0 && !arr[x1][left-1]) --left;
		while(right+1<n && !arr[x1][right+1]) ++right;
		while(down-1>=0 && !arr[down-1][x2]) --down;
		while(up+1<m && !arr[up+1][x2]) ++up;
		if (left!=x2 && !visited.count(x1*n+left)) {
			visited.insert(x1*n+left); q.push({x1,left});
		}
		if (right!=x2 && !visited.count(x1*n+right)) {
			visited.insert(x1*n+right); q.push({x1,right});
		}
		if (down!=x1 && !visited.count(down*n+x2)) {
			visited.insert(down*n+x2); q.push({down,x2});
		}
		if (up!=x1 && !visited.count(up*n+x2)) {
			visited.insert(up*n+x2); q.push({up,x2});
		}
	}
	return false;
}


int main() {
	vector<vector<int> >arr {{0,0,0,1},{1,0,0,1},{1,0,0,0}};
	cout<<rollingballgame(arr);
	
	return 0;
}

