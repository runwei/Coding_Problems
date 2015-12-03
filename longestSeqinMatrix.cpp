/*
Find the longest increasing(increasing means one step) sequence in an integer matrix in 4 directions (up down left right), return the sequence
For Example:
[18273645]

The output should be [1, 2, 3, 4, 5, 6, 7, 8]


直接DFS效率太低，这题主要考DP+记忆化。
DP方程很明显：
opt[i][j] = max{ opt[i+1][j], opt[i-1][j], opt[i][j+1], opt[i][j-1] } +１
可以参考POJ原题,1088滑雪。
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
int longestSeqinMatrix(const vector<vector<int> > &arr) {
	if (arr.empty() || arr[0].empty()) return -1;
	int m=arr.size(), n=arr[0].size();
	vector<vector<int> > mem(m,vector<int> (n,-1));
	int dirs[4][2] {{0,1},{0,-1},{1,0},{-1,0}};
	function<int(int i,int j)> dfs=[&] (int i,int j) {
		if (mem[i][j]!=-1) return mem[i][j];
		else {
			for (int k=0;k<4;++k) {
				int tmpi=i+dirs[k][0], tmpj=j+dirs[k][1];
				if (tmpi>=0 && tmpi<m && tmpj>=0 && tmpj<n && arr[tmpi][tmpj]==arr[i][j]+1) {
					mem[i][j]=max(mem[i][j],dfs(tmpi,tmpj)+1);
				}
			}
			return max(mem[i][j],1);
		}
	};
	int maxnum=0;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++)
			maxnum=max(dfs(i,j),maxnum);
	return maxnum;
}
	
int main() {
	vector<vector<int> > arr {{3,2,3,4},{8,8,6,5},{9,2,3,5}};
	cout<<longestSeqinMatrix(arr);
	return 0;
}