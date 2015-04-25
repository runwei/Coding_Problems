/*
给定一个数组A[1..n]，求数组B[1..n]，使得B[i] = A[1] * A[2] .. * A[i-1] * A[i+1] .. * A[n]。要求不要使用除法，O(n)时间且不用额外空间。

Examples:
Input: {2, 3, 4, 5}
Output: {60, 40, 30, 24}
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
#include "BST.h"
using namespace std;

vector<int> get_product(const vector<int> &arr) {
	vector<int> ret(arr);
	for (int i=1;i<arr.size();i++)
		ret[i]*=ret[i-1];
	int backnum=1;
	for (int i=arr.size()-1;i>=0;i--){
		ret[i]=i==0?backnum:ret[i-1]*backnum;
		backnum*=arr[i];
	}
	return ret;	
}

int main() {
	vector<int> arr{2,3,4,5};
	vector<int> ret=get_product(arr);
	for (auto &i:ret) cout<<i<<" ";
	return 0;
}