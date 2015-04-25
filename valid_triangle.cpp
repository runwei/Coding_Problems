/*
Three segments of lengths A, B, C form a triangle iff
A + B > C
B + C > A
A + C > B

e.g.
6, 4, 5 can form a triangle
10, 2, 7 can’t

Given a list of segments lengths algorithm should find at least one triplet of segments that form a triangle (if any).

Method should return an array of either:

3 elements: segments that form a triangle (i.e. satisfy the condition above)
empty array if there are no such segments
L家常考题，思路与3 Sum类似，先排序，然后two pointers。
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

vector<vector<double> > validTriangle(vector<double> &arr) {
	vector<vector<double> >ret;
	int n=arr.size();
	if (n<3) return ret;
	sort(arr.begin(),arr.end());
	for (int i=0;i<n-2;i++) {
		if (i!=0 && arr[i]==arr[i-1]) continue;
		for (int j=i+1;j<n-1;j++) {
			if (j!=i+1 && arr[j]==arr[j-1]) continue;
			for (int k=j+1;k<n;k++) {
				if (k!=j+1 && arr[k]==arr[k-1]) continue;
				if (arr[i]+arr[j]>arr[k]) {
					ret.push_back({arr[i],arr[j],arr[k]});
				}
			}
				
		}
	}
	return ret;
}


int main() {
	vector<double> arr{ 9,9, 8,7,8, 10, 7 };
	vector<vector<double> > ret=validTriangle(arr);
	for (auto& set:ret) {
		for (auto & i:set) cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}