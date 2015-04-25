/*
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example, if length of the rod is 8 and the values of different pieces are given as following, then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

Example:
Pricing list: {1, 5, 8, 9, 10, 17, 17, 20}
Result = 22 (cut into two pieces of length 2 and 6)*/
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

int cutting_rod(const vector<int> & price) {
	int n=price.size();
	vector<int> value(price);
	for (int i=0;i<n;i++) {
		for (int j=0;j<i;j++) {
			value[i]=max(value[i],value[j]+value[i-j-1]);
		}
	}
	return value[n-1];
}
	
	
int main() {
	cout<<cutting_rod({1, 5, 8, 9, 10, 17, 17, 20});
}