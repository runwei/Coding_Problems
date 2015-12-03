#include<limits.h>
#include<ctime>
#include<iostream>
using namespace std;

int experiment1() {
	int x = 0, y = 0, count = 0;
	while (count<10){
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
	}
    if (x * x + y * y >= 9) return 1;
    else return 0;   
}

int experiment2() {
	int x = 0, y = 0, count = 0;
	while (count<60){
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
	}
    if (x * x + y * y >= 100) return 1;
    else return 0;   
}

int experiment3() {
	int x = 0, y = 0, count = 0;
	while (count<10){
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
		if (x * x + y * y >= 25) return 1; 
	}
    return 0;   
}

int experiment4() {
	int x = 0, y = 0, count = 0;
	while (count<60){
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
		if (x * x + y * y >= 100) return 1; 
	}
    return 0;   
}

int experiment5() {
	int x = 0, y = 0, count = 0;
	bool flag = false;
	while (count<10){
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
		if (x >1) flag=true;
	}
    return flag && x<-1; 
} 

int experiment6() {
	int x = 0, y = 0, count = 0;
	bool flag = false;
	while (count<30){
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
		if (x >1) flag=true;
	}
    return flag && x<-1; 
} 

int experiment7() {
	int x = 0, y = 0, count = 0;
	while (true) {
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
		if (x*x +y*y >=100) break;
	}
    return count;
} 

int experiment8() {
	int x = 0, y = 0, count = 0;
	while (true) {
		int rn = rand() % 4;
        if (rn == 0) x -= 1;
		else if (rn ==1) x += 1;
        else if (rn ==2) y -= 1;
        else y += 1;
        count += 1;
		if (x*x +y*y >=3600) break;
	}
    return count;
} 

int main(){
	srand(time(NULL));
	double sumval = 0;
	int round = 1000000;
	for (int i=0;i<round;++i)
		sumval += experiment8();
	cout<< sumval /round;
	return 0;
}
