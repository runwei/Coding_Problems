/*
remove minimum number of left and right brackets and return the string with 
valid bracket pairs. given (a))()), should return (a)(), or (a()); given )()
()), should return either ()() or (()); given ()((9()), should return either
()(9()) or ()((9)).

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

string removebrackets(const string & s){
	string ret;
	int leftbracket=0,rightbracket=0;
	unordered_set<int> indset;
	for (int i=0;i<s.size();++i){
		if (s[i]=='(') ++leftbracket;
		else if (s[i]==')') ++rightbracket;
		if (rightbracket>leftbracket) {
			indset.insert(i);
			rightbracket=leftbracket;
		}
	}
	leftbracket=0;rightbracket=0;
	for (int i=s.size()-1;i>=0;--i){
		if (s[i]=='(') ++leftbracket;
		else if (s[i]==')') ++rightbracket;
		if (leftbracket>rightbracket) {indset.insert(i);leftbracket=rightbracket;}
	}
	for (int i=0;i<s.size();++i)
		if (!indset.count(i))
			ret.push_back(s[i]);
	return ret;
}


	
int main() {
	cout<<removebrackets("(a))())")<<endl;
	cout<<removebrackets(")()())")<<endl;
	cout<<removebrackets("()((9())")<<endl;
	return 0;
}