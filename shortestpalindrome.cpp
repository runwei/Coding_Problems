/*
Given a string S, you are allowed to convert it to a palindrome by adding 0 or more characters in front of it.
Find the length of the shortest palindrome that you can create from S by applying the above transformation.

Examples:
cca -> 1
aba -> 0
acb -> 2
abcb -> 3
abb -> 2
abcdefg -> 6
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

int shortest_palindrome(string s){
	int n=s.size();
	s=s+'#'+string(s.rbegin(),s.rend());
	vector<int> f(2*n+2,0);
	int p1=0,p2=2;
	while (p2<=2*n+1) {
		if (s[p1]==s[p2-1]) {f[p2++]=++p1;}
		else if (p1==0) f[p2++]=0;
		else p1=f[p1];
	}
	return n-f[2*n+1];
}

int main() {
	cout<<shortest_palindrome("cca")<<endl;
	cout<<shortest_palindrome("aba")<<endl;
	cout<<shortest_palindrome("acb")<<endl;
	cout<<shortest_palindrome("abcb")<<endl;
	cout<<shortest_palindrome("abb")<<endl;
}