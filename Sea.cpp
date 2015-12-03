/*
输入是一个 N*N的矩阵，代表地势高度。如果下雨水流只能流去比他矮或者一样高的地势。
矩阵左边和上边是太平洋，右边和下边是大西洋。求出所有的能同时流到两个大洋的点。

For example:
1
2
3
4
5
6
7
8
9
10
Pacific: ~
Atlantic: *
~  ~   ~   ~   ~   ~  ~
~  1   2   2   3  (5) *
~  3   2   3  (4) (4) *
~  2   4  (5)  3   1  *
~ (6) (7)  1   4   5  *
~ (5)  1   1   2   4  *
*  *   *   *   *   *  *
括号里即为结果：
[[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]


Google近期高频题。
Brutal force的解法很简单，每个点搜索一次，接触到太平洋或者大西洋就记录下来。最后扫一遍输出同时能走到两个ocean的点即可。
复杂度为O(n^2)。

优化的话，可以从两个ocean的点开始，从外往里搜。首先搜所有太平洋的点，记录下能接触到的position。然后同理搜大西洋的点，求出交集即可。
搜索用DFS和BFS都可以，复杂度为O(n^2)。

下面给出5个语言版本的DFS解法。
Judge@fgdsb测试结果（测试数据大小247KB）：
*/
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
		for (int j=1;j<n;j++) {q.push({0,j});visited[0][j]=true;}
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

