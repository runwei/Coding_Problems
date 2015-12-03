/*
Parse a formula string (only contains “+-()”, no “* /“).
For example,
5 + 2x – ( 3y + 2x - ( 7 – 2x) – 9 ) = 3 + 4y
Parse this string, with a given float of ‘x’ value, output a float for ‘y’ value.
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

double calculatey(string str,int xval){
	function<void(string,vector<double> &)> f=[&](string s, vector<double>& vec) {
		stack<int> m_stack;
		int bracketop=1, lastop=1;
		for (int pos=0;pos<=s.size();++pos) {
			if (s[pos]<='9' && s[pos]>='0') {
				int endpos=pos;
				while (s[endpos]<='9' && s[endpos]>='0') ++endpos;
				if (s[endpos]=='x') {vec[1]+=bracketop*lastop*stoi(s.substr(pos,endpos-pos));pos=endpos;}
				else if (s[endpos]=='y') {vec[2]+=bracketop*lastop*stoi(s.substr(pos,endpos-pos));pos=endpos;}
				else {vec[0]+=bracketop*lastop*stoi(s.substr(pos,endpos-pos));pos=endpos-1;}
			} else if (s[pos]=='x') vec[1]+=bracketop*lastop;
			else if (s[pos]=='y') vec[2]+=bracketop*lastop;
			else if (s[pos]=='+') lastop=1;
			else if (s[pos]=='-') lastop=-1;
			else if (s[pos]=='(') {m_stack.push(lastop);bracketop*=lastop;lastop=1;}
			else if (s[pos]==')') {bracketop/=m_stack.top();m_stack.pop();}
		}
	};
	vector<double> l(3,0),r(3,0);
	int pos=str.find('=');
	f(str.substr(0,pos),l);
	f(str.substr(pos+1),r);
	return (l[0]-r[0]+l[1]*xval-r[1]*xval)/(r[2]-l[2]);
}
	
int main() {
	string str {"x-(y-(5+3y))=3y+2x-1"};
	cout<<calculatey(str,2);
}