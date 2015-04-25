#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<limits.h>
using namespace std;

bool isMatch(const char *s, const char *p) {
    int m=strlen(s), n=strlen(p);
    vector<vector<int> > f(m+1,vector<int> (n+1,-1));
    function<int(int,int)> dfs=[&](int i,int j) {
        if (f[i][j]!=-1) return f[i][j];
        if (j==n) {f[i][j]=i==m?1:0;return f[i][j];}
        else if (p[j+1]!='*') {
            if ((s[i]==p[j]) || (p[j]=='.' && i!=m)) return dfs(i+1,j+1);
            else {f[i][j]=-1;return -1;}
        } else {
            int k=i;
            while (s[k]==p[j] || (p[j]=='.' && k!=m)) {
                if (dfs(k,j+2)==1) {f[i][j]=1; return 1;}
                ++k;
            }
			if (dfs(k,j+2)==1) {f[i][j]=1; return 1;}
            else {f[i][j]=0;return 0;}
        }
    };
    return dfs(0,0);
}


int main() {
	cout<<isMatch("aa","aa")<<endl;
	return 0;
}