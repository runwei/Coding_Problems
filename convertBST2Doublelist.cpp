/*
Find longest continous subarray that sum up to zero.
For example:
{1, 2 -3, 1, 5, -5, 6} should return {2, -3, 1, 5, -5}
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


class DoubleListNode {
public:
	int val;
	DoubleListNode* next {NULL}; 
	DoubleListNode* prev {NULL};
	DoubleListNode(int value):val(value) {}
};

void bst2list(TreeNode*root,DoubleListNode* &start, DoubleListNode* &end) {
	start=NULL;end=NULL;
	if (!root) return;
	DoubleListNode *cur=new DoubleListNode(root->val);
	DoubleListNode *leftstart, *rightstart,*leftend, *rightend;
	bst2list(root->left,leftstart,leftend);
	bst2list(root->right,rightstart,rightend);
	cur->prev=leftend;
	cur->next=rightstart;
	if (leftend) leftend->next=cur;
	if (rightstart) rightstart->prev=cur;
	start=leftstart?leftstart:cur;
	end=rightend?rightend:cur;
}
TreeNode * put (TreeNode *head, int target) {
	if (!head) return new TreeNode(target);
	if (target==head->val) return head;
	else if (target<head->val) head->left=put(head->left,target);
	else head->right=put(head->right,target);
}	
	
int main() {
	TreeNode *p=NULL;
	int A[]={5,3,1,6,4,2,0,8,7,9};
	for (int i=0;i<10;i++) p=put(p,A[i]);
	DoubleListNode *start,*end;
	bst2list(p,start,end);
	for (;start;start=start->next) cout<<start->val<<endl;
	for (;end;end=end->prev) cout<<end->val<<endl;	
}