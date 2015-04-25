/*
Get maximum binary Gap.
For example, 9’s binary form is 1001, the gap is 2.
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

int max_bin_gap(int num) {
	int maxcount=0,lastpos=-1,curpos=0;
	while (num) {
		if(num & 1) {
			if (lastpos!=-1) maxcount=max(maxcount,curpos-lastpos-1);
			lastpos=curpos;
		}
		++curpos;num>>=1;
	}
	return maxcount;
}
	
	
int main() {
	
	cout<<max_bin_gap(9);
	return 0;
}