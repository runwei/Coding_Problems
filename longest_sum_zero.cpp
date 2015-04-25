/*
Find longest continous subarray that sum up to zero.
For example:
{1, 2 -3, 1, 5, -5, 6} should return {2, -3, 1, 5, -5}
*/
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

vector<int> longest_sum_zero(const vector<int> & arr) {
	int begin=0,length=0,sum=0;
	unordered_map<int,int> m_map;
	for (int i=0;i<arr.size();i++) {
		sum+=arr[i];
		if (m_map.count(sum)) {
			if (i-m_map[sum]>length) {
				begin=m_map[sum]+1;
				length=i-m_map[sum];				
			}
		} else m_map[sum]=i;
	}
	return vector<int> (arr.begin()+begin,arr.begin()+begin+length);
}
	
	
int main() {
	vector<int> arr{1, 2, -3, 1, 5, -5, 6};
	vector<int> ret=longest_sum_zero(arr);
	for (auto &i:ret) cout<<i<<" ";
	cout<<endl;
}