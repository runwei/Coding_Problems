/*
Given an unsorted array arr[] and two numbers x and y, find the minimum distance between x and y in arr[]. The array might also contain duplicates. You may assume that both x and y are different and present in arr[].

Examples:
Input: arr[] = {1, 2}, x = 1, y = 2
Output: 1.

Input: arr[] = {2, 5, 3, 5, 4, 4, 2, 3}, x = 3, y = 2
Output: 1.
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

int minimum_number_distance(int a[],int n, int num1, int num2) {
	int pos1=-1, pos2=-1, mindist=INT_MAX;
	for (int i=0;i<n;i++){
		if (a[i]==num1) {
			pos1=i;
			if (pos2!=-1) mindist=min(mindist,pos1-pos2);
		} else if (a[i]==num2) {
			pos2=i;
			if (pos1!=-1) mindist=min(mindist,pos2-pos1);
		}
	}
	return mindist;
}

int main() {
	int a[] {2,5,3,5,4,4,2,3};
	cout<<minimum_number_distance(a,8,2,3);
	
	return 0;
}

