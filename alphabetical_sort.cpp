/*
{ “face”, “ball”, “apple”, “art”, “ah” }
“htarfbp…”
根据下面的string去给上面list words排序。就是平常我们按abcd…排，这次按string里的letter顺序排
*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<list>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
#include "BST.h"
using namespace std;


void alphabetical_sort(vector<string>& strs,const string&s) {
	unordered_map<char,int> m_map;
	int count=0;
	for (auto& c:s) m_map[c]=count++;
	function<bool(string,string)> f=[&] (string s1,string s2) {
		int p1=0,p2=0;
		while (p1<s1.size() && p2<s2.size()){
			if (m_map[s1[p1]]<m_map[s2[p2]]) return true;
			else if (m_map[s1[p1]]>m_map[s2[p2]]) return false;
			else {++p1;++p2;}
		}
		return p1==s1.size();
	};
	sort(strs.begin(),strs.end(),f);
}

	
int main() {
	vector<string> strs { "face", "ball", "apple", "art", "ah" };
	alphabetical_sort(strs,"htarfbp");
	for (auto &s:strs) cout<<s<<endl;
}