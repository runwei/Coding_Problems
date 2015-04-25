/*
Given a array of pairs where each pair contains the start and end time of a meeting (as in int),
Determine if a single person can attend all the meetings
For example:
Input array { pair(1,4), pair(4, 5), pair(3,4), pair(2,3) }
Output: false

Follow up:
determine the minimum number of meeting rooms needed to hold all the meetings.
Input array { pair(1, 4), pair(2,3), pair(3,4), pair(4,5) }
Output: 2

http://www.fgdsb.com/2015/01/30/meeting-rooms/
*/


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

int findlowerbound(vector<pair<int,int> >&meetings, int i);
bool attend_all(vector<pair<int,int> > & meetings) {
	auto f=[&](const pair<int,int> &a,const pair<int,int> &b){
		return a.first<b.first;
	};
	sort(meetings.begin(),meetings.end(),f);
	for (int i=1;i<meetings.size();i++) 
		if (meetings[i-1].second>meetings[i].first) return false;
	return true;
}

int min_rooms(vector<pair<int,int> >& meetings) {
	vector<pair<int,int> > _time;
	for (auto& m:meetings) {
		_time.push_back({m.first,1});
		_time.push_back({m.second,-1});
	}
	auto f=[&](const pair<int,int> &a,const pair<int,int> &b) {
		if (a.first<b.first) return true;
		else if (a.first>b.first) return false;
		else return a.second<b.second;
	};
	sort(_time.begin(),_time.end(),f);
	int minroom=0,curroom=0;
	for (auto &t:_time) {
		if (t.second==1) ++curroom;
		else --curroom;
		minroom=max(minroom,curroom);
	}
	return minroom;
} 

int max_weight(vector<pair<int,int> >&meetings) {
	auto f=[&](const pair<int,int> &a, const pair<int,int> &b){
		return a.second<b.second;
	};
	sort(meetings.begin(),meetings.end(),f);
	if (meetings.empty()) return 0;
	int n=meetings.size();
	vector<int> weights(n,0);
	for (int i=0;i<n;i++){
		int pos=findlowerbound(meetings,i);
		int num1=pos==-1?0:weights[pos];
		num1+=meetings[i].second-meetings[i].first;
		int num2=i==0?0:weights[i-1];
		weights[i]=max(num1,num2);
	}
	return weights[n-1];
}

int findlowerbound(vector<pair<int,int> >&meetings, int i){
	if (i==0 || meetings[i].first<meetings[0].second) return -1;
	int left=0,right=i; 
	while (left+1<right) {
		int mid=(left+right)/2;
		if (meetings[i].first<meetings[mid].second) right=mid;
		else left=mid;
	}
	return left;
}


int main(){
	vector<pair<int,int> > meetings{{1,5}, {3,6}, {6,9} };
	cout<<max_weight(meetings);
	return 0;
}