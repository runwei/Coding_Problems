/*
输出count最多的连续的字符。
For example:
"this is a sentence" => [t, h, i, s, i, s, a, s, e, n, t, e, n, c, e]
"thiis iss a senntencee" => [i, s, n, e]
"thiisss iss a senntttenceee" => [s, t, e]
"thiisss iss a sennnntttenceee" => [n]
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
#include "leetcode.h"
using namespace std;

string LongestContinuousLetter(const string &s) {
	string ret;
	if (s.empty()) return ret;
	int dnum=1,curnum=1;
	char c=s[0];
	for (int i=1;i<=s.size();i++){
		if (s[i]==c && i<s.size()) ++curnum;
		else {
			if (curnum==dnum) ret.push_back(c);
			else if (curnum>dnum) {
				ret.clear();ret.push_back(c);dnum=curnum;
			}
			curnum=1;
			if (i<s.size()) c=s[i];
		}
	}
	return ret;
}
	
	
int main() {
	cout<<LongestContinuousLetter("aabbbccc");
	return 0;
}