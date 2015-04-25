/*
Given a integer array, please determine if it is a postorder traversal result of an arbitrary Binary Search Tree.
For example:

{5,7,6,9,11,10,8} is valid
{7,4,6,5} is not valid
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

bool validbstpostorder(int a[],int n) {
	if (n<=2) return true;
	int pivot=a[n-1], ind=0;
	while (a[ind]<pivot && ind<n-1) ++ind;
	for (int i=ind;i<n-1;i++)
		if (a[i]<pivot) return false;
	return validbstpostorder(a,ind) && validbstpostorder(a+ind,n-ind-1);
}

int main() {
	int arr[] {7,4,6,5};
	cout<< validbstpostorder(arr,7);
	return 0;
}

