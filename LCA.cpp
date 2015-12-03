/*
Given a binary search tree (BST), find the lowest common ancestor of two given nodes in the BST.
A top-down walk from the root of the tree is enough.
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

struct NodeP{
	int val {0};
	NodeP* left {NULL};
	NodeP* right{NULL};
	NodeP* parent{NULL};
	NodeP(const int& val): val(val) {}
};

TreeNode* LCA_noparent(TreeNode* root, TreeNode *t1, TreeNode *t2) {
	if (!root) return NULL;
	if (root==t1 || root==t2) return root;
	TreeNode* p1=LCA_noparent(root->left,t1,t2);
	TreeNode* p2=LCA_noparent(root->right,t1,t2);
	if (p1 && p2) return root;
	else return p1?p1:p2;
}

TreeNode* LCA_BST(TreeNode* root, TreeNode *t1, TreeNode *t2) {
	if (!root || !t1 || !t2) return NULL;
	else if (max(t1->val, t2->val)<root->val) 
		return LCA_BST(root->left,t1,t2);
	else if (min(t1->val,t2->val)>root->val)
		return LCA_BST(root->right,t1,t2);
	else return root;
}


// NodeP* LCA_parent(NodeP*, NodeP* t1, NodeP *t2){
//
// }

	
	
int main() {
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6),n7(7);
	n4.left=&n2;
	n4.right=&n6;
	n2.left=&n1;
	n2.right=&n3;
	n6.left=&n5;
	n6.right=&n7;
	TreeNode *ret=LCA_BST(&n4,&n1,&n2);
	cout<<ret->val;
	return 0;
}