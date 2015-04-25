/*
Given an array find 3 elements such that a[i] < a[j] < a[k] and i < j < k in 0(n) time.
可以用买卖股票的第三题的思路做。

用两个数组，分别存最大值和最小值的index。
min数组从前往后扫，如果遇到最小值，则把这个index存下来。
max数组从后往前扫，原理同上。
假设数组为：{4,7,5,1,3,8,9,6,2}
扫完后的min和max应该分别为：
{0,0,0,3,3,3,3,3,3}
{6,6,6,6,6,6,6,7,8}
下面就简单了，从前往后扫描原数组，如果符合nums[mins[i]] < nums[i] && nums[i] < nums[maxs[i]]就直接返回即可。
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

vector<int> find3increasingnum(const vector<int> &arr) {
	int n=arr.size();
	if (n<3) return {};
	vector<int> minval(n,INT_MAX),maxval(n,INT_MIN);
	for (int i=0;i<n;i++) {
		minval[i]=i==0?arr[0]:min(minval[i-1],arr[i]);
		maxval[n-1-i]=i==0?arr[n-1]:max(maxval[n-i],arr[n-i-1]);
	}
	for (int i=0;i<n;i++) {
		if (minval[i]<arr[i] && arr[i]<maxval[i]) return {minval[i],arr[i],maxval[i]};
	}
	return {};
}
	
int main() {
	vector<int> arr {3,1,2,4,5,0,3,2};
	vector<int> ret=find3increasingnum(arr);
	for (int i=0;i<3;i++)
	cout<<ret[i]<<endl;
		
	// for (int i=1;i<=n;i++)
	// cout<<findksmallest(arr,i)<<endl;
	
	return 0;
}