/*http://www.fgdsb.com/2015/01/19/sums-of-all-subtrees/*/
#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<stdlib.h>
#include<ctime>
#include<limits.h>
#include "leetcode.h"
using namespace std;


int number_of_ones(unsigned int x) {
  int total_ones = 0;
  while (x != 0) {
    x = x & (x-1);
    total_ones++;
  }
  return total_ones;
}


int main(){
	
	cout<<number_of_ones(10);
	return 0;
}