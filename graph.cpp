#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<limits.h>
using namespace std;

class Graph {
	struct GraphNode {
	    int label;
	    vector<GraphNode *> neighbors;
	    GraphNode(int x) : label(x) {};
	};
public:
	vector<GraphNode*> nodes;
	vector<GraphNode*> TP_nodes;
	
	unordered_set<GraphNode*> visited;
	unordered_set<GraphNode*> returned;
	unordered_map<GraphNode*, GraphNode*> parent;
	unordered_map<GraphNode*,int> componentID;
	int numComponent=0;
	Graph() {
		GraphNode *n0=new GraphNode(0);
		GraphNode *n1=new GraphNode(1);
		GraphNode *n2=new GraphNode(2);
		GraphNode *n3=new GraphNode(3);
		GraphNode *n4=new GraphNode(4);
		nodes.push_back(n0);
		nodes.push_back(n1);
		nodes.push_back(n2);
		nodes.push_back(n3);
		nodes.push_back(n4);
		n0->neighbors.push_back(n1);
		// n1->neighbors.push_back(n2);	
		n1->neighbors.push_back(n3);
		n2->neighbors.push_back(n3); 	n2->neighbors.push_back(n4);
		n3->neighbors.push_back(n4);
		// n4->neighbors.push_back(n0);
	}
	void cycledetect() {
		for (auto& n: nodes) {
			if (visited.count(n)==0) {
				if (dfs(n)) return;
			}
		}
	}
	
	void topologicalsort(){
		for (auto& n: nodes) {
			if (visited.count(n)==0) {
				dfs(n);
			}
		}
	}
	
	void startdfs()
	{
		dfs(nodes[0]);
	}
	void connectedcomponent(){
		for (auto& n: nodes) {
			if (visited.count(n)==0) {
				dfs(n);
				++numComponent;
			}
		}
	}
	
	void showroutes()
	{
		for (auto &n:TP_nodes) cout<<n->label<<" ";
		// for (auto it=componentID.begin();it!=componentID.end();it++) cout<<it->first->label<<" "<<it->second<<endl;
		// cout<<endl;
		// for (auto n:nodes) {
		// 	while (parent.count(n)==1) {
		// 		cout<<n->label;
		// 		n=parent[n];
		// 	}
		// 	cout<<n->label<<endl;
		// }
	}
	void bfs() {
		queue<GraphNode*> q;
		q.push(nodes[0]);
		visited.insert(nodes[0]);
		while (!q.empty()) {
			GraphNode* tmp=q.front();
			q.pop();
			for (auto & n:tmp->neighbors) {
				if (visited.count(n)==0) {
					parent[n]=tmp;
					q.push(n);
					visited.insert(n);
				}
			}
		}
	}
	bool dfs(GraphNode *n0) {
		visited.insert(n0);
		componentID[n0]=numComponent;
		for (auto n: n0->neighbors) 
			if (visited.count(n)==1 && returned.count(n)==0) {
				while (n0!=n) {
					cout<<n0->label;
					n0=parent[n0];
				}
				cout<<n->label;
				return true;
			}
			else if (visited.count(n)==0) {
				parent.insert({n,n0});
				if (dfs(n)) return true;
			} 
		TP_nodes.push_back(n0);
		returned.insert(n0);
		return false;
	}
	~Graph() {
		for (int i=0;i<nodes.size();i++) 
			delete nodes[i];
	}

};



int main() {	
	Graph g=Graph();
	g.topologicalsort();
	g.showroutes();
	return 0;
}