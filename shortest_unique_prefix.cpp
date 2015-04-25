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
#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

struct Node {
	char val;
	int num{0};
	Node* children[27];
	Node (const char &c): val(c) {}
	Node* getchar(const char &c, const bool flag=true){
		int ind=c=='\0'?26:c-'a';
		if (!children[ind] && flag) {
			children[ind]= new Node(c);
			++num;
		}
		return children[ind];
	}
	~Node() {
		for (int i=0;i<27;i++) 
			if (children[i]){
				delete children[i];
				children[i]=NULL;
			}
	}
};

class Trie {
public:
	void addstring(const string& s) {
		auto p=root;
		for (auto &c:s) {
			p=p->getchar(c);
		}
		p->getchar('\0');
	}
	Trie(){
		root= new Node(-1);
	}
	
	bool existstring(const string &s) {
		auto p=root;
		for (auto &c:s) {
			p=p->getchar(c,false);
			if (!p) return false;
		}
		return p->getchar('\0',false);
	}
	
	string findshortestprefix(const string &s) {
		auto p=root;
		string ret;
		for (auto &c:s) {
			p=p->getchar(c);ret.push_back(c);
			if (!p) return "";
			else if (p->num==1) return ret;
		}
		return "";
	}
	~Trie(){
		delete root;
	}
private:
	Node *root;
};


int main() {
	vector<string> arr{"zebra", "dog", "duck","dot"};
	Trie t;
	for (auto&s :arr) t.addstring(s);
	
	cout<<t.existstring("zeb")<<endl;
	cout<<t.existstring("dog")<<endl;
	cout<<t.existstring("dit")<<endl;
	
	for (auto&s: arr) {
		cout<<s<<":"<<t.findshortestprefix(s)<<endl;
	}
	
	// vector<int> arr {1,4,6,8};
	// vector<int> ret=findmissingnum(arr,4);
	// for (auto &num:ret) cout<<num;
	return 0;
}

