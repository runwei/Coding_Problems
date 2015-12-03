/*
输入一个字符串，它包含的是『食物-重量』对。解析之，按食物重量降序排序输出List. (重量一致可放在一起）
特别情况：

当食物后面跟的也是食物，表明前面的食物是默认重量，比如5.
在例子1中：crab后面直接跟了hotdog，那么crab的重量是5
在例子4中，2.0表示的是食物，这个食物的名字就叫2.0 因为它前面已经完成了
一个食物-重量对（pizza, 500），但是当数字直接出现在食物后，它就一定是重量，
比如例子2，3中的1，500都是重量。
注意：输入字符串前后可能有若干冗余空格，食物/重量之间也可能有冗余空格，请忽略所有冗余空格。

4个例子（默认重量 = 5）：

sort_food("crab hotdog  9.0 chicken 9.2", 5);
sort_food("  pizza  1 hotdog 2.0", 5);
sort_food("pizza 500 hotdog 2.0 ", 5);
sort_food(" pizza  500 2.0 ", 5);
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

