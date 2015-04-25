/*
Find the n-th digit of a number which is constructed by concatenation of all natural numbers.
Concatenation of all natural numbers looks like:
1234567891011121314...
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

int findnthdigit(int n) {
	int numdigits=1,maxdigits=9,sumdigits=0;
	while (n>=maxdigits*numdigits){
		n-=maxdigits*numdigits;
		++numdigits;
		sumdigits+=maxdigits;
		maxdigits*=10;
	}
	int ind=(n-1)/numdigits,res=(n-1) % numdigits;
	int value=ind+sumdigits+1;
	for (int k=0;k<numdigits-1-res;++k) value/=10;
	return value %10;
}
	
int main() {
	// cout<<findnthdigit(14);
	for (int i=10;i<16;++i)
	cout<<findnthdigit(i)<<endl;
	
	return 0;
}