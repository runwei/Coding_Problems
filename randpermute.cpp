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
    backtrack(ret,state,root,sum);
    return ret;
}
void backtrack(vector<vector<int> >&ret, vector<int> &state,TreeNode*root, int sum) {
    if (!root->left && !root->right) {
        if (root->val==sum)  ret.push_back(state);
    } else {
        if (root->left) {state.push_back(root->val);backtrack(ret,state,root->left,sum-root->val);state.pop_back();}
        if (root->right){state.push_back(root->val);backtrack(ret,state,root->right,sum-root->val);state.pop_back();}
    }
}


int main() {	
	TreeNode node(1);
	vector<vector<int> > ret=pathSum(&node,1);
	cout<<ret.size();
	return 0;
}