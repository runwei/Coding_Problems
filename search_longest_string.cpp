/*
给一个dictionary, 一个string,找出dict 里能全部用string里的letter 表示的所有最长的词。
For example:
字典包含如下单词：
abcde, abc, abbbc, abbbccca, abbbcccabbcx
给string = "abc"，最长单词应为"abbbccca"


也是给一个字典，所以建trie比较合适。搜索函数如下（trie代码请参考Get Similar Words中的实现）
本题还有一种变体，基本上是差不多的：
given Set set, List chars, return Set which has longest be covered by the List
e.g. dgg cat naioe lot.
1st case: dcnlggatio -> return [dgg,cat,lot]
2st case: dcnlggatioe -> return [naioe]
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
// #include "Trie.h"

using namespace std;


struct Node {
	Node(const char &input): c(input){}
	Node* get(const char &c, bool newflag=true) {
		int ind=c=='\0'?26:c-'a';
		if (!vec[ind] && newflag) vec[ind]=new Node(c);
		return vec[ind];
	}
	bool end() {
		return vec[26]?true:false;
	}
private:
	char c;
	Node* vec[27] {NULL};
};

class Trie {
public:
	Trie() {root=new Node('\0');}
	void addstring(const string &s) {
		Node *cur=root;
		for(auto &c:s) cur=cur->get(c);
		cur->get('\0');
	}
	string searchlongest(const unordered_set<char> & m_map) {
		string ret,s; int maxlen=0,curlen=0;
		function<void(Node*)> dfs=[&](Node *cur)->void {
			if (!cur) return;
			if (cur->end()&& curlen>maxlen) {
				maxlen=curlen;ret=s;
			}
			for (auto &c:m_map) {
				s.push_back(c);++curlen;
				dfs(cur->get(c,false));
				s.pop_back();--curlen;
			}
		};
		dfs(root);
		return ret;
	}
private:
	Node *root;
};


int main(){
	Trie t;
	t.addstring("abdaadb");
	t.addstring("ab");
	t.addstring("baa");
	t.addstring("babba");
	t.addstring("abbbcccabbcx");
	cout<<t.searchlongest({'a','b', 'd'});
	return 0;
}