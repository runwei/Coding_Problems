/*
Please design and implement a class:
This class will be given a list of words (such as might be tokenized from a paragraph of text), and will provide a method that takes two words and returns the shortest distance (in words) between those two words in the provided text.
Example:
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

int shortestworddist(const vector<string> &arr, string s1,string s2) {
	int pos1=-1,pos2=-1,mindist=INT_MAX;
	for (int i=0;i<arr.size();i++) {
		if (arr[i]==s1) {
			if (pos2!=-1) mindist=mindist<i-pos2?mindist:i-pos2;
			pos1=i;
		} else if (arr[i]==s2) {
			if (pos1!=-1) mindist=mindist<i-pos1?mindist:i-pos1;
			pos2=i;
		}
	}
	return mindist;
}

int main() {
	vector<string> arr{"the", "quick", "brown", "fox", "quick"};
	cout<<shortestworddist(arr,"the","fox")<<endl;
	cout<<shortestworddist(arr,"quick","fox");
	
	return 0;
}