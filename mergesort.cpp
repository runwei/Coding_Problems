#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<limits.h>
using namespace std;

void mergesort(vector<int> &array) {
	vector<int> newarray(array);
	function<void(int,int,int,int)> mergeTwosortedarray=[&](int s1,int e1,int s2, int e2){
		int left=s1, right=s2,pos=s1;
		for (int i=s1;i<=e2;i++) newarray[i]=array[i];
		while (left<=e1 || right<=e2) {
			int val1=left<=e1?newarray[left]:INT_MAX;
			int val2=right<=e2?newarray[right]:INT_MAX;
			if (val1<val2) {
				array[pos++]=val1; ++left;
			} else {array[pos++]=val2;++right;}
		}
	};
	function<void(int,int)> mergesorthelper=[&](int start,int end) {
		if(start>=end) return;
		int mid=(start+end)/2;
		mergesorthelper(start,mid);
		mergesorthelper(mid+1,end);
		mergeTwosortedarray(start,mid,mid+1,end);
	};
	mergesorthelper(0,(int)array.size()-1);
}



int main() {
	int A[]={4,2,1,3,5,6};
	vector<int> vecA(A,A+sizeof(A)/sizeof(int));
	mergesort(vecA);
	for (auto& i:vecA) cout<<i<<" ";
	return 0;
}