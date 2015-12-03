/*
Given a string which only contains lowercase. You need delete the repeated letters only leave one, and try to make the lexicographical order of new string is smallest. 
i.e: 
bcabc 
You need delete 1 'b' and 1 'c', so you delete the first 'b' and first 'c', the new string will be abc which is smallest. 

ps: If you try to use greedy algorithm to solve this problem, you must sure that you could pass this case: 
cbacdcbc. answer is acdb not adcb 

I can't solve this problem well and the interviewer said that you can scan the string twice. First scan is do some preprocess, and the second is to get the answer, but I really can't come up this idea.
*/

#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<unordered_map>
#include<queue>
#include<stack>
#include<limits.h>
using namespace std;

vector<int> deleteNode(vector<int>&arr, int index) {
	if (arr.empty()) return {};
	int n=arr.size();
	vector<int> arr2(n,-1);
	function<bool(int)> dfs=[&] (int i) {
		if (arr2[i]==1) return true;
		else if (arr2[i]==0) return false;
		else {
			if (i==index || ((i!=arr[i])&& dfs(arr[i]))){
				arr2[i]=1;
				return true;
			} else {
				arr2[i]=0;
				return false;
			}
		}
	};
	for (int i=0;i<n;++i) dfs(i);
	int count=0;
	for(int i=0;i<n;++i) 
		if (arr2[i]==0) arr2[i]=count++;
		else arr2[i]=-1;
	vector<int> ret;
	for (int i=0;i<n;++i) {
		if (arr2[i]!=-1) ret.push_back(arr2[arr[i]]);
	}
	return ret;
}



int main() {
	vector<int> citations {3,1,4,1,5,7,2,7};
	vector<int> ret=deleteNode(citations,1);
	for(auto& n: ret) cout<<n<<" ";
}