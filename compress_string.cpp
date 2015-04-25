/*
Implement a function to perform basic string compression using the counts of repeated characters.
For example, the string aabcccccaaa would become a2b1c5a3.
If the “compressed” string would not become smaller than the original string, you should return the original one.
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

string str_compress(const string &s) {
	if (s.empty()) return "";
	int num=1;char c=s[0];string ret;
	for (int i=1;i<=s.size();i++) {
		if (i<s.size()&& s[i]==c) ++num;
		else {
			ret+=c;
			ret+=to_string(num);
			num=1;
			c=s[i];
		}
	}
	return ret.size()<s.size()?ret:s;
}


int main() {
	cout<<str_compress("aabcccccaaa");
	return 0;
}