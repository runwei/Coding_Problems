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

using _pair=pair<int,int>;
vector<_pair>  insertInterval(vector<_pair> &intervals, _pair newInterval) {
	//find the insert position
	vector<_pair> ret;
	for (auto &elem: intervals) {
		if (elem.second<newInterval.first) ret.push_back(elem);
		else if (elem.first>newInterval.second) {ret.push_back(newInterval);newInterval=elem;}
		else {
			newInterval.first=min(newInterval.first,elem.first);
			newInterval.second=max(newInterval.second,elem.second);
		}
	}
	ret.push_back(newInterval);
	return ret;
}

int main() {
	vector<_pair> m_vec {{1,2},{3,5},{6,7},{8,10},{12,16}};
	_pair newInterval {4,9};
	vector<_pair> ret=insertInterval(m_vec,newInterval);
	for (auto &b:ret) cout<<b.first<<" "<<b.second<<endl;
	return 0;
}