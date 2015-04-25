/*
Given a set of n jobs with [start time, end time, cost] find a subset so that no 2 jobs overlap and the cost is maximum.
DP+二分:
Sort the intervals based on end time
define p(i) for each interval, giving the biggest end point which is smaller than the start point of i-th interval. Use binary search to obtain nlogn
define d[i] = max(w(i) + d[p(i)], d[i-1]).

initialize d[0] = 0
The result will be in d[n] n- the number of intervals.
Overall complexity O(nlogn)
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

