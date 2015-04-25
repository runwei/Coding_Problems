/*
有这么一个class Contact，里面有一个string的name，和一个vector 装着email address，是这个Contact有的address，用一个list装着是因为一个人有可 能有多个email，现在给你vector，比如
{
    { "John", {"john@gmail.com"} },
    { "Mary", {"mary@gmail.com"} },
    { "John", {"john@yahoo.com"} },
    { "John", {"john@gmail.com", "john@yahoo.com", "john@hotmail.com"} },
    { "Bob",  {"bob@gmail.com"} }
}
现在我们知道如果email address相同的话，那么就说明是同一个人，现在要做的是根据这些email address，把同一个contact给group起来，生成一个vector<vector<Contact>>
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
#include "unionfind.h"
using namespace std;

class Contact {
public:
    string name;
    vector<string> emails;
};

vector<vector<Contact> > group_contacts(vector<Contact>& input) {
	unordered_map<string, vector<int> > record;
	for (int i=0;i<input.size();i++)
		for (auto& s:input[i].emails) record[s].push_back(i);
	
	unionfind un(input.size());
	for (auto& r:record) 
		for (int i=1;i<r.second.size();i++) un.connect(r.second[i-1],r.second[i]);
	unordered_map<int, vector<int> > groups;
	for (int i=0;i<input.size();i++) groups[un.root(i)].push_back(i);
	
	vector<vector<Contact> > ret;
	for (auto& g:groups) {
		vector<Contact> vs;
		for (auto &c:g.second) vs.push_back(input[c]);
		ret.push_back(vs);
	}
	return ret;
}

	
	
int main(){
	vector<Contact> contactlist{
    { "John", {"john@gmail.com"} },
    { "Mary", {"mary@gmail.com"} },
    { "John", {"john@yahoo.com"} },
    { "John", {"john@gmail.com", "john@yahoo.com", "john@hotmail.com"} },
    { "Bob",  {"bob@gmail.com"} }
};
	vector<vector<Contact> > ret=group_contacts(contactlist);
	int groupid=0;
	for (auto& g: ret) {
		cout<<"group"<<++groupid<<endl;
		for (auto&c: g) {
			cout<<c.name<<" ";
			for (auto& s:c.emails) cout<<s<<" ";
			cout<<endl;
		}
	}
	return 0;
}