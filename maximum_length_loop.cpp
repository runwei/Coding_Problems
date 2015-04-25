/*maximum length of a loop
Given an array
Indexes 0 1 2 3 4
Values 3 2 1 4 0
Values are the next index of the jump 0 -> 3 -> 4 -> 0... 1 -> 2 -> 1...
Write a function to detect if there are loops. If yes, get the max length of the loop possible, otherwise just return zero.
G家题，实际上就是有向图找最大环。POJ有类似题。用一个DFS走一遍就好，用两个数组，一个记录visited，一个记录走过的长度。
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
using namespace std;

int max_length(const vector<int>& arr) {
	int n=arr.size();
	bool visited[n];fill_n(visited,n,false);
	bool returned[n];fill_n(returned,n,false);
	int length[n];fill_n(length,n,0);
	int maxloop=0,count=0;
	bool flag=false;//whether there is a loop
	function<void(int)> dfs=[&](int i)->void {
		visited[i]=true;
		length[i]=count++;
		if (!visited[arr[i]]) dfs(arr[i]);
		else if (visited[arr[i]] && !returned[arr[i]]) {
			maxloop=max(maxloop,count-length[arr[i]]);
			flag=true;
		}  
		--count;
		returned[i]=true;
	};
	for (int i=0;i<n;i++) dfs(i);
	return flag?maxloop:0;
}



int main(){
	vector<int> A1{1,2,3,4,0};
	vector<int> A2{3,5,1,6,2,4,0};
	vector<int> A3{2,2,2,2};
	vector<int> A4{3,2,1,4,0};
	vector<int> A5{1,2,3,4,2,0};
	
	cout<<max_length(A1)<<endl;
	cout<<max_length(A2)<<endl;
	cout<<max_length(A3)<<endl;
	cout<<max_length(A4)<<endl;
	cout<<max_length(A5)<<endl;
	
	return 0;
}