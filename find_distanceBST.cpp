/*
Find the distance between two keys in a binary tree, no parent pointers are given.
这题可以先求出两个节点的LCA，然后分别计算离LCA的深度，加起来就可以了。当然纯粹这样做有一些重复运算，我们可以在找LCA的时候就把两个节点分别离根节点的距离算出来，如果两个节点是上下级关系，就需要把下边的那个节点的高度单独再算一次。
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

TreeNode* put(TreeNode*p, int target) {
	if (!p) return new TreeNode(target);
	if (p->val==target) return p;
	if (target<p->val) p->left=put(p->left,target);
	if (target>p->val) p->right=put(p->right,target);
	return p;
}

int get_distance(TreeNode* root, int key1, int key2) {
	vector<TreeNode*> vec1,vec2;
	function<bool(vector<TreeNode*> &,TreeNode*,int key)> dfs=[&] (vector<TreeNode*> &vec,TreeNode* t, int key) {
		if (!t) return false;
		vec.push_back(t);
		if (t->val==key) {return true;}
		if ( dfs(vec,t->left,key) ||  dfs(vec,t->right,key)) return true;
		vec.pop_back();
		return false;
	};
	dfs(vec1,root,key1);
	dfs(vec2,root,key2);
	int p=0; 
	for (;p<vec1.size() && p<vec2.size() && vec1[p]->val==vec2[p]->val;++p){}
	return vec1.size()+vec2.size()-2*p;
}
	
int main() {
	TreeNode*p {NULL};
	int A[]={2,8,4,3};
	for (int i=0;i<sizeof(A)/sizeof(int);i++) 
		p=put(p,A[i]);
	cout<<get_distance(p,8,3);
}