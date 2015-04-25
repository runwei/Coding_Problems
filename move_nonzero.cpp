/*
写一个程序，找出 5^1234566789893943的从底位开始的1000位数字。
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

int movezeroplus(vector<int> & arr) {
	int first=0,second=arr.size()-1;
	while (first<second) {
		while (first<second && arr[first]) ++first;
		while (first<second && !arr[second]) --second;
		if (first<second) arr[first++]=arr[second--];
	}
	if (arr[first]) ++first;
	return first;
}


	
int main() {
	vector<int> arr {2,0,1,0,0,3,1};
	int num=movezeroplus(arr);
	for (int i=0;i<num;++i) cout<<arr[i]<<" ";
	return 0;
}