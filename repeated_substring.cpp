/*
有一种String,是把一个更短的String重复n次而构成的，那个更短的String长度至少为2，输入一个String写代码返回T或者F
例子：
"abcabcabc" true 因为它把abc重复3次构成
"bcdbcdbcde" false 最后一个是bcde
"abcdabcd" true 因为它是abcd重复2次构成
"xyz" false 因为它不是某一个String重复
"aaaaaaaaaa" false 重复的短String长度应至少为2（这里不能看做aa重复5次)

要求算法复杂度为O(n)
KMP algorithm
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>

#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

bool repeated_substring(const string &s) {
	if (s.empty()) return true;
	int n=s.size(), pos=1,len=1;
	bool flag=false;
	while (pos<n) {
		int i; 
		for (i=0;i<len;i++) {
			if (i+pos>=n) {flag=true;break;}
			if (s[i]!=s[i+pos]) {
				pos=len=i+pos+1;
				break;
			}
		}
		if (flag) break;
		if (i==len) pos+=len;
	}
	if (flag) return false;
	return (!(len==n)) && len!=1;
}


int main() {
	// cout<<repeated_substring("absabs")<<endl;
	// cout<<repeated_substring("absabsa")<<endl;
	cout<<repeated_substring("aaaaaaaaaa")<<endl;
	
	return 0;
}

