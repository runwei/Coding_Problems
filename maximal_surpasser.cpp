/*
输入一个数组，返回数组元素的surpasser个数的最大值。
数组元素a[i] 的surpasser是指元素a[j], j > i， a[j] > a[i]。
比如[10, 3, 7, 1, 23, 14, 6, 9] 这个数组中10的surpasser是23,14，个数是2。而3的surpasser是7,23,14,6,9，个数为5，并且是最多的一个。所以返回5。
利用特殊数据结构的话，本题有很多种做法，比如BST，线段树，点树，树状数组。下面给出一种归并排序思路的解法。实际上跟Inverse Pairs基本是完全一样的。这里关心的是顺序而不是逆序。
大体思路就是在降序归并排序的过程中每次遇到顺序对就记录下来，比如merge的过程中两个元素分别是3和7，3 < 7，所以3的顺序数+1。最后merge sort完毕后，每个顺序数的个数我们都知道，返回最大值即可。
思路很简单，唯一tricky的地方就是每次遇到顺序的时候，这个顺序数的个数到底加多少。这个需要注意一下。
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

int max_surpasser(vector<int> nums) {
	int n=nums.size();
	vector<int> num_bak(n,0);
	unordered_map<int,int> m_map;
	function<void(int,int,int)> merge=[&](int start, int mid, int end) {
		int left=start, right=mid+1,curpos=start;
		while (left<=mid || right<=end) {
			int a1=left<=mid?nums[left]:INT_MAX;
			int a2=right<=end?nums[right]:INT_MAX;
			if (a1<a2) {
				num_bak[curpos++]=nums[left++];
				m_map[a1]+=end-right+1;
			} else {
				num_bak[curpos++]=nums[right++];
			}
			
		}
		for (int i=start;i<=end;i++) nums[i]=num_bak[i];
	};
	
	function<void(int,int)> mergesort=[&] (int start, int end) {
		if(start>=end) return;
		int mid=start+(end-start)/2;
		mergesort(start,mid);
		mergesort(mid+1,end);
		merge(start,mid,end);
	};

	mergesort(0,n-1);
	// int maxval=0;
	// for (auto &m:m_map) maxval+=m.second;
	int maxval=INT_MIN;
	for (auto &m:m_map) maxval=maxval>m.second?maxval:m.second;
	return maxval;
}


int main() {
	vector<int> nums {3,5,1,4,6,2};
	int ret=max_surpasser(nums);
	cout<<ret;
	return 0;
}