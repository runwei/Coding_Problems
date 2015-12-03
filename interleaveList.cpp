/*
Interleave two linked-list
for example
Given
1->2->3->4
5->6
return 1->5->2->6->3->4
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;


ListNode *interleaveList(ListNode *n1, ListNode *n2) {
	ListNode dummy(-1); ListNode*p=&dummy;
	while (n1 && n2) {
		ListNode *nextn1=n1->next,*nextn2=n2->next;
		p->next=n1;
		n1->next=n2;
		p=n2;
		n1=nextn1;
		n2=nextn2;
	}
	if (n1) p->next=n1;
	else p->next=n2;
	return dummy.next;
}




	
	
int main() {
	ListNode n1(1),n2(2),n3(3),n4(4),n5(5),n6(6);
	n1.next=&n2;
	n2.next=&n3;
	n3.next=&n4;
	n5.next=&n6;
	ListNode *p=interleaveList(&n1,&n5);
	for (auto p0=p;p;p=p->next) cout<<p->val<<" ";
	
	// for (int i=1;i<=n;i++)
	// cout<<findksmallest(arr,i)<<endl;
	
	return 0;
}