/*
Find the max and min elements of an unsorted integer array using a minimal number of comparisons
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

void max_min(int a[],int n,int &minval, int &maxval) {
	int pos=0;
	while (pos+1<n) {
		if (a[pos+1]<a[pos]) swap(a[pos],a[pos+1]);
		minval=min(minval,a[pos]);
		maxval=max(maxval,a[pos+1]);
		pos+=2;
	}
	if (n %2==1) {
		minval=min(minval,a[pos]);
		maxval=max(maxval,a[pos]);
	}
}
	
	
int main() {
	int arr[] {2,1,4,0,3,5,7};
	int maxval, minval;
	max_min(arr,7,minval,maxval);
	cout<<minval<<" "<<maxval<<" ";
	return 0;
}