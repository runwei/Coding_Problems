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

vector<string> get_token(const string& s) {
	int pos=0,endpos;
	int quotestart=-1;
	vector<string> ret;
	while (pos<s.size()) {
		while (pos<s.size() && s[pos]==' ') ++pos;
		if (pos==s.size()) break;
		if (s[pos]=='\"' && quotestart==-1) quotestart=ret.size();
		endpos=pos;
		while(endpos<s.size() && s[endpos]!=' ') ++endpos;
		string tmps=s.substr(pos,endpos-pos);
		ret.push_back(tmps);
		if (quotestart!=-1 && tmps.back()=='\"') {
			ret[quotestart].erase(0,1);
			ret.back().pop_back();
			for (int i=quotestart+1;i<ret.size();++i) {
				ret[quotestart]=ret[quotestart]+" "+ret[i];
			}
			ret.erase(ret.begin()+quotestart+1,ret.end());
			quotestart=-1;
		}
		pos=endpos+1;  
	}
	return ret;
}


int main() {
	vector<string> ret= get_token("I have a \"faux coat\"");
	for (auto& s: ret) cout<<s<<endl;
	// sort_food("  pizza  1 hotdog 2.0", 5);
	// sort_food("pizza 500 hotdog 2.0 ", 5);
	// sort_food(" pizza  500 2.0 ", 5);
	return 0;
}

