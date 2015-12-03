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
	int bitnum=1,roundnum=9,totalnum=0;
	while (n>roundnum*bitnum){
		n-=roundnum*bitnum;
		++bitnum;
		totalnum+=roundnum;
		roundnum*=10;
	}
	int ind=(n-1)/bitnum,res=(n-1) % bitnum;
	int value=ind+totalnum+1;
	for (int k=0;k<bitnum-1-res;++k) value/=10;
	return value %10;
}
	
int main() {
	// cout<<findnthdigit(14);
	for (int i=10;i<16;++i)
	cout<<findnthdigit(i)<<endl;
	return 0;
}