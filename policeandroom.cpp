/*
一个 n x n 矩阵，每个房间可能是封闭的房间，可能是警察，可能是开的房间，
封闭的房间不能过，返回一个n x n矩阵，每一个元素是最近的警察到这个房间的最短距离。
初始矩阵中-1代表封闭房间，INT_MAX代表普通房间，0代表有警察的房间。

常规思路是对每一个警察做一次BFS，复杂度为O(n^3)。可以一开始找出所有警察，然后一起push到BFS的queue里面，同时搜索。复杂度可降为O(n^2)。
本题出现的频率还是很高的，比如还有这样的描述形式：
给一个matrix里面有人，墙和空格，把空格里填上需要走到最近的人那里的步数。
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

vector<vector<int> > policeandroom(const vector<vector<int> >&arr) {
	if (arr.empty() || arr[0].empty()) return {{}};
	int m=arr.size();
	int n=arr[0].size();
	vector<vector<int> > ret (m, vector<int> (n,-1));
	queue<pair<int,int> > q,new_q;
	unordered_set<int> visited; int dist=1;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++)
			if (arr[i][j]==2) {
				q.push({i,j});
				visited.insert(i*n+j);
				ret[i][j]=0;
			}
	vector<pair<int,int> > dirs {{0,-1},{0,1},{-1,0},{1,0}};
	while (!q.empty()) {
		while (!q.empty()) {
			pair<int,int> tmp=q.front();
			
			q.pop();
			for (auto& dir:dirs) {
				int x=dir.first+tmp.first;
				int y=dir.second+tmp.second;
				if (x>=0 && x<m && y>=0 && y<n && !visited.count(x*n+y) && arr[x][y]==0) {
					new_q.push({x,y});
					visited.insert(x*n+y);
					ret[x][y]=dist;
				}
			}
		}
		swap(q,new_q);++dist;
	}
	return ret;
}
int main() {
	vector<vector<int> > arr{{0,0,0,1,2},{1,1,0,0,0},{0,0,2,0,0},{2,0,0,0,0}};
	vector<vector<int> > ret=policeandroom(arr);
	for (auto& seq:ret) {
		for (auto& elem:seq) 
			cout<<elem<<" ";
		cout<<endl;
	}
	// cout<< validbstpostorder(arr,7);
	return 0;
}

