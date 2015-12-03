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
// #include "leetcode.h"
using namespace std;

class BigInt {
public:
	BigInt(const string& s) {
		vector<long long> result;
		result.reserve(s.size()/RADIX_LEN+1);
		int pos=s.size();
		while (pos>0) {
			int tmp=0;
			if (pos>RADIX_LEN) {
				for(int i=0;i<RADIX_LEN;++i)
					tmp=10*tmp+(s[pos-RADIX_LEN+i]-'0');
			} else {
				for (int i=0;i<pos;++i)
					tmp=10*tmp+(s[i]-'0');				
			}
			result.push_back(tmp);
			pos-=RADIX_LEN;
		}
		elem=result;
	}
	BigInt(const vector<long long> num): elem(num){}
	
	string toString() {
		string ret;
		for(auto &val:elem) ret=to_string(val)+ret;
		// while (ret.back()=='0') ret.pop_back();
		return ret;
	}
	static BigInt multiply(const BigInt &x, const BigInt &y) {
		vector<long long> z(x.elem.size()+y.elem.size(),0);
		for (int i=0;i<x.elem.size();++i)
			for(int j=0;j<y.elem.size();++j) {
				z[i+j]+=(y.elem[i]*x.elem[j]) % RADIX_VAL;
				z[i+j+1]+=(y.elem[i]*x.elem[j]) /RADIX_VAL;
			}
		return BigInt(z);
	}
private:
	const static int RADIX_LEN=9;
	const static int RADIX_VAL=1000000000;
	vector<long long> elem;
};

int main(){
	BigInt x1 {"123456789123456789"};
	BigInt x2 {"987654321987654321"};
	BigInt ret= BigInt::multiply(x1,x2);
	cout<<ret.toString();
	return 0;
}

