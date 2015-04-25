/*
已知平面上有N个点，找到其中某个点P，使得P到其余所有点的Manhattan距离之和最短并求出这个最短距离。
因为是曼哈顿距离，所以可以把x轴和y轴分离开来计算。

针对x坐标对所有点排序。
求一个数组，每个元素为对应点到其他所有点的在x轴上的距离和。
这一步需要O(n)的算法，具体思路是，记录两个数组，left和right:
left[i] = x[1] + x[2] + ... + x[i-1]
right[i] = x[i+1] + x[i+2] ... + x[n]
然后对每个点
sum[i] = x[i] * i - left[i] + right[i] - (n - 1 - i) * x[i]
针对y坐标重复1和2的计算。
求得每个点在x和y上的1D曼哈顿距离和之后，可以遍历所有点，直接找出最小值。
算法复杂度即为sort的复杂度,O(nlogn)
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

pair<int,int> minsummanhattan(vector<pair<int,int> > arr) {
	map<pair<int,int>, int > m_x,m_y;
	int n=arr.size();
	auto f1=[](pair<int,int> p1,pair<int,int> p2) {
		return p1.first<p2.first;
	};
	auto f2=[](pair<int,int> p1,pair<int,int> p2) {
		return p1.second<p2.second;
	};
	sort(arr.begin(),arr.end(),f1);
	int sumleft=0,sumright=0;
	for (int i=0;i<arr.size();i++) sumright+=arr[i].first;
	for (int i=0;i<arr.size();i++) {
		m_x[arr[i]]=i*arr[i].first-sumleft+sumright-(n-i)*arr[i].first;
		sumleft+=arr[i].first;
		sumright-=arr[i].first;
	}
	sort(arr.begin(),arr.end(),f2);
	sumleft=0;sumright=0;
	for (int i=0;i<arr.size();i++) sumright+=arr[i].second;
	for (int i=0;i<arr.size();i++) {
		m_y[arr[i]]=i*arr[i].second-sumleft+sumright-(n-i)*arr[i].second;
		sumleft+=arr[i].second;
		sumright-=arr[i].second;
	}
	pair<int,int> ret{-1,-1}; int mincost=INT_MAX;
	for (int i=0;i<arr.size();i++) {
		if (m_x[arr[i]]+m_y[arr[i]]<mincost) {
			ret=arr[i];
			mincost=m_x[arr[i]]+m_y[arr[i]];
		}
	}
	return ret;
}


	
int main() {
	vector<pair<int,int> > arr {{0,0},{1,1},{2,3},{3,3},{4,4}};
	pair<int,int> ret=minsummanhattan(arr);
	cout<<ret.first<<" "<<ret.second<<endl;
	return 0;
}