/*
二维矩阵里面有obstacle，已知有k个点，求房间中离这k个点距离之和最短的那个点。


对所有的K个点做一次BFS，记录下每个点的最短距离和，最后扫一遍找出最小值即可。复杂度是O(K*N^2)，感觉有更优的解。
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<list>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
#include "BST.h"
using namespace std;

using _pair = pair<int,int>;
//In the matrix strs, P means point, D means visited, O means obstacle, V means vacant;
int min_dist_sum(const vector<string> &strs) {
	if (strs.empty() || strs[0].empty()) return -1;
	int m=strs.size(), n=strs[0].size();
	int dist[m][n]; fill_n(&dist[0][0],m*n,INT_MAX);
	vector<_pair> m_vecp;
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++){
			if (strs[i][j]=='P')
				m_vecp.push_back({i,j});
		}
	int k=m_vecp.size();
	unordered_set<int> m_set;
	queue<_pair> m_q, m_newq;
	int dirs[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
	for (int l=0;l<k;++l) {
		m_set.clear();
		m_set.insert(m_vecp[l].first*n+m_vecp[l].second);
		int count=0;
		m_q.push(m_vecp[l]);
		while (!m_q.empty()) {
			while (!m_q.empty()) {
				_pair point=m_q.front();
				m_q.pop();
				dist[point.first][point.second]=dist[point.first][point.second]==INT_MAX?count:dist[point.first][point.second]+count;
				for (int i=0;i<4;i++) {
					int tmpx=point.first+dirs[i][0];
					int tmpy=point.second+dirs[i][1];
					if (tmpx>=0 && tmpx<m && tmpy>=0 && tmpy<n && strs[tmpx][tmpy]!='O' && !m_set.count(tmpx*n+tmpy)){
						m_set.insert(tmpx*n+tmpy);
						m_newq.push({tmpx,tmpy});
					}
				}
			} 
			swap(m_newq,m_q);
			++count;
		}
	}
	int mindist=INT_MAX;
	for (int i=0;i<m;++i)
		for (int j=0;j<n;++j){
			mindist=min(dist[i][j],mindist);
		}
	return mindist;
}

// using _pair=pair<int,int>;
// int min_dist_sum(const vector<string> &strs) {
// 	if (strs.empty() || strs[0].empty()) return -1;
// 	int m=strs.size(),n=strs[0].size();
// 	int sumdist,mindist=INT_MAX;
// 	function<void(vector<string>, int,int)> f=[&](vector<string> arr,int i,int j) {
// 		queue<_pair> q,new_q;
// 		int d=1;
// 		q.push({i,j});
// 		arr[i][j]='D';//means visited
// 		while (!q.empty()) {
// 			while (!q.empty()) {
// 				_pair tmp=q.front();
// 				q.pop();
// 				vector<_pair> directions={{-1,0,},{1,0},{0,-1},{0,1}};
// 				for (auto & dire: directions){
// 					if (tmp.first+dire.first>=0 && tmp.first+dire.first<m && tmp.second+dire.second>=0 && tmp.second+dire.second<n) {
// 						if (arr[tmp.first+dire.first][tmp.second+dire.second]=='P' ) {
// 							new_q.push({tmp.first+dire.first,tmp.second+dire.second});
// 							sumdist+=d;
// 						} else if (arr[tmp.first+dire.first][tmp.second+dire.second]=='V')
// 							new_q.push({tmp.first+dire.first,tmp.second+dire.second});
// 						arr[tmp.first+dire.first][tmp.second+dire.second]='D';
// 					}
// 				}
// 			}
// 			++d;
// 			swap(q,new_q);
// 		}
// 	};
//
// 	for (int i=0;i<m;i++)
// 		for (int j=0;j<n;j++) {
// 			if (strs[i][j]=='V'||  strs[i][j]=='P') {
// 				sumdist=0;
// 				f(strs,i,j);
// 				mindist=mindist>sumdist?sumdist:mindist;
// 			}
//
// 		}
// 	return mindist;
// }
	
int main() {
	vector<string> strs {"POOP","VOOV","VOOV","PVVV"};
	cout<<min_dist_sum(strs);
	return 0;
}