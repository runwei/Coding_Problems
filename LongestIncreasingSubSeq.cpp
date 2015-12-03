/*
The longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.
For example, length of LIS for { 10, 22, 9, 33, 21, 50, 41, 60, 80 } is 6 and LIS is {10, 22, 33, 50, 60, 80}.
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
#include "leetcode.h"
using namespace std;

vector<int> longestincreasestr(vector<int> &arr) {
    int n=arr.size();
    vector<int> len(n,1);
    vector<int> pointer(n,-1);
    for (int i=0;i<n;i++) {
        for (int j=0;j<i;j++) {
            if (arr[j]<arr[i] && len[j]+1>len[i]) {
                pointer[i]=j;
                len[i]=len[j]+1;
            }
        }
    }
    vector<int> ret;
    int ind=0;
    for (int i=1;i<n;i++){
        if (len[i]>len[ind]) {
            ind=i;
        }
    }
    while (ind!=-1) {
        ret.push_back(arr[ind]);
        ind=pointer[ind];
    }
	reverse(ret.begin(),ret.end());
    return ret;  
}


int main() {
	vector<int> arr {9, 11, 4, 8, 10, 7, 12, 2, 6};
	vector<int> ret=longestincreasestr(arr);
	for (auto &num:ret) cout<<num<<" ";
    return 0;
}

