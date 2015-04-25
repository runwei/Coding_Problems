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
#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
// #include "leetcode.h"
using namespace std;

struct Node {
	Node *left{NULL};
	Node *right{NULL};
	int begin {0};
	int end {0};
	int cover {0};
	bool is_leaf() {return begin==end;}
	Node (const int l=0,const int r=0): begin(l),end(r) {
		cover=r-l+1;
	}
};

class SegmentTree {
private:
	Node *root {NULL};
public:
	SegmentTree(int n) {
		root=BuildTree(1,n);
	}
	Node* BuildTree(int start, int end) {
		if (start>end) return NULL;
		else if (start==end) return new Node(start,end);
		else {
			Node *cur= new Node(start,end);
			int mid=start+(end-start)/2;
			cur->left=BuildTree(start,mid);
			cur->right=BuildTree(mid+1,end);
			return cur;
		}
	}

	void DeleteNode(int n) {
		function<Node*(Node*, int)> deletehelper=[&] (Node* cur, int num)->Node* {
			if (!cur) return NULL;
			if (cur->begin==cur->end && cur->begin==num) {
				delete(cur);
				return NULL;
			} else {
				--cur->cover;
				int mid=(cur->begin+cur->end)/2;
				if (mid<num) cur->right=deletehelper(cur->right,num);
				else cur->left=deletehelper(cur->left,num);
			}
		};
		root=deletehelper(root,n);
	}
	void showTree() {
		function<void(Node*)> showhelper=[&](Node* root) {
			if (!root) return ;
			else {
				cout<<root->begin<<"-"<<root->end<<"-"<<root->cover<<endl;
				showhelper(root->left);
				showhelper(root->right);
			}
		};
		showhelper(root);
	}
	int getkth(int k) {
		int ret=-1;
		function<void(Node*,int)> dfs=[&] (Node* cur, int num) {
			if (!cur) return;
			if (num>cur->cover) return;
			else if (cur->begin==cur->end && num==1) ret= cur->begin;
			else  {
				int leftcover=cur->left?cur->left->cover:0;
				if(num<=leftcover) dfs(cur->left,num);
				else dfs(cur->right,num-leftcover);
			}
		};
		dfs(root,k);
		return ret;
		// Node *cur=root;
		// while (cur) {
		// 	if (k==1 && cur->begin==cur->end) return cur->begin;
		// 	int left_cover=cur->left?cur->left->cover:0;
		// 	if (k<=left_cover) {
		// 		cur=cur->left;
		// 	} else {
		// 		k-=left_cover;
		// 		cur=cur->right;
		// 	}
		// }
		// return -1;
	}
};


vector<int> recover_count_array(const vector<int> &arr) {
	vector<int> ret;
	SegmentTree t(arr.size());
	t.showTree();
	for (int i=0;i<arr.size();i++) {
		int tmpnum=t.getkth(arr[i]+1);
		ret.push_back(tmpnum);
		t.DeleteNode(tmpnum);
		t.showTree();
		cout<<endl<<endl;
		// tmpnum=t.getkth(arr[1]+1);
	}
	return ret;
}

int main() {
	vector<int> arr {3,0,1,0};
	vector<int> ret=recover_count_array(arr);
	for (auto &num:ret) cout<<num<<" ";
	return 0;
}

