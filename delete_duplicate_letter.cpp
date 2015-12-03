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
#include<limits.h>
using namespace std;

string delete_duplicate_letter(const string &s) {
	map<char,set<int> > m_map;
	for (int i=0;i<s.size();++i) {
		m_map[s[i]].insert(i);
	} 
	string state;
	int curind=-1;
	function<void(int,map<char,set<int> >::iterator)> backtrack=[&](int k, map<char,set<int> >::iterator itstart) {
		if (k==m_map.size()) {
			return state;
		} else {
			for (auto it=itstart;it!=m_map.end();++it) {
				if (curind>it->second.lowerbound)
			}
		}
	};
}

int main() {
	cout<<delete_duplicate_letter("cdacbcbc")<<endl;
	return 0;
}