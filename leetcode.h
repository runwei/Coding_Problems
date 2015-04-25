#ifndef _leetcode
#define _leetcode
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode{
	int val;
	TreeNode *left {NULL};
	TreeNode *right {NULL};
	TreeNode (const int& val=0): val(val){}
};
#endif