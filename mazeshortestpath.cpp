/*
find the shortest path in maze
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

vector<pair<int,int> > mazeshortestpath(const vector<vector<int> >& arr, pair<int,int>  s, pair<int,int>  t) {
	vector<pair<int,int> > ret;
	if (arr.empty()|| arr[0].empty()) return ret;
	int m=arr.size(), n=arr[0].size();
	unordered_map<int,int> m_map;
	unordered_set<int> visited; 
	queue<pair<int,int> > q;
	q.push(s);visited.insert(s.first*n+s.second);
	vector<pair<int,int> > dirs {{0,-1},{0,1},{-1,0},{1,0}};
	while (!q.empty()) {
		pair<int,int>  tmp=q.front();q.pop();
		bool flag=false;
		for (auto & dir:dirs) {
			int a1=dir.first+tmp.first, a2=dir.second+tmp.second;
			if (a1>=0 && a1<m && a2>=0 && a2<n && arr[a1][a2] && !visited.count(a1*n+a2)) {
				visited.insert(a1*n+a2);
				q.push({a1,a2});
				m_map[a1*n+a2]=tmp.first*n+tmp.second;
				if (t.first==a1 && t.second==a2) {flag=true;break;}
			}
		}
		if (flag) break;
	}
	ret.push_back(t);
	while (t!=s) {
		t=make_pair(m_map[t.first*n+t.second]/n, m_map[t.first*n+t.second] %n);
		ret.push_back(t);
	}
	reverse(ret.begin(),ret.end());
	return ret;
}
	
int main() {
	vector<vector<int> > arr {{1,0,1,0,1},{1,0,1,0,1},{1,1,1,1,1},{1,0,1,0,1},{1,0,1,0,1}};
	pair<int,int>  s {0,0}, t{4,4};
	vector<pair<int,int> > ret=mazeshortestpath(arr, s,t);
	for (auto & n:ret) cout<<n.first<<" "<<n.second<<endl;
	return 0;
}