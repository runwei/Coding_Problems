#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<list>
#include<limits.h>
using namespace std;

string simplifyPath(string path) {
    list<string> m_list;
    string ret;
    int pos=0,nextpos;
    while (pos<path.size()) {
        nextpos=path.find('/',pos+1);
        nextpos=nextpos==string::npos?path.size():nextpos;
        string s=path.substr(pos+1,nextpos-pos-1);
        pos=nextpos;
        if (s=="." || s.empty()) continue;
        else if (s=="..") {if (!m_list.empty())  m_list.pop_back();}
        else m_list.push_back(s);
    }
    for (auto &s0: m_list) {ret+="/"+s0;}
    if (m_list.empty()) ret.push_back('/');
    return ret;
}


int main() {
	cout<<simplifyPath("/a/./b/../../c/")<<endl;
	return 0;
}