/*
写一个程序，找出 5^1234566789893943的从底位开始的1000位数字。
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