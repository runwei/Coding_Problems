/*
写一个程序，找出 5^1234566789893943的从底位开始的1000位数字。
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;


vector<pair<int,int> > getkclosestpoints(const vector<pair<int,int> > &arr, const pair<int,int> &p,int k) {
	auto shorter=[&] (const pair<int,int> &p1, const pair<int,int> &p2) {
		return (p1.first-p.first)*(p1.first-p.first)+(p1.second-p.second)*(p1.second-p.second)<(p2.first-p.first)*(p2.first-p.first)+(p2.second-p.second)*(p2.second-p.second);
	};
	priority_queue<pair<int,int>, vector<pair<int,int> >, function<bool(const pair<int,int> &,const pair<int,int> &)> > pq{shorter};
	for (int i=0;i<k;i++) pq.push(arr[i]);
	for (int i=k;i<arr.size();i++) {
		if (shorter(arr[i],pq.top())) {
			pq.pop();
			pq.push(arr[i]);
		}
	}
	vector<pair<int,int> > ret;
	while(!pq.empty()) {
		ret.push_back(pq.top());
		pq.pop();
	}
	return ret;
}



	
	
int main() {
	vector<pair<int,int> > arr {{-2, -4}, {0, 0}, {10, 15}, {5, 6}, {7, 8}, {-10, -30}};
	vector<pair<int,int> > ret=getkclosestpoints(arr,{5,5},2);
	for (int i=0;i<2;i++){
		cout<<ret[i].first<<" "<<ret[i].second<<endl;
	} 
	
	// for (int i=1;i<=n;i++)
	// cout<<findksmallest(arr,i)<<endl;
	
	return 0;
}