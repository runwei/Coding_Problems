#ifndef BST_H
#define BST_H
#include "leetcode.h"
#include<stack>
using namespace std;

class BST {
public:
	BST(TreeNode *root=NULL): root(root){}
	
	TreeNode* search(int target) {
		TreeNode *p=root;
		while (p) {
			if (p->val==target) return p;
			else if (target<p->val) p=p->left;
			else p=p->right;
		}
		return p;
	}
	
	void deleteVal(int target) {
		root=deleteHelper(root,target);
	}
	
	TreeNode* deleteHelper(TreeNode*p,int target) {
		if (!p) return NULL;
		TreeNode *ret;
		if (target<p->val) p->left=deleteHelper(p->left,target);
		else if (target>p->val) p->right=deleteHelper(p->right,target);
		else {
			if (!p->left) {
				ret=p->right;
				delete(p);
				return ret;
			} else if (!p->right) {
				ret=p->left;
				delete(p);
				return ret;
			}
			TreeNode *ceil=minPointer(p->right);
			p->val=ceil->val;
			p->right=deletemin(p->right);
			return p;
		}
	}
	int maxVal() {
		TreeNode *p=root;
		if (!root) return INT_MIN;
		while (p->right) p=p->right;
		return p->val;
	}
	int minVal() {
		return minPointer(root)->val;
	}
	TreeNode* minPointer(TreeNode* p) {
		while (p->left) p=p->left;
		return p; 
	}
	TreeNode* deletemin(TreeNode* p) {
		if (!p) return NULL;
		if (p->left) return p->left=deletemin(p->left);
		TreeNode *ret=p->right;
		delete(p);
		return ret;
	}
	
	int ceil(int target) {
		TreeNode *node=ceilHelper(root,target);
		return node?node->val:INT_MAX;
	}
	TreeNode *ceilHelper(TreeNode *root, int target) {
		if (!root) return NULL;
		else if (root->val==target) return root;
		else if (target>root->val) return ceilHelper(root->right,target);
		else {
			TreeNode *tmp=ceilHelper(root->left,target);
			if (!tmp) return root;
			else return tmp;
		}
	}
	TreeNode *nextnode(int target) {
		return nextnode(root,target);
	}
	TreeNode *nextnode(TreeNode *root, int target) {
		if (!root) return NULL;
		else if (target>=root->val) return nextnode(root->right,target);
		else {
			TreeNode *tmp=nextnode(root->left,target);
			return tmp?tmp:root;
		}
	}
	
	int floor(int target) {
		TreeNode* node=floorHelper(root,target);
		return node?node->val:INT_MIN;
	}
	TreeNode* floorHelper(TreeNode *root,int target){
		if (!root) return NULL;
		else if (root->val==target) return root;
		else if (target<root->val) return floorHelper(root->left,target);
		else  {
			TreeNode *tmp=floorHelper(root->right,target);
			if (!tmp) return root;
			else return tmp;
		}
	}
	
	void insert(int target) {
		root=put(root,target);
	}
	TreeNode * put (TreeNode *head, int target) {
		if (!head) return new TreeNode(target);
		if (target==head->val) return head;
		else if (target<head->val) head->left=put(head->left,target);
		else head->right=put(head->right,target);
		return head;
	}
		
	void showTree(){
		TreeNode *p=root;
		stack<TreeNode*> m_stack;
		while (p || !m_stack.empty()) {
			if (p) {m_stack.push(p);p=p->left;}
			else {
				p=m_stack.top();
				m_stack.pop();
				cout<<p->val<<" ";
				p=p->right;
			}
		}
		cout<<endl;
	}
private:
	TreeNode *root;
};
#endif
//
// #include<vector>
// #include<iostream>
// #include<algorithm>
// #include<unordered_map>
// #include<unordered_set>
// #include<queue>
// #include<stack>
// #include<stdlib.h>
// #include<ctime>
// #include<limits.h>
// #include "BST.h"
// using namespace std;
//
// int main() {
// 	BST t(NULL);
// 	int A[]={5,3,1,6,4,2,0,8,7,9};
// 	for (int i=0;i<10;i++) t.insert(A[i]);
// 	t.showTree();
// 	t.deleteVal(3);
// 	t.showTree();
// 	// TreeNode *p=t.search();
// 	cout<<endl<<t.floor(3)<<" "<<t.ceil(5);
//
// 	// int val=p?p->val:-1;
// 	// cout<<endl<<val;
// 	return 0;
// }