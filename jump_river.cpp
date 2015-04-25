/*
给一个0/1数组R代表一条河，0代表水，1代表石头。起始位置R[0]等于1，
初速度为1. 每一步可以选择以当前速度移动，或者当前速度加1再移动。只能停留在石头上。问最少几步可以跳完整条河流。

给定数组为R=[1,1,1,0,1,1,0,0]，最少3步能过河：
第一步先提速到2，再跳到R[2]；
第二步先提速到3，再跳到R[5]；
第三步保持速度3，跳出数组范围，成功过河。
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


int min_river_jumps(const vector<int>& river)  {
	map<pair<int,int>, int> m_map;
	int n=river.size();
	function<int(int,int)> dfs=[&](int pos,int speed) {
		if (pos>=n) return 0;
		else if (m_map.count({pos,speed})) return m_map[{pos,speed}];
		else if (river[pos]) {
			int a1=dfs(pos+speed,speed);
			int a2=dfs(pos+speed+1,speed+1);
			m_map[{pos,speed}]=min(a1,a2)==INT_MAX?INT_MAX:min(a1,a2)+1;
		} else m_map[{pos,speed}]=INT_MAX;
		return m_map[{pos,speed}];
	}; 
	return dfs(0,1);
}


int main(){
	vector<int> A{1,1,1,0,1,1,0,0,1,1,1,1,0,0,0,1,1,1};
	cout<<min_river_jumps(A);
	return 0;
}