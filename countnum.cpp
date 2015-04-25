/*
Given an array of ages (integers) sorted lowest to highest, output the number of occurrences for each age.
For instance:
[8,8,8,9,9,11,15,16,16,16]
should output something like:
*/
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

vector<vector<int> > countnum(const vector<int> &arr) {
	vector<vector<int> > ret;
	if (arr.empty()) return ret;
	int n=arr.size(),i=1,cur_num=arr[0],cur_count=1;
	while (i<n) {
		if (arr[i]!=cur_num) {
			ret.push_back({cur_num,cur_count});
			cur_num=arr[i];
			cur_count=0;
		} else {
			int step=1;
			while (i+step*2<n && arr[i+step*2]==cur_num) step*=2;
			i+=step;cur_count+=step;
		}
	}
	ret.push_back({cur_num,cur_count});
	return ret;
}

int main() {
	vector<int> arr {8,8,8,9,9,11,15,16,16,16};
	vector<vector<int> > ret=countnum(arr);
	for (auto &entry:ret) {
		cout<<entry[0]<<" "<<entry[1]<<endl;
	}
	return 0;
}