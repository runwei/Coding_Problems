#ifndef UNION_FIND_H
#define UNION_FIND_H

#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<limits.h>
using namespace std;

class unionfind {
private:
	int* key;
	int* weight;
	int size;
public:
	unionfind(const int n=10): size(n){
		key=new int[n];
		weight=new int[n];
		for (int i=0;i<n;i++) {key[i]=i;weight[i]=1;}
	}
	~unionfind(){
		delete []key;
		delete []weight;
	}
	bool isconnected(int a, int b) {
		return root(a)==root(b);
	}
	int root(int a){
		while (a!=key[a]) a=key[a];
		return a;
	}
	void connect(int a, int b){
		int roota=root(a);
		int rootb=root(b);
		if (roota==rootb) return;
		if (weight[roota]>weight[rootb])  {
			key[rootb]=roota;
			weight[roota]+=weight[rootb];
			weight[rootb]=0;
		} else {
			key[roota]=rootb;
			weight[rootb]+=weight[roota];
			weight[roota]=0;
		} 
	}
};
#endif	
//
//
//
// int main() {
// 	unionfind u=unionfind();
// 	u.connect(0,1);
// 	u.connect(1,3);
// 	cout<<u.isconnected(1,3)<<endl;
// 	cout<<u.isconnected(1,4)<<endl;
// 	return 0;
// }