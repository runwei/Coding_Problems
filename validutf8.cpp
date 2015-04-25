/*
Write a function to validate whether the input is valid UTF-8. Input will be string or byte array, output should be true or false.
UTF-8是一种变长的编码方式。它可以使用1~4个字节表示一个符号，根据不同的符号而变化字节长度。UTF-8的编码规则很简单，只有二条：
1）对于单字节的符号，字节的第一位设为0，后面7位为这个符号的unicode码。因此对于英语字母，UTF-8编码和ASCII码是相同的。
2）对于n字节的符号（n>1），第一个字节的前n位都设为1，第n+1位设为0，后面字节的前两位一律设为10。剩下的没有提及的二进制位，全部为这个符号的unicode码。

比如：
0xxxxxxx是一个合法的单字节UTF8编码。
110xxxxx 10xxxxxx是一个合法的2字节UTF8编码。
1110xxxx 10xxxxxx 10xxxxxx是一个合法的3字节UTF8编码。
11110xxx 10xxxxxx 10xxxxxx 10xxxxxx是一个合法的4字节UTF8编码。
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

bool valid_utf8(const vector<unsigned char> & data) {
	int count=0;
	for (auto& c:data) {
		if (count==0) {
			if (c>>7==0) continue;
			else if (c>>6==2) return false;
			else if (c>>5==6) count=1;
			else if (c>>4==14) count=2;
			else if (c>>3==30) count=3;
		} else if (c>>6==2) --count;
		else return false;
	}
	return !count;
}
	
	
int main() {
	cout << valid_utf8({0b00101010}) << endl; // true
	cout << valid_utf8({0b00101010, 0b01110010, 0b01001010}) << endl; // true
	cout << valid_utf8({0b10101010}) << endl; // false
	cout << valid_utf8({0b11010110, 0b10110111}) << endl; // true
	cout << valid_utf8({0b11010110, 0b00110111}) << endl; // false
	cout << valid_utf8({0b11001111, 0b10111111}) << endl; // true
	cout << valid_utf8({0b11101111, 0b10101010, 0b10111111}) << endl; // true
	cout << valid_utf8({0b11111111, 0b10101010, 0b10111111}) << endl; // false
	cout << valid_utf8({0b11101111, 0b10101010}) << endl; // false
}