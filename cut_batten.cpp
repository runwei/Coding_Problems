/*
Least cost to cut a batten
The cost of cutting each segment is the cost of the segment length, an array is storing each end point,
For example:
[0, 3, 7, 8, 11, 12], the batten length is 12, there are 4 cuting point
*/

#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<list>
#include<limits.h>
using namespace std;


int mincutcost(const vector<int> &arr){
	if (arr.empty()) return 0;
	int n=arr.size();
	vector<vector<int> > cost(n,vector<int> (n,0));
	for (int len=2;len<n;++len){
		for (int i=0;i+len<n;i++) {
			int minnum=INT_MAX;
			for (int k=1;k<len;k++) {
				minnum=min(minnum,cost[i][i+k]+cost[i+k][i+len]+arr[i+len]-arr[i]);
			}
			cost[i][i+len]=minnum;
		}
	}

    return cost[0][n-1];
}

// int mincutcost(const vector<int> &arr) {
// 	if (arr.empty()) return 0;
// 	int n=arr.size();
// 	int cost[100][100];
// 	fill_n(&cost[0][0],10000,INT_MAX);
// 	function<int(int,int)> dfs=[&](int i,int j) {
// 		if (i==j || i+1==j) {return 0;}
// 		if (cost[i][j]!=INT_MAX) return cost[i][j];
// 		for (int k=i+1;k<j;++k){
// 			cost[i][j]=min(cost[i][j],dfs(i,k)+dfs(k,j)+arr[j]-arr[i]);
// 		}
// 		return cost[i][j];
// 	};
// 	return dfs(0,n-1);
// }

int main() {
	vector<int> arr {0, 3, 7, 8, 11, 12};
	// int a[]{0, 3, 7, 8, 11, 12};
	// int n=6;
	cout<<mincutcost(arr);
	return 0;
}