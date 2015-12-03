/*
Given an integer array, return the number of all inverse pairs.
For example:
{7, 5, 6, 4}
There are five inverse pairs in total:
(7,6), (7,5), (7,4), (6,4), (5,4)
The result should be 5.
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
using namespace std;

int inverse_pairs(vector<int> &array) {
	if (array.size()<2) return 0;
	vector<int> newarray(array);
	
	function<int(int,int,int,int)> mymerge=[&] (int s1, int e1, int s2,int e2) {
		int p1=s1, p2=s2, sum=0,p3=s1;
		while (p1<=e1 || p2<=e2) {
			int a1=p1<=e1?array[p1]:INT_MAX;
			int a2=p2<=e2?array[p2]:INT_MAX;
			if (a1<=a2) {
				newarray[p3++]=a1; ++p1;
			} else {
				newarray[p3++]=a2; ++p2;
				sum+=e1-p1+1;
			}
		}
		for (int i=s1;i<=e2;i++) array[i]=newarray[i];
		return sum;
	};
	
	function<int(int,int)> mergesort =[&] (int start, int end) {
		if (start>=end) return 0;
		int mid=start+(end-start)/2;
		int a1=mergesort(start,mid);
		int a2=mergesort(mid+1,end);
		int ret=mymerge(start,mid,mid+1,end);
		return ret+a1+a2;
	};
	return mergesort(0,array.size()-1);
}
	
	
int main(){
	vector<int> array{7,5,6,4};
	cout<<inverse_pairs(array);
	return 0;
}