/*
Given a Binary Tree, find the deepest leaf node that is left child of its parent.
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


int deepest_left_node(TreeNode *root) {
	int maxlevel=0,ret=0;
	function<void(TreeNode*,TreeNode*,int)> dfs=[&] (TreeNode*last,TreeNode* cur, int level) {
		if (!cur) return;
		if (last && cur==last->left) {
			if (maxlevel<level) {ret=cur->val;maxlevel=level;}
		}
		dfs(cur,cur->left,level+1);
		dfs(cur,cur->right,level+1);
	};
	dfs(NULL,root,0);
	return ret;
}

int main(){
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n1.left=&n2;
	n1.right=&n3;
	n2.left=&n4;
	n2.right=&n5;
	n5.right=&n6;
	cout<<deepest_left_node(&n1);
	return 0;
}