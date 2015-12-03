/*
Given an integer array, adjust each integers so that the difference of every adjcent integers are not greater than a given number target.
If the array before adjustment is A, the array after adjustment is B, you should minimize the sum of |A[i]-B[i]|
Note:
You can assume each number in the array is a positive integer and not greater than 100
Example:
Given [1,4,2,3] and target=1, one of the solutions is [2,3,2,3], the adjustment cost is 2 and it’s minimal. Return 2.
此题可以用记忆化搜索也可以用DP。
记忆化搜索用的Memory矩阵含义为
M[i][j]：从index = i处开始往后所有的differ，并且A[i]的取值取为j + 1;
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;



int minadjustcost(const vector<int> &arr, int target) {
	int n=arr.size();
	if (n==0) return 0;
	int f[n][100];fill_n(&f[0][0],n*100,INT_MAX);
	for (int i=0;i<n;i++) {
		for (int num=0;num<100;++num) {
			if (i==0) f[0][num]=abs(num-arr[0]);
			else {
				for (int k=max(0,num-target);k<=min(99,num+target);++k)
					f[i][num]=min(f[i][num],f[i-1][k]);
				f[i][num]+=abs(arr[i]-num);
			}
		}
	}
	int mincost=INT_MAX;
	for (int num=0;num<100;++num)
		mincost=min(f[n-1][num],mincost);
	return mincost;
}
	
int main() {
	vector<int> arr {1,4,2,3,2,3,2,2,4};
	cout<<minadjustcost(arr,1);
	return 0;
}