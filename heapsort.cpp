#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<limits.h>
using namespace std;

void sink(vector<int> &array, int i, int n);
void heapsort(vector<int> &array) {
	int n=array.size();
	for (int i=n/2-1;i>=0;i--)
		sink(array,i,n);
	while (n>0){
		swap(array[0],array[--n]);
		sink(array,0,n);
	}
}

void sink(vector<int> &array, int i, int n) {
	while (i<n) {
		int left=i*2+1<n?array[i*2+1]:INT_MIN;
		int right=i*2+2<n?array[i*2+2]:INT_MIN;
		if (array[i]>=left && array[i]>=right) break;
		if (left>right) {swap(array[i*2+1],array[i]); i=i*2+1;}
		else {swap(array[i*2+2],array[i]);i=i*2+2;}
	}
}




int main() {
	int A[]={4,2,8,5,3,3,5,1,2,3,1,3,5,6,9,1,8,7,8,2,3};
	vector<int> vecA(A,A+sizeof(A)/sizeof(int));
	heapsort(vecA);
	for (auto& i:vecA) cout<<i<<" ";
	return 0;
}