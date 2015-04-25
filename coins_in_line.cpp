/*
一串数，两个玩家，每次轮流选一个数并且只能选最左或最右，在你先选并且对手很聪明的情况下，怎样max你的和。
Example:
{5, 3, 7, 10}，应该返回15
{8, 15, 3, 7}，应该返回22
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

int coins_in_line(const vector<int> &arr){
	int n=arr.size();
	if (n==0) return 0;
	int sum[n][n];
	fill_n(&sum[0][0],n*n,0);
	for (int i=0;i<n;i++){
		int cursum=0;
		for (int j=i;j<n;j++) {
			cursum+=arr[j];
			sum[i][j]=cursum;
		}
	}
	int f[n][n];
	fill_n(&f[0][0],n*n,0);
	for (int j=0;j<n;++j)
		for (int i=j;i>=0;--i){
			if (i==j) f[i][j]=arr[i];
			else f[i][j]=max(arr[i]+sum[i+1][j]-f[i+1][j],arr[j]+sum[i][j-1]-f[i][j-1]);
		}
	return f[0][n-1];
}
	
	
int main() {
	vector<int> arr {8,15,3,7};
	cout<<coins_in_line(arr);
}