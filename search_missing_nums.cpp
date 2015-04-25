/*
A sorted array contains integers from 1..n with m of them missing. Find all missing numbers.

Example:
n = 8 , m = 2
arr = [1,2,4,5,6,8]
Result has to be {3, 7}.
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

vector<int> findmissingnum(const vector<int> &arr, int m) {
	vector<int> ret;
	function<void(int,int,int,int)> bs=[&](int l, int r, int start, int end) {
		if (l==r) {
			for(int i=start;i<=end;++i)
				if (arr[l]!=i) ret.push_back(i);
		} else  {
			int mid=(l+r)/2;
			if (mid-l!=arr[mid]-start) bs(l,mid,start, arr[mid]);
			if (r-mid-1!=end-arr[mid]+1) bs(mid+1,r,arr[mid]+1,end);
		}
	};
	bs(0,arr.size()-1,1, arr.size()+m);
	return ret;
}

int main() {
	vector<int> arr {1,2,4,5,6,8};
	vector<int> ret=findmissingnum(arr,2);
	for (auto &num:ret) cout<<num;
	return 0;
}

