/*
Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, …
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 150’th ugly number.

http://www.geeksforgeeks.org/ugly-numbers/
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>
#include<unordered_set>

#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

int uglynumber(int n) {
	int num[n],pos1=0,pos2=0,pos3=0,pos=0;
	num[0]=1;
	for (int i=1;i<n;i++) {
		int num2=num[pos1]*2;
		int num3=num[pos2]*3;
		int num5=num[pos3]*5;
		int bestnum=min(min(num2,num3),num5);
		num[++pos]=bestnum;
		if (bestnum==num2) ++pos1;
		if (bestnum==num3) ++pos2;
		if (bestnum==num5) ++pos3;
	}
	return num[n-1];
}

int main() {
	cout<<uglynumber(11);
	return 0;
}

