
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <ctime>
using namespace std;

struct Node{
	int x;
	int y;
	Node(int x,int y):x(x), y(y) {}
};

class Solution {
public:
	void findpeak(vector<vector<int> > &height, vector<Node> &peakset){
		int m=height.size();
		if (m==0) return;
		int n=height[0].size();
		vector<vector<bool> > visited(m,vector<bool> (n,false));
		queue<Node> q;
		for (int i=0;i<m;i++)  {q.push({i,0});visited[i][0]=true;}
		for (int j=0;j<n;j++) {q.push({0,j});visited[0][j]=true;}
		while (!q.empty()) {
			Node c=q.front();
			q.pop();
			if (c.y-1>=0 && !visited[c.x][c.y-1] && height[c.x][c.y]<=height[c.x][c.y-1]) {q.push({c.x,c.y-1});visited[c.x][c.y-1]=true;}
			if (c.y+1<n && !visited[c.x][c.y+1] && height[c.x][c.y]<=height[c.x][c.y+1]) {q.push({c.x,c.y+1});visited[c.x][c.y+1]=true;}
			if (c.x-1>=0 && !visited[c.x-1][c.y] && height[c.x][c.y]<=height[c.x-1][c.y]) {q.push({c.x-1,c.y});visited[c.x-1][c.y]=true;}
			if (c.x+1<m && !visited[c.x+1][c.y] && height[c.x][c.y]<=height[c.x+1][c.y]) {q.push({c.x+1,c.y});visited[c.x+1][c.y]=true;}
		}
		
		vector<vector<bool> > visited2(m,vector<bool> (n,false));
		queue<Node> q2;
		for (int i=0;i<m;i++)  {q2.push({i,n-1});visited2[i][n-1]=true;}
		for (int j=0;j<n;j++) {q2.push({m-1,j});visited2[m-1][j]=true;}
		while (!q2.empty()) {
			Node c=q2.front();
			q2.pop();
			if (c.y-1>=0 && !visited2[c.x][c.y-1] && height[c.x][c.y]<=height[c.x][c.y-1]) {q2.push({c.x,c.y-1});visited2[c.x][c.y-1]=true;}
			if (c.y+1<n && !visited2[c.x][c.y+1] && height[c.x][c.y]<=height[c.x][c.y+1]) {q2.push({c.x,c.y+1});visited2[c.x][c.y+1]=true;}
			if (c.x-1>=0 && !visited2[c.x-1][c.y] && height[c.x][c.y]<=height[c.x-1][c.y]) {q2.push({c.x-1,c.y});visited2[c.x-1][c.y]=true;}
			if (c.x+1<m && !visited2[c.x+1][c.y] && height[c.x][c.y]<=height[c.x+1][c.y]) {q2.push({c.x+1,c.y});visited2[c.x+1][c.y]=true;}
		}
		for (int i=0;i<m;i++)
			for (int j=0;j<n;j++) 
				if (visited[i][j] && visited2[i][j]) peakset.push_back({i,j});
	}
};

int main() {
	vector<vector<int> > height({{1, 4, 4, 2},{2, 1, 3, 1},{2, 2, 2, 3},{1, 2, 4, 2}});
	vector<Node> peakset;
	Solution sol;
	sol.findpeak(height,peakset);
	for (auto it=peakset.begin();it!=peakset.end();it++) {
		cout<<(*it).x<<" "<<(*it).y<<endl;
	}
    /* Your algorithm here */
	// std::clock_t start;
	//
	// double duration= (clock()-start)/ (double) CLOCKS_PER_SEC;
	//     std::cout<<"printf: "<< duration <<'\n';
}

