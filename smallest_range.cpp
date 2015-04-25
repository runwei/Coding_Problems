/*
You have k lists of sorted integers. Find the smallest range that includes at least one number from each of the k lists.

For example,
List 1: [4, 10, 15, 24, 26]
List 2: [0, 9, 12, 20]
List 3: [5, 18, 22, 30]

The smallest range here would be [20, 24] as it contains 24 from list 1, 20 from list 2, and 22 from list 3.
*/


#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
using namespace std;


pair<int,int> min_range(const vector<vector<int>>& nums) {
	int n=nums.size();
	if (n==0) return {-1,-1};
	using _pair = pair<int,int>;//vecid,pos
	priority_queue<_pair,vector<_pair>, function<bool(_pair &,_pair &)> > heap {
		[&] (_pair& a, _pair& b) {return nums[a.first][a.second]>nums[b.first][b.second];}
	};
	int maxnum=INT_MIN;
	int range=INT_MAX;
	_pair ret{INT_MAX,INT_MIN};
	for (int i=0;i<n;i++) {
		if (!nums[i].empty()) {heap.push({i,0});maxnum=max(maxnum,nums[i][0]);}
		else return {-1,-1};
	}
	while (heap.size()==n) {
		_pair tp=heap.top();
		heap.pop();
		if (maxnum-nums[tp.first][tp.second]<range) {
			ret.first=nums[tp.first][tp.second];
			ret.second=maxnum;
			range=ret.second-ret.first;
		}
		if (tp.second+1<nums[tp.first].size()) {
			heap.push({tp.first,tp.second+1});
			maxnum=max(maxnum,nums[tp.first][tp.second+1]);
		}
	}
	return ret;
}

int main(){
	vector<vector<int> > A{{4,10,15,24,26}, {0,9,12,20}, {5,18,22,30}};
	pair<int,int> ret=min_range(A);
	cout<<ret.first<<" "<<ret.second<<endl;
	return 0;
}