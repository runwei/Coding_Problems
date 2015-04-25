/*
A number of buildings are visible form a point. Each building is a rectangle, and the bottom of each buliding lies on a fixed line. A building is specified using a triple of (Left, Height, Right). One building may partly obstruct another, as shown below:
nv5RL1s
The skyline is the list of coordinates and corresponding heights of what is visible.
For example, the skyline to the buildings on the left in figure above is given in the figure on the right.
Assume you have a Building class:
struct Building {
    Building() {}
    Building(int l, int r, int h) : left(l), right(r), height(h){}
    int left{ 0 }, right{ 0 }, height{ 0 };
};
And the input is:
{{1,5,11}, {2,7,6}, {3,9,13}, {12,16,7}, {14,25,3}, {19,22,18}, {23,29,13}, {24,28,4}}

Output could be a set of merged buildings:
{{1,3,11}, {3,9,13}, {12,16,7}, {16,19,3}, {19,22,18}, {22,23,3}, {23,29,13}}
非常经典的一题，我所见过的面经里G家和Yelp都考过，也有多种做法。下面给出类似归并排序思想的Divide and Conquer算法。
首先原题需要给出skyline，也就是建筑物的轮廓，实际上就是合并所有相交的建筑物，比如下图的效果：

merge
这样的合并效果大致就是二维版的merge intervals，也是本题的核心部分。实际上也就是把所有情况枚举出来，分别处理（参考代码中的do_overlap函数）。
对于没有相交的建筑物就按照merge sort的方法处理即可，最后得到的结果就是merge并排序后的建筑物，遍历一遍即可得到skyline。时间复杂度为O(NlogN)。
当然，这样的思路很明显也是可以用BST或者线段树来解的。
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
#include "BST.h"
using namespace std;


struct Building {
	Building() {}
	Building(int l, int r, int h):l(l),r(r),h(h){}
	int l{0},r{0},h{0};
};

vector<Building> draw_skyline(vector<Building> &buildings) {
	using _pair = pair<int,int>;
	auto f=[](const _pair &a, const _pair &b) {
		if (a.first<b.first) return true;
		else if (a.first>b.first) return false;
		else return a.second<=b.second;
	};
	vector<_pair> m_vec;
	for (auto & b:buildings) {
		m_vec.push_back({b.l,b.h});
		m_vec.push_back({b.r,-b.h});
	}
	sort(m_vec.begin(),m_vec.end(),f);
	vector<Building> ret;
	BST t;
	int prevh=INT_MIN,prevl=INT_MIN;
	for (int i=0;i<m_vec.size();i++) {
		if (m_vec[i].second>0) {
			t.insert(m_vec[i].second);
		} else {
			t.deleteVal(-m_vec[i].second);
		}
		if ( t.maxVal()!=prevh) {
			if (prevh!=INT_MIN)ret.push_back({prevl,m_vec[i].first,prevh});
			prevh=t.maxVal();
			prevl=m_vec[i].first;
		}
	}
	return ret;
}


int main() {
	vector<Building> buildings {{1,5,11}, {2,7,6}, {3,9,13}, {12,16,7}, {14,25,3}, {19,22,18}, {23,29,13}, {24,28,4}};
	vector<Building> ret=draw_skyline(buildings);
	for (auto &b:ret) cout<<b.l<<" "<<b.r<<" "<<b.h<<endl;
	return 0;
}