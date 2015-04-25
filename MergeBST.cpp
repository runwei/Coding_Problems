/*
You are given two balanced binary search trees. Write a function that merges the two given balanced BSTs into a balanced binary search tree.
Your merge function should take O(M+N) time and O(1) space.
G家onsite题，算是很多小问题的综合题。因为不允许用extra space，可以先把两个输入BST给转换成链表，然后merge两个链表，再把merge完的链表重新转化成BST。
*/


#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
using namespace std;
TreeNode* List2BST(TreeNode *root);
TreeNode* flattenBST(TreeNode*root);
TreeNode* mergeList(TreeNode *root1, TreeNode *root2);
void showTree(TreeNode *root);

TreeNode* mergeBST(TreeNode* root1, TreeNode* root2) {
	if (!root1) return root2;
	if (!root2) return root1;
	root1=flattenBST(root1);
	root2=flattenBST(root2);
	root1=mergeList(root1,root2);
	return List2BST(root1);
}

TreeNode* flattenBST(TreeNode*root) {
	if (!root) return NULL;
	root->right=flattenBST(root->right);
	if (!root->left) {
		return root;
	} else {
		TreeNode* p1=flattenBST(root->left);
		TreeNode* p2=p1;
		while (p2->right) p2=p2->right;
		p2->right=root;
		root->left=NULL;
		return p1;
	}
}

TreeNode* mergeList(TreeNode *root1, TreeNode *root2) {
	TreeNode dummy(-1);
	TreeNode* p =&dummy;
	while (root1 || root2) {
		int a1=root1?root1->val:INT_MAX;
		int a2=root2?root2->val:INT_MAX;
		if (a1<a2) {
			p->right=root1;
			root1=root1->right;
		} else {
			p->right=root2;
			root2=root2->right;
		}
		p=p->right;
	}
	return dummy.right;
}

TreeNode* List2BST(TreeNode *root) {
	if (!root || !root->right) return root;
	TreeNode* slow=root, *fast=root->right;
	while (fast->right && fast->right->right) {
		slow=slow->right;
		fast=fast->right->right;
	}
	TreeNode* newroot=slow->right;
	TreeNode* t2=slow->right->right;
	slow->right=NULL;
	newroot->left=List2BST(root);
	newroot->right=List2BST(t2);
	return newroot;
}

void showTree(TreeNode *root) {
	if (!root) return;
	showTree(root->left);
	cout<<root->val<<endl;
	showTree(root->right);
}

int main(){
	TreeNode n1(1), n2(2),n3(3),n4(4),n5(5),n6(6);
	n3.left=&n1;
	n3.right=&n5;
	n4.left=&n2;
	n4.right=&n6;
	TreeNode*p=mergeBST(&n3,&n4);
	showTree(p);
}