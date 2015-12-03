/*
一个线程奇数一个线程偶数，顺序输出
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

mutex m;
condition_variable c;
bool isodd=true;

thread odd([](){
	for (int i=1;i<10;i+=2) {
		unique_lock<mutex>l(m);
		c.wait(l,[&](){return isodd;});
		cout<<i<<endl;
		isodd=!isodd;
		c.notify_one();
	}
});

thread even([](){
	for (int i=2;i<=10;i+=2) {
		unique_lock<mutex> l(m);
		c.wait(l,[&](){return !isodd;});
		cout<<i<<endl;
		isodd=!isodd;
		c.notify_one();
	}
});

int main() {
	odd.join();
	even.join();
	// vector<int> arr {1,4,6,8};
	// vector<int> ret=findmissingnum(arr,4);
	// for (auto &num:ret) cout<<num;
	return 0;
}

