/*
设计一个数据结构，要求支持插入，删除和random返回一个元素这三种操作，每种操作的复杂度都要是O(1)。
Google, Yelp, Twitter都考过这题。
我们需要一个vector和一个hash table。vector存实际的数据，hash table存每个value对应在数组里面的index。
add操作要把新插进去的value的id保存到hash table里。
remove操作首先根据给的value在hash中查出所在id，然后把数组最后一个元素move到要删除的这个元素所在的位置。然后更新index和size。
random返回只需要一个简单的rand() % size就好。
注意这个solution是无法处理重复元素的。
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

class myContainer{
public:
	void AddElem(int a) {
		if (!m_map.count(a)) {
			m_list.push_back(a);
			m_map[a]=m_list.size()-1;
		}
	}
	void DeleteElem(int a) {
		if (m_map.count(a)) {
			int id=m_map[a];
			m_map.erase(a);
			m_list[id]=m_list.back();
			m_list.pop_back();
		}
	}
	int RandomElem(){
		int n=m_list.size();
		if (n==0) return INT_MAX;
		return m_list[(rand() % n)];
	}
		
private:
	vector<int> m_list;
	unordered_map<int,int> m_map;//key,index
};
	


int main() {
	myContainer c;
	c.AddElem(1);
	c.AddElem(2);
	c.AddElem(3);
	for (int i=0;i<10;i++) cout<<c.RandomElem()<<" ";
	cout<<endl;
	c.DeleteElem(2);
	for (int i=0;i<10;i++) cout<<c.RandomElem()<<" ";
	
	return 0;
}