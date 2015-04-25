/*
Given a string S, find the longest palindromic substring in S.
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<list>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
#include "BST.h"
using namespace std;


string longest_palidrome(string s) {
	int n=s.size();
	if (n<2) return s;
	int maxlen=0,start=0;
	bool f[n][n];
	for (int j=0;j<n;++j)
		for (int i=j;i>=0;--i) {
			f[i][j]=s[i]==s[j] && (j-i<2 || f[i+1][j-1]);
			if (f[i][j] && j-i+1>maxlen) {
				maxlen=j-i+1;
				start=i;
			}
		}
	return s.substr(start,maxlen);
}

	
int main() {
	cout<<longest_palidrome("abbac");
}