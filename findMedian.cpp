#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int findKelement(int A[], int m,int B[], int n, int k) {
	if (m<n) return findKelement(B,n,A,m,k);
	if (n==0) return A[k-1];
	if (k==1) return min(A[0],B[0]);
	int right=min(n,k/2);
	int left=k-right;
	if (A[left-1]<B[right-1]) return findKelement(A+left,m-left,B,n,k-left);
	else if (A[left-1]>B[right-1]) return findKelement(A,m,B+right,n-right,k-right);
	else return A[left-1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
	if ((m+n) %2==0) 
	return (findKelement(A,m,B, n,(m+n)/2) +findKelement(A,m,B,n, (m+n)/2+1))/2.0;
	else return findKelement(A,m,B,n, (m+n)/2+1);
}



int main() {
	int A[]={1,2};
	int B[]={1,2};
	cout<<findMedianSortedArrays(A,2,B,2)<<endl;
	return 0;
}