/*
Given a set of n jobs with [start time, end time, cost] find a subset so that no 2 jobs overlap and the cost is maximum.
DP+二分:
Sort the intervals based on end time
define p(i) for each interval, giving the biggest end point which is smaller than the start point of i-th interval. Use binary search to obtain nlogn
define d[i] = max(w(i) + d[p(i)], d[i-1]).

initialize d[0] = 0
The result will be in d[n] n- the number of intervals.
Overall complexity O(nlogn)
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

TreeNode *randTreeNode(TreeNode* root) {
	TreeNode * ret; int num=0;
	function<void(TreeNode *)> visit=[&] (TreeNode *cur) {
		if (rand() % (++num)==0) ret=cur;
		if (cur->left) visit(cur->left);
		if (cur->right) visit(cur->right);
	};
	if (!root) return NULL;
	visit(root); return ret;
}


int main() {
	TreeNode n1(1), n2(2), n3(3);
	n1.left=&n2;
	n1.right=&n3;
	srand(time(NULL));
	int expnum=0;
	for (int i=0;i<1000000;i++)
		expnum+=randTreeNode(&n1)->val;
	cout<<expnum;
	return 0;
}

