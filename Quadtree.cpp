/*
Given a quadtree structure:
1
2
3
4
5
struct QuadNode {
    QuadNode(int num_ones = 0) : ones(num_ones) {}
    int ones{ 0 };
    QuadNode* child[4]{ nullptr };
};
Please build a quadtree to represent a 0-1 matrix, assume the matrix is a square and the dimension is power of 2.
Given two such quadtrees with same depth, please write a function to calculate how many 1s are overlapped.
For example:
1
2
3
4
5
6
7
Matrix 0:
0 1
1 1
Matrix 1:
0 0
1 1
*/
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

struct QuadNode {
	QuadNode (const int num_ones=0): ones(num_ones) {}
	QuadNode* child[4]{NULL};
	int ones;
};

QuadNode * buildTree(vector<vector<int> > &mat) {
	if (mat.empty()) return NULL;
	
	function<QuadNode*(int,int,int)> build =[&] (int size,int row,int col) {
		if (size==1) return new QuadNode(mat[row][col]);
		auto root=new QuadNode();
		size/=2;
		int subcoords[4][2]={{row,col},{row+size,col},{row,col+size},{row+size,col+size}};
		for (int i=0;i<4;++i) {
			root->child[i] =build(size,subcoords[i][0],subcoords[i][1]);
			root->ones+=root->child[i]->ones;
		}
		return root;
	};
	return build(mat.size(),0,0);
}

int intersection(QuadNode *t0, QuadNode *t1) {
	int ret=0;
	function<void(QuadNode*,QuadNode*)> solve =[&] (QuadNode *tree0, QuadNode *tree1) {
		if (!tree0 || !tree1 || !tree0->ones || !tree1->ones)  return;
		if (!tree0->child[0] && !tree1->child[0]) {
			ret+=tree0->ones && tree1->ones ? 1:0;
		} 
		else {
			for (int i=0;i<4;i++) 
				solve(tree0->child[i],tree1->child[i]);
		}
	};
	solve(t0,t1);
	return ret;
}

QuadNode* intersectQuad(QuadNode*t0, QuadNode*t1) {
	if (!t0 && !t1) return NULL;
	QuadNode*root;
	if (!t0->child[0] && !t1->child[0]) {
		root=new QuadNode(t0->ones && t1->ones);
		return root;
	}
	else {
		root=new QuadNode(0);
		int sumones=0;
		for (int i=0;i<4;i++) {
			root->child[i]=intersectQuad(t0->child[i],t1->child[i]);
			sumones+=root->child[i]->ones;
		}
		root->ones=sumones;
		return root;
	}
}

void ShowQuadtree(QuadNode*root) {
	if (!root) return;
	if (!root->child[0]) {cout<<root->ones;return;}
	cout<<"{";
	for (int i=0;i<4;i++)
		ShowQuadtree(root->child[i]);
	cout<<"}";
}

int main(){
	vector<vector<int> > A{{1,0,0,1},{0,1,0,1},{1,1,0,0,},{0,0,0,1}};
	vector<vector<int> > B{{1,1,0,1},{1,0,0,1},{1,1,0,0,},{0,0,0,1}};
	QuadNode* ta=buildTree(A);
	QuadNode* tb=buildTree(B);
	cout<<intersection(ta,tb);
	// QuadNode* tc=intersectQuad(ta,tb);
	// cout<< tc->ones<<endl;
	// ShowQuadtree(tc);
	return 0;
}