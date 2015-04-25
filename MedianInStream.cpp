/*
Create the data structure for a component that will receive a series of numbers over the time and, when asked, returns the median of all received elements.
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



class Onlinemedian {
private:
	priority_queue<int,vector<int>, less<int> > s_small;// {[](int a,int b) {return a<b;}};
	priority_queue<int,vector<int>, greater<int> > s_large;// {[](int a,int b) {return a>b;}};
public:
	void addnum (int num) {
		if (s_small.empty() || s_small.top()>=num) s_small.push(num);
		else s_large.push(num);
		if (s_small.size()>s_large.size()+1) {s_large.push(s_small.top());s_small.pop();}
		else if (s_small.size()<s_large.size()) {s_small.push(s_large.top());s_large.pop();}
	}
	double getmedian() {
		if (s_small.empty() && s_large.empty()) return INT_MIN;
		else if (s_small.size()==s_large.size()) return (s_small.top()+s_large.top())/2.0;
		else return s_small.top();
	}
};
	
int main() {
	vector<int> arr {1,3,2,5,4,6};
	Onlinemedian o; 
	for (auto & n:arr) {
		o.addnum(n);
		cout<<o.getmedian()<<endl;
	}
	return 0;
}