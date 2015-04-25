/*
Abbreviation: apple can be abbreviated to 5, a4, 4e, a3e, …
If given a string and an abbreviation, return if the string matches abbr.
Assume the original string only contains alphabetic characters.
For example:
“internationalization”, “i5a11o1” -> true
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

bool abbreviation(const string &s1, const string &s2) {
	int p1=0,p2=0;
	while (p2<s2.size()) {
		if (!isdigit(s2[p2])) {
			if (s2[p2]==s1[p1]) {++p1;++p2;}
			else return false;
		} else {
			int num=0;
			while (isdigit(s2[p2])) {num=num*10+s2[p2]-'0';++p2;}
			if (p1+num>s1.size()) return false;
			else p1+=num;
		}
	}
	return p1==s1.size();
}


int main() {
	cout<<abbreviation("internationalizationN","i5a11o2");
	return 0;
}