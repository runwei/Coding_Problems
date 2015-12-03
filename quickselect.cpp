#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <algorithm>
using namespace std;



int quickselect(vector<int> &arr,int s,int e, int k) {
	int pos=s;
	for (int i=s;i<e;i++){
		if (arr[i]<arr[e]) swap(arr[i],arr[pos++]); 
	}
	swap(arr[pos], arr[e]);
	if (s+k-1==pos) return arr[pos];
	else if (s+k-1<pos) quickselect(arr,s,pos-1,k);
	else quickselect(arr,pos+1,e,k-(pos+1-s));
}

int main() {
    vector<int> arr{3,4,1,2,6,5,7,0};
	cout<<quickselect(arr,0,arr.size()-1, 3);
    return 0;
}




