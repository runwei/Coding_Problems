/*
输入一个数组，返回数组元素的surpasser个数的最大值。
数组元素a[i] 的surpasser是指元素a[j], j > i， a[j] > a[i]。
比如[10, 3, 7, 1, 23, 14, 6, 9] 这个数组中10的surpasser是23,14，个数是2。而3的surpasser是7,23,14,6,9，个数为5，并且是最多的一个。所以返回5。
利用特殊数据结构的话，本题有很多种做法，比如BST，线段树，点树，树状数组。下面给出一种归并排序思路的解法。实际上跟Inverse Pairs基本是完全一样的。这里关心的是顺序而不是逆序。
大体思路就是在降序归并排序的过程中每次遇到顺序对就记录下来，比如merge的过程中两个元素分别是3和7，3 < 7，所以3的顺序数+1。最后merge sort完毕后，每个顺序数的个数我们都知道，返回最大值即可。
思路很简单，唯一tricky的地方就是每次遇到顺序的时候，这个顺序数的个数到底加多少。这个需要注意一下。
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

bool pow4(int num) {
	if (num<=0) return false;
	return (0x55555555 & num) && !(num & (num-1));
}


int main() {
	cout<<pow4(3);
}