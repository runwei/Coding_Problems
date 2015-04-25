/*
Given a BST and a number x, find two nodes in the BST whose sum is equal to x.
You can’t use extra memory like converting BST into one array and then solve this like 2sum.
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

struct Node{
	int val {0};
	Node* left {NULL};
	Node* right {NULL};
	Node (const int val=0): val(val){}
};


pair<Node*, Node*> twosumBST(Node *root,int sum) {
	Node *p1{NULL}, *p2{NULL};
	function<void(Node*,int)> search=[&](Node* cur,int val) {
		if (!cur) return;
		if (cur->val==val) {p2=cur;return;}
		else if (cur->val>val) search(cur->left,val);
		else search(cur->right,val); 
	};
	
	function<bool(Node*)> iterate=[&] (Node* p){
		if (!p) return false;
		else {
			search(root,sum-p->val);
			if (p2) {
				if (p2!=p) {p1=p; return true;}
				p2=NULL;
			}
			if (iterate(p->left)) return true;
			if (iterate(p->right)) return true;
			return false;
		}
	};
	if (iterate(root)) return {p1,p2};
	else return {NULL,NULL};
}

int main() {
	Node n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
	n4.left=&n2;
	n4.right=&n6;
	n2.left=&n1;
	n2.right=&n3;
	n6.left=&n5;
	n6.right=&n7;
	pair<Node*, Node*> ret=twosumBST(&n4,8);
	cout<<ret.first->val<<" "<<ret.second->val<<endl;
	return 0;
}

