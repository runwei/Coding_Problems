/*
Given a set of n jobs with [start time, end time, cost] find a subset so that no 2 jobs overlap and the cost is maximum.
DP+二分:
Sort the intervals based on end time
define p(i) for each interval, giving the biggest end point which is smaller than the start point of i-th interval. Use binary search to obtain nlogn
define d[i] = max(w(i) + d[p(i)], d[i-1]).

initialize d[0] = 0
The result will be in d[n] n- the number of intervals.
Overall complexity O(nlogn)
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<map>
#include<set>
#include<mutex>
#include<thread>
#include<condition_variable>


#include<queue>
#include<list>
#include<limits.h>
#include "leetcode.h"
using namespace std;

string read_number(int num) {
    if(num == 0) return "zero";
   
    static map<int,string> readings = {
        {0, ""}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"},
        {5, "five"}, {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"},
        {10, "ten"}, {11, "eleven"}, {12, "twelve"}, {13, "thirteen"}, {14, "fourteen"},
        {15, "fifteen"}, {16, "sixteen"}, {17, "seventeen"}, {18, "eighteen"}, {19, "nineteen"},
        {20, "twenty"}, {30, "thirty"}, {40, "fourty"}, {50, "fifty"}, {60, "sixty"},
        {70, "seventy"}, {80, "eighty"}, {90, "ninety"}, {100, "hundred"}, {1000, "thousand"}
    };   
    auto read_tens = [&](int n) {
        if(n <= 20) return readings[n];
        int unit = n % 10, rest = n - unit;
        string ret = readings[rest];
        if(!ret.empty() && unit != 0) ret += "-";
        return ret + readings[unit];
    };   
    auto read_hunds = [&](int n) {
        int hund = n / 100, rest = n % 100;
        string ret;
        if(hund > 0) {
            ret = readings[hund] + " " + readings[100];
            if(rest > 0) ret += " and ";
        }
        if(rest > 0) {
            ret += read_tens(rest);
        }
        return ret;
    };   
    auto read_thous = [&](int n) {
        int thous = n / 1000, rest = n % 1000;
        string ret;
        if(thous > 0) {
            ret = read_hunds(thous);
            ret += " ";
            ret += readings[1000];
            if(rest > 0) ret += " ";
        }
        return ret + read_hunds(rest);
    };
    return read_thous(num);
}

int main() {
	cout<<read_number(999999);
}

