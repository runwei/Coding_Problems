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

ListNode* reverselinkedlist(ListNode* head, int m, int n) {
	ListNode dummy(-1);dummy.next=head;
	ListNode *prev=&dummy, *p2, *p1, *end;
	for (int i=0;i<m-1;i++) prev=prev->next;
	p1=p2=end=prev->next;
	for (int i=0;i<=n-m;++i) p2=p2->next;
	while (p1!=p2) {
		ListNode *sufix=p1->next;
		p1->next=prev->next;
		prev->next=p1;
		p1=sufix;
	}
	end->next=p2;
	return dummy.next;
}

int main() {
	ListNode n1(1), n2(2),n3(3),n4(4),n5(5);
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n4.next=&n5;
	ListNode *ret=reverselinkedlist(&n1,1,4);
	while (ret) {cout<<ret->val<<endl;ret=ret->next;}
	return 0;
}

