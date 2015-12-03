/*
Write a function to calculate x * 7 without using + - / * %.
x * 7可以做如下分解：
x * 7 = x * 4 + x * 2 + x
= (x << 2) + (x << 1) + x
= add(x << 2, add(x << 1, x))
所以本质上这题就是考用二进制实现add函数。
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

int add(int a,int b) {
	int sum;
	while (b) {
		sum=a^b;
		//carry
		b=(a&b)<<1;
		a=sum;
	}
	return a;
}

int times7(int x) {
	int tmp1=x<<1, tmp2=x<<2;
	return add(add(x,tmp1),tmp2);
}

int main() {
	cout<<times7(2);
	return 0;
}