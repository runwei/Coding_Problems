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

using _pair=pair<int,int>;
int min_dist_sum(const vector<string> &strs) {
	if (strs.empty() || strs[0].empty()) return -1;
	int m=strs.size(),n=strs[0].size();
	int sumdist,mindist=INT_MAX;
		//P means point, D means visited, O means obstacle, V means vacant;
	function<void(vector<string>, int,int)> f=[&](vector<string> arr,int i,int j) {
		queue<_pair> q,new_q;
		int d=1;
		q.push({i,j});
		arr[i][j]='D';//means visited
		while (!q.empty()) {
			while (!q.empty()) {
				_pair tmp=q.front();
				q.pop();
				vector<_pair> directions={{-1,0,},{1,0},{0,-1},{0,1}};
				for (auto & dire: directions){
					if (tmp.first+dire.first>=0 && tmp.first+dire.first<m && tmp.second+dire.second>=0 && tmp.second+dire.second<n) {
						if (arr[tmp.first+dire.first][tmp.second+dire.second]=='P' ) {
							new_q.push({tmp.first+dire.first,tmp.second+dire.second});
							sumdist+=d;
						} else if (arr[tmp.first+dire.first][tmp.second+dire.second]=='V')
							new_q.push({tmp.first+dire.first,tmp.second+dire.second});
						arr[tmp.first+dire.first][tmp.second+dire.second]='D';
					}
				}				
			}
			++d;
			swap(q,new_q);
		}
	};
	
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++) {
			if (strs[i][j]=='V'||  strs[i][j]=='P') {
				sumdist=0;
				f(strs,i,j);
				mindist=mindist>sumdist?sumdist:mindist;
			}
				
		}
	return mindist;
}
	
int main() {
	vector<string> strs {"POOP","VOOV","VOOV","VVVV"};
	cout<<min_dist_sum(strs);
	return 0;
}