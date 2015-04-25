/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>

using namespace std;

int lengthOfLongestSubstring(string s) {
	unordered_map<char,int> m_map;
	int maxlen=0,curpos=0;
	for (int i=0;i<s.size();i++) {
		if (m_map.count(s[i]) && m_map[s[i]]>=curpos) curpos=m_map[s[i]]+1;
		m_map[s[i]]=i;
		maxlen=max(maxlen,i-curpos+1);
	}
	return maxlen;
}


int main() {
	string s("hchzvfrkmlnozjk");
	cout<<lengthOfLongestSubstring(s)<<endl;
	return 0;
}