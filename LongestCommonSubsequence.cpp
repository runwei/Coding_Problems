/*
LCS Problem Statement: Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.
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

string LongestCommonSubsequence(const string &s1, const string &s2) {	
	int m=s1.size(),n=s2.size();
	vector<vector<int> >f(m+1,vector<int> (n+1,0));
	for (int i=1;i<=m;i++)
		for (int j=1;j<=n;j++){
			f[i][j]=max(f[i][j-1],f[i-1][j]);
			f[i][j]=max(f[i][j],s1[i-1]==s2[j-1]?f[i-1][j-1]+1:f[i-1][j-1]);
		}
	string ret;
	function<void(int,int)> backtrack=[&](int i,int j){
		if (i==0 || j==0) return;
		else if (s1[i-1]==s2[j-1]) {
			ret.push_back(s1[i-1]);
			backtrack(i-1,j-1);
		}
		else if (f[i-1][j]>f[i][j-1]) backtrack(i-1,j);
		else backtrack(i,j-1);
	};
	backtrack(m,n);
	reverse(ret.begin(),ret.end());
	return ret;
}


	
	
int main() {
	string s1="abcdefghij";
	string s2="accbdeffag";
	cout<<LongestCommonSubsequence(s1,s2);
	return 0;
}