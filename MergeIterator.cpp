/*
输入为一个Iterator数组，这些Iterator分别取出来的数都是已排序的，设计并实现一个MergeIterator类，merge这些sorted iterator。
你的MergeIterator类需要包含has_next和get_next方法。
注意，Iterator也只包含has_next和get_next方法。
G家的onsite题，实际上就是多路归并，用一个heap就可以搞定，注意类的细节设计即可。
看过一个面经，面试者跟面试官说Iterator的接口需要有个peek()函数（即只看，不move），实际上是可以不需要的。
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

class Iterator {
public:
	Iterator (vector<int>&& data):_data(move(data)) {}
	int get_next() {return _data[_pointer++];}
	bool has_next() {return _pointer<_data.size();}
private:
	vector<int> _data;
	size_t _pointer{0};
};


class MergeIterator {
public:
	using _pair=pair<int,int>;//value, vecid
	MergeIterator(vector<Iterator> arr): streams(arr) {	
		for (int i=0;i<streams.size();i++) {
			if(streams[i].has_next()) {
				heap.push({streams[i].get_next(),i});
			}
		}
	}
	bool has_next() {return !heap.empty();}
	int get_next() {
		pair<int,int> tmp=heap.top();
		heap.pop();
		if (streams[tmp.second].has_next()) 
			heap.push({streams[tmp.second].get_next(),tmp.second});
		return tmp.first;
	}
private:
	vector<Iterator> streams;
	priority_queue<_pair,vector<_pair>, function<bool(_pair &,_pair &)> > heap {
		[](_pair& a ,_pair &b) {return a.first>b.first;}
	};
};

int main(){
	Iterator i1{{1,3,5}};
	Iterator i2{{2,4,6}};
	MergeIterator mi({i1,i2});
	while(mi.has_next()) 
		cout << mi.get_next() << endl;
	 // for (auto &c:A) cout<<c<<" ";
	return 0;
}