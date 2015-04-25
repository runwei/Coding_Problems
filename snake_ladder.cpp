/*
Given a snake and ladder board, find the minimum number of dice throws required to reach the destination or last cell from source or 1st cell. Basically, the player has total control over outcome of dice throw and wants to find out minimum number of throws required to reach last cell.
If the player reaches a cell which is base of a ladder, the player has to climb up that ladder and if reaches a cell is mouth of the snake, has to go down to the tail of snake without a dice throw.

For example consider the board shown on right side (taken from here), the minimum number of dice throws required to reach cell 30 from cell 1 is 3. Following are steps.
a) First throw two on dice to reach cell number 3 and then ladder to reach 22
b) Then throw 6 to reach 28.
c) Finally through 2 to reach 30.
There can be other solutions as well like (2, 2, 6), (2, 4, 4), (2, 3, 5).. etc.
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<unordered_map>

#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

int snakeandladder(int a[],int n) {
	unordered_map<int,int> m_map;
	queue<int> q;
	q.push(0);m_map[0]=0;
	while (!q.empty()) {
		int ind=q.front();q.pop();
		int dist=m_map[ind];
		while (a[ind]!=-1) ind=a[ind];
		for (int i=ind+1;i<=ind+6;i++) {
			if(!m_map.count(i)) {
				if (i==n-1) return dist+1;
				m_map[i]=dist+1;q.push(i);
			} else continue;
		}
	}
	return INT_MAX;
}


int main() {
	int N = 30;
	    int moves[N];
	    for (int i = 0; i<N; i++)
	        moves[i] = -1;
 
	    // Ladders
	    // moves[2] = 21;
	    // moves[4] = 7;
	    // moves[10] = 25;
	    // moves[19] = 28;
	    //
	    // // Snakes
	    // moves[26] = 0;
	    // moves[20] = 8;
	    // moves[16] = 3;
	    // moves[18] = 6;
 
	    cout << "Min Dice throws required is " << snakeandladder(moves, N);
	return 0;
}

