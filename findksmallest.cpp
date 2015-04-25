/*
Find the kth smallest element in an unordered array.
Quick Select Algorithm:
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

int findksmallest(vector<int> &arr,int k) {
	int n=arr.size();
	if (n==0) return INT_MIN;
	function<int(int,int,int)> findhelper=[&](int i,int j, int m) {
		if (i==j) return arr[i];
		int ind=i;
		for (int k=i;k<j;++k) {
			if (arr[k]<arr[j]) swap(arr[k],arr[ind++]);
		}
		swap(arr[j],arr[ind++]);
		if (ind-i<k) return findhelper(ind,j,k-(ind-i));
		else if (ind-i>k) return findhelper(i,ind-2,k);
		else return arr[ind-1];
	};
	return findhelper(0,n-1,k);
}

void knuthshuffle(vector<int> &arr) {
	int n=arr.size();
	for (int k=n-1;k>=0;--k){
		swap(arr[k],arr[rand()%(k+1)]);
	}
}	
	
int main() {
	int n=10;
	srand(time(NULL));
	vector<int> arr(n,0);
	for (int k=0;k<n;k++) arr[k]=k+1;
	vector<int> sumval(n,0);
	for (int i=1;i<=1000000;i++) {
		knuthshuffle(arr);
		for (int k=0;k<n;k++) {
			sumval[k]+=arr[k];
		}
	}
	for (int k=0;k<n;k++) cout<<sumval[k]<<" ";
		
	// for (int i=1;i<=n;i++)
	// cout<<findksmallest(arr,i)<<endl;
	
	return 0;
}