/*
有一种integer序列满足以下条件

非负
不能有重复的digit，比如11是不合法的
递增，既后面产生的比前面产生的要大，比如10的下一个数字是12
显然，这组数字的范围为[0, 9876543210]
输入一个一定符合该条件的数字，返回下一个（比输入大但是最小的）数。
如果不存在这样的下一个数，则返回0
For example:
Given 789
Next integer should be 790
Given 98
Next integer should be 102
Given 9876543210
Just return 0
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>

#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

int nextuniquedigitnum (int n) {
	bool num[10];fill_n(num,10,false);
	if (n<0 || n>=9876543210) return 0;
	vector<int> vn;
	while (n) {
		vn.push_back(n %10);
		num[n % 10]=true;
		n/=10;
	}
	for (int i=0;i<vn.size();i++) {
		for (int val=vn[i]+1;val<10;val++) {
			if (!num[val]) {
				num[vn[i]]=false;
				vn[i]=val;
				num[val]=true;
				vector<int> tmparr;
				for (int k=0;k<10;k++) if (!num[k]) tmparr.push_back(k);
				int tmppos=0;
				for (int pos=i-1;pos>=0;--pos)
					vn[pos]=tmparr[tmppos++];
				int ret=0; for (int pos=vn.size()-1;pos>=0;--pos) ret=10*ret+vn[pos];return ret;
			}
		}
		num[vn[i]]=false;
	}
	int ret=0;
	if (vn.size()<10) {
		for (int i=0;i<=vn.size();++i) {
			if (i==0) ret=1;
			else if (i==1) ret=ret*10;
			else ret=ret*10+i;
		}
	}
	return ret;
}

	
int main() {
	cout<<nextuniquedigitnum(789)<<endl;
	cout<<nextuniquedigitnum(987)<<endl;
	
	return 0;
}