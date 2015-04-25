/*
Given an array of whose elements are positive numbers. Find the maximum sum of a subsequence with all the constraint that no two numbers in the sequence should be adjacent in the array.
3 2 7 10 should return 13 (13 = 3 + 10)
3 2 5 10 7 should return 15 (15 = 3 + 5 + 7)
1 5 4 3 2 should return 8 (8 = 5 + 3)

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

int findmaxsum(vector<int> &arr) {
	int n=arr.size();
	if (n==0) return 0;
	int prev=0, cur=arr[0];
	for (int i=1;i<n;i++) {
		int tmp=prev;
		prev=cur;
		cur=max(cur,tmp+arr[i]);
	}
	return cur;
}


int main() {
	vector<int> A {3,2,5,10,7};
	cout<<findmaxsum(A);
	return 0;
}