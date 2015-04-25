#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<list>
#include<limits.h>
using namespace std;


bool hascycle(const vector<vector<int> >& g) {
	unordered_map<int,bool> visited, returned;
	function<bool(int)> dfs=[&](int i) {
		visited[i]=true;
		for (auto & node:g[i]) {
			if (visited[node] && !returned[node]) return true;
			else if (!visited[node] && dfs(node)) return true;
		}
		returned[i]=true;
		return false;
	};
	for (int i=0;i<g.size();i++) {visited[i]=returned[i]=false;}
	for (int i=0;i<g.size();i++) {
		if (dfs(i)) return true;
	}
	return false;
}

int main() {
	vector<vector<int> >g {{1},{0,2},{0}};
	// int a[]{0, 3, 7, 8, 11, 12};
	// int n=6;
	cout<<hascycle(g);
	return 0;
}