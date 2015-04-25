/*
Given a set of n jobs with [start time, end time, cost] find a subset so that no 2 jobs overlap and the cost is maximum.
DP+二分:
Sort the intervals based on end time
define p(i) for each interval, giving the biggest end point which is smaller than the start point of i-th interval. Use binary search to obtain nlogn
define d[i] = max(w(i) + d[p(i)], d[i-1]).

initialize d[0] = 0
The result will be in d[n] n- the number of intervals.
Overall complexity O(nlogn)
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>

#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

vector<string> sortfood(const string& s, double w) {
	map<double, vector<string> >m_map;
	int pos=0,endpos=0;
	bool flag=true; 
	string food;
	while (pos<s.size()) {
		while (pos<s.size() && s[pos]==' ') ++pos;
		if (pos==s.size()) break;
		endpos=pos;
		while (endpos<s.size() && s[endpos]!=' ') ++endpos;
		string tmps=s.substr(pos,endpos-pos);
		double weight=atof(tmps.c_str());
		if (flag) {food=tmps;flag=false;}
		else {
			if (weight>1e-5) {m_map[weight].push_back(food);flag=true;}
			else {
				m_map[w].push_back(food);flag=false;food=tmps;
			}
		}
		pos=endpos+1;
	}
	if (!flag) m_map[w].push_back(food);
	vector<string> ret;
	for (auto it=m_map.begin();it!=m_map.end();++it) 
		for (auto &ss:it->second) ret.push_back(ss);
	return ret;
}


int main() {
	vector<string> ret= sortfood("pizza  500 2.0 ", 5);
	for (auto& s: ret) cout<<s<<endl;
	// sort_food("  pizza  1 hotdog 2.0", 5);
	// sort_food("pizza 500 hotdog 2.0 ", 5);
	// sort_food(" pizza  500 2.0 ", 5);
	return 0;
}

