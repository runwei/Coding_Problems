/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.


2014-1-23 最后完成这道题目， Leetcode 150道题目正式完工
且每道题做了不下三遍。
贴出这道题是2014-3-7了。时隔一个月多了，期间又多做差不多两遍，到现在才贴完，是因为到现在才算把所有题目都研究透彻了。每道题做了五遍以上了，打算以慢速继续刷多几遍，每天刷几题吧。
算法修炼到现在差不多四个月了，期间过春节，没什么时间，算起来也有三个月。终于提高到了一个全新的境界了，对算法是信心满满的了。
有空全面地总结一下。
本博客也有所有Leetcode题的程序了，不太好的代码都有更新了，所有Leetcode题目更新后的代码可读性都挺高的了。

本题5星级接近6星级的题目，本题是十分麻烦的题目，情况是非常多，网上也很多方法，其中最有效，优雅的方法是有限状态自动机(Finite automata machine)。其他一般方法都会十分复杂，而代码不能算优雅。为此我也曾经专门修了一个automata的知识。
只要设计好Finite Automata Machine之后，写程序就可以很优雅，很简单了。
但是，问题是要构造一个Finite Automata也是十分麻烦的事情，我画了一张A4纸，像蜘蛛网一样的，故此就不贴出来了，也搞了一两个小时，要多练练automata才能快起来吧

注释一下本题分多少状态吧：
0初始无输入或者只有space的状态
1输入了数字之后的状态
2前面无数字，只输入了Dot的状态
3输入了符号状态
4前面有数字和有dot的状态
5'e' or 'E'输入后的状态
6输入e之后输入Sign的状态
7输入e后输入数字的状态
8前面有有效数输入之后，输入space的状态
共9种状态了，难设计的是6,7,8状态。
分好之后就好办了，设计出根据输入进行状态转换就OK了。

这里的输入可以分：
INVALID,  // 0 Include: Alphas, '(', '&' ans so on
SPACE,  // 1
SIGN, // 2 '+','-'
DIGIT,  // 3 numbers
DOT, // 4 '.'
EXPONENT,  // 5 'e' 'E'
然后就是画蜘蛛网吧，什么状态可以转换到什么状态的。

下面代码也注释出来了，参照了Leetcode论坛上的代码写的：
*/

#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<queue>
#include<limits.h>
using namespace std;

class Solution {
public:
	bool isNumber(const char *s) {
		enum InputType {
			INVALID,		// 0 Include: Alphas, '(', '&' ans so on
			SPACE,		// 1
			SIGN,		// 2 '+','-'
			DIGIT,		// 3 numbers
			DOT,			// 4 '.'
			EXPONENT,		// 5 'e' 'E'
		};
		int transTable[][6] = {
		//0INVA,1SPA,2SIG,3DI,4DO,5E
			-1,  0,  3,  1,  2, -1,//0初始无输入或者只有space的状态
			-1,  8, -1,  1,  4,  5,//1输入了数字之后的状态
			-1, -1, -1,  4, -1, -1,//2前面无数字，只输入了Dot的状态
			-1, -1, -1,  1,  2, -1,//3输入了符号状态
			-1,  8, -1,  4, -1,  5,//4前面有数字和有dot的状态
			-1, -1,  6,  7, -1, -1,//5'e' or 'E'输入后的状态
			-1, -1, -1,  7, -1, -1,//6输入e之后输入Sign的状态
			-1,  8, -1,  7, -1, -1,//7输入e后输入数字的状态
			-1,  8, -1, -1, -1, -1,//8前面有有效数输入之后，输入space的状态
		};
		int state = 0;
		while (*s)
		{
			InputType input = INVALID;
			if (*s == ' ') input = SPACE;
			else if (*s == '+' || *s == '-') input = SIGN;
			else if (isdigit(*s)) input = DIGIT;
			else if (*s == '.') input = DOT;
			else if (*s == 'e' || *s == 'E') input = EXPONENT;
			state = transTable[state][input];
			if (state == -1) return false;
			++s;
		}
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};