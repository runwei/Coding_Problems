/*
写一个程序，找出 5^1234566789893943的从底位开始的1000位数字。
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
using namespace std;

string addstring(const string &s1, const string &s2, int k) {
	int carry=0,pos=0;
	string ret;
	while (pos<k) {
		int num1=pos<s1.size()?s1[pos]-'0':0;
		int num2=pos<s2.size()?s2[pos]-'0':0;
		ret.push_back((num1+num2+carry) % 10+'0');
		carry=(num1+num2+carry)/10;
		++pos;
	}
	return ret;
}

string multiply(const string &s1, const string &s2, int k) {
	string ret(k,'0');
	for (int i=0;i<k;i++)
		for (int j=0;j<k-i;j++) {
			string tmps=to_string( (s1[i]-'0')*(s2[j]-'0'));
			tmps.append(i+j,'0');
			reverse(tmps.begin(),tmps.end());
			ret=addstring(ret,tmps,k);
		}
		return ret;
}	

string get_power_digits(int m, long long n, int k) {
	string tmps=to_string(m);
	reverse(tmps.begin(),tmps.end());
	tmps.append(k-tmps.size(),'0');
	string ret(k,'0');ret[0]='1';
	while (n>0) {
		if (n%2) ret=multiply(ret,tmps,k);
		n/=2;
		tmps=multiply(tmps,tmps,k);
	}
	reverse(ret.begin(),ret.end());
	return ret;
}




	
	
int main() {
	cout<<pow(5,8)<<endl;
	cout<<get_power_digits(5,8,4);
		
	// for (int i=1;i<=n;i++)
	// cout<<findksmallest(arr,i)<<endl;
	
	return 0;
}