/*http://www.fgdsb.com/2015/01/19/sums-of-all-subtrees/*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
using namespace std;


int getk_th(TreeNode *root, int k){
	stack<TreeNode*> m_stack;
	TreeNode *p=root;
	int count=0;
	while (p || !m_stack.empty()) {
		while (p) {
			m_stack.push(p);
			p=p->left;
		}
		p=m_stack.top();
		m_stack.pop();
		if (++count==k) return p->val;
		p=p->right;
	}
	return 0;
} 


int main(){
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n3.left=&n1;
	n3.right=&n5;
	n1.right=&n2;
	n5.right=&n6;
	n5.left=&n4;
	cout<<getk_th(&n3,1);
	cout<<getk_th(&n3,2);
	cout<<getk_th(&n3,3);
	cout<<getk_th(&n3,6);
	
	
	return 0;
}