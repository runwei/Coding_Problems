#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void backtrack(vector<vector<int> >&ret, vector<int> &state,TreeNode*root, int sum);

vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<vector<int> > ret;
    vector<int> state;
    if (!root) return ret;
	function<void(TreeNode*, int)> backtrack=[&](TreeNode* cur, int sum){
		if (!cur->left && !cur->right){
			if (cur->val==sum) {state.push_back(cur->val);ret.push_back(state);state.pop_back();}
		} else {
			if (cur->left) {
				state.push_back(cur->val);
				sum-=cur->val;
				backtrack(cur->left,sum);
				sum+=cur->val;
				state.pop_back();
			} 
			if (cur->right) {
				state.push_back(cur->val);
				sum-=cur->val;
				backtrack(cur->right,sum);
				sum+=cur->val;
				state.pop_back();				
			}
		}
	};
    backtrack(root,sum);
    return ret;
}
// void backtrack(vector<vector<int> >&ret, vector<int> &state,TreeNode*root, int sum) {
//     if (!root->left && !root->right) {
//         if (root->val==sum)  ret.push_back(state);
//     } else {
//         if (root->left) {state.push_back(root->val);backtrack(ret,state,root->left,sum-root->val);state.pop_back();}
//         if (root->right){state.push_back(root->val);backtrack(ret,state,root->right,sum-root->val);state.pop_back();}
//     }
// }


int main() {	
	TreeNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n1.left=&n3;
	n1.right=&n2;
	n3.left=&n4;
	n3.right=&n5;
	n2.left=&n6;
	vector<vector<int> > ret=pathSum(&n1,9);
	for (int i=0;i<ret.size();i++){
		for (auto & k:ret[i]) cout<<k<<" ";
		cout<<endl;
	}
	// cout<<ret.size();
	return 0;
}