/*
第一题给一个BST（树节点的索引都是不重复的），然后给一个threshhold value，该value可能出现在树中，可能没有，要求分开成两棵树，一棵节点值小于等于threshhold，另一个大于threshold。这个题关键是定义好递归方程的API（即每层递归到底要做什么），然后静下心来做。

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

void ShowTree(TreeNode*root) {
	if (!root) return;
	ShowTree(root->left);
	cout<<root->val<<" ";
	ShowTree(root->right);
}
void SplitTree(TreeNode*root, int target, TreeNode* &t1,TreeNode * &t2) {
	if (!root) {
		t1=NULL;t2=NULL;
	} else {
		TreeNode *p1, *p2;
		if (root->val>target) {
			SplitTree(root->left,target,p1,p2);
			t1=p1;t2=root;
			root->left=p2;
		} else {
			SplitTree(root->right,target,p1,p2);
			t1=root;t2=p2;
			root->right=p1;
		}
	}
}

TreeNode * put (TreeNode *head, int target) {
	if (!head) return new TreeNode(target);
	if (target==head->val) return head;
	else if (target<head->val) head->left=put(head->left,target);
	else head->right=put(head->right,target);
}

int main() {
	srand(time(NULL));
	TreeNode* root=new TreeNode(10);
	for (int i=0;i<100;i++)
		root=put(root,rand() %200);
	TreeNode *p1,*p2;
	SplitTree(root,100,p1,p2);
	ShowTree(p1);
	cout<<endl;
	ShowTree(p2);
	return 0;
}