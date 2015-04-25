/*
Matching nuts and bolts problem can be stated as follows: “Given a collection of n nuts of distinct sizes and n bolts such that there is a one-to-one correspondence between the nuts and the bolts, find for each nut its corresponding bolt.” We can only compare nuts to bolts i.e., we can neither compare nuts to nuts nor bolts to bolts.
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

void sorttwogroups(vector<int> &arr1, vector<int> &arr2) {
	function<int(vector<int> &, int,int,int)> partition=[&](vector<int> &arr,int base, int start, int end) {
		int pos=start;
		for (int i=start;i<=end;i++) {
			if (arr[i]<base) swap(arr[i],arr[pos++]);
		}
		for (int i=pos;i<=end;i++) 
			if (arr[i]==base) {swap(arr[pos],arr[i]);break;}
		return pos;
	};
	function<void(int,int,int,int)> sorthelper=[&](int s1,int e1,int s2,int e2) {
		if (s1>=e1) return;
		int ind1=partition(arr1,arr2[e2],s1,e1);
		int ind2=partition(arr2,arr1[ind1],s2,e2);
		sorthelper(s1,ind1-1,s2,ind2-1);
		sorthelper(ind1+1,e1,ind2+1,e2);
	};
	sorthelper(0,(int)arr1.size()-1,0,(int) arr2.size()-1);
}
	
	
int main() {
	vector<int> arr1 {2,1,4,0,3,5};
	vector<int> arr2 {3,2,0,1,5,4};
	sorttwogroups(arr1,arr2);
	for (auto &num:arr1) cout<<num<<" ";cout<<endl;
	for (auto &num:arr2) cout<<num<<" ";cout<<endl;
	
	return 0;
}