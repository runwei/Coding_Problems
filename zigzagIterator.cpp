/*
检查一个字符串是否包含k位a进制数的所有表示形式。
保证原字符串的所有字串都是合法的k位a进制数。"00110", a=2, k=2 => true （包括了00，01，10，11）
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
    Iterator(vector<int>&& data) : _data(move(data)) {}
    int get_next() { return _data[_pointer++]; }    
    bool has_next() { return _pointer < _data.size(); }
    
private:
    vector<int> _data;
    size_t _pointer{ 0 };
};

class ZigzagIterator {
public: 
	ZigzagIterator(const vector<Iterator> &arr):arr(arr) {}
	int getnext(){
		int ret=arr[pos].getnext();
		pos=(pos+1) %arr.size();
		return ret;
	}
	bool hasnext(){
		if (arr[pos].hasnext()) return true;
		int oldpos=pos++;
		while (!arr[pos].hasnext() && oldpos!=pos) pos=(pos+1) % arr.size();
		return !(pos==oldpos);
	}
	vector<Iterator> arr;
	int pos=0;
};

int main(){
	vector<int> arr1 {1,3,5,7};
	vector<int> arr2 {2,4,6,8};
	vector<Iterator> vecIt;
	vecIt.push_back(Iterator(arr1));
	vecIt.push_back(Iterator(arr2));
	ZigzagIterator ItZ(vecIt);
	while (ItZ.hasnext()) cout<<ItZ.getnext()<<endl;
	return 0;
}