/*
There’s a new language which uses the latin alphabet. However, you don’t know the order among letters. You receive a list of words lexicographically sorted by the rules of this new language. From this list, derive one valid particular ordering of letters in this language.

e.g. dictionry:
  {"ze", "yf", "xd", "wd", "vd", "ua", "tt", "sz", "rd",
  "qd", "pz", "op", "nw", "mt", "ln", "ko", "jm", "il",
  "ho", "gk", "fa", "ed", "dg", "ct", "bb", "ba"}
Output:
z, y, x, w, v, u, t, s, r, q, p, o, n, m, l, k, j, i, h, g, f, e, d, c, b, a
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

#include<queue>
#include<list>
#include<limits.h>
using namespace std;

string getorder(const vector<string> &arr) {
	unordered_map<char,vector<char> > m_map;
	for (int i=0;i<arr.size()-1;i++) {
		int p1=0,p2=0;
		while (p1<arr[i].size() && p2<arr[i+1].size()) {
			if (arr[i][p1]!=arr[i+1][p2]) {
				m_map[arr[i+1][p2]].push_back(arr[i][p1]);
				break;
			} else {++p1;++p2;}
		}
	}
	unordered_set<char> visited;
	string ret;
	function<void(char)> dfs=[&] (char c) {
		visited.insert(c);
		for (auto & nc:m_map[c]) {
			if ((!visited.count(nc))) dfs(nc);
		}
		ret.push_back(c);
	};
	for (int i=0;i<26;i++)
		if (!visited.count('a'+i)) dfs('a'+i);
	return ret;
}
	
int main() {
	vector<string> arr {"ze", "yf", "xd", "wd", "vd", "ua", "tt", "sz", "rd","qd", "pz", "op", "nw", "mt", "ln", "ko", "jm", "il","ho", "gk", "fa", "ed", "dg", "ct", "bb", "ba"};
	cout<<getorder(arr)<<endl;
		
	// for (int i=1;i<=n;i++)
	// cout<<findksmallest(arr,i)<<endl;
	
	return 0;
}