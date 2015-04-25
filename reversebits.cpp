/*
Reverse bits of an unsigned integer.
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
// #include "leetcode.h"
using namespace std;

uint8_t reversebits(uint8_t num) {
	uint8_t ret,count=8;
	while (count) {
		ret=(ret<<1) | (num & 1);
		num>>=1;
		--count;
	}
	return ret;
}

int main() {
	cout<<reversebits(5);
	return 0;
}

