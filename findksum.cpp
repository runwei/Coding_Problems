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

vector<vector<int> > findksum(vector<int> &arr, int sum, int k) {
	vector<vector<int> > ret;
	if (arr.size()<k) return {{}};
	int n=arr.size();
	sort(arr.begin(),arr.end());
	vector<int> state;
	function<void(int,int)> backtrack=[&](int pos,int num) {
		if (num==k) {
			int val=0;
			for (auto &ns:state) val+=ns;
			if (val==sum) ret.push_back(state);
		} else  if (pos>=n) return;
		else {
			for (int i=pos;i<n;++i) {
				if (i!=pos && arr[i]==arr[i-1]) continue;
				else  {
					state.push_back(arr[i]);
					backtrack(i+1,num+1);
					state.pop_back();
				}
			}
		}
	};
	backtrack(0,0);
	return ret;
}


int main() {
	vector<int> arr{-1,0,1,2,-1,-4};
	vector<vector<int> > ret=findksum(arr,0,3);
	for (auto & vec: ret) {
		for(auto & n:vec) cout<<n<<" ";
		cout<<endl;
	}
	return 0;
}