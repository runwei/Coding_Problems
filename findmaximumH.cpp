/*
一个array里面找最大的这样的h: 至少有h个数大于等于h。
比如{2,3,5}答案是2，{5,6,7,8}答案是4。


可以用quick select的思路来做，平均时间复杂度O(n),空间O(1)
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>

#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

int  findmaximumH(vector<int> &arr) {
	function<int(int,int)> partition=[&](int s,int e) {
		int pos=s;
		for(int i=s;i<e;i++) 
			if (arr[i]>arr[e]) swap(arr[pos++],arr[i]);
		swap(arr[pos++],arr[e]);
		return pos;
	};
	
	function<int(int,int,int)> helper=[&](int s,int e,int leftnum) {
		if (s>e) return leftnum;
		int ind=partition(s,e);
		if (leftnum+ind-s==arr[ind-1]) return arr[ind-1];
		else if (leftnum+ind-s<arr[ind-1]) return helper(ind,e,leftnum+ind-s);
		else return helper(s,ind-2,leftnum);
	};
	return helper(0,(int) arr.size()-1,0);
}


int main() {
	vector<int> arr {2,3,5};
	cout<<findmaximumH(arr);
	
	return 0;
}

