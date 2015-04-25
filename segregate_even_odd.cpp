/*
Given an array A[], write a function that segregates even and odd numbers. The functions should put all even numbers first, and then odd numbers.

Example
Input = {12, 34, 45, 9, 8, 90, 3}
Output = {12, 34, 8, 90, 45, 9, 3}*/


#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
using namespace std;


int segregates_even_odd(vector<int> &arr) {
	int count=0;
	for (int i=0;i<arr.size();i++)
		if (arr[i] %2==0) swap(arr[i],arr[count++]);
	return count;
}

int main(){
	vector<int> A{12, 34, 45, 1,5,3,8,5,7,8,9, 8, 90, 3};
	 cout<<segregates_even_odd(A)<<endl;
	 
	 for (auto &c:A) cout<<c<<" ";
	return 0;
}