/*
implement memmove
*/
#include<vector>
#include<string.h>
#include <stdio.h>
#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

#include<queue>
#include<list>
#include<limits.h>
using namespace std;

void mymemmove(void*dst, void *src, int size) {
	uint8_t* pdst=(uint8_t*) dst;
	uint8_t* psrc=(uint8_t*) src;
	if (pdst<psrc) {
		for (int i=0;i<size/4;i++) {
			*((uint32_t*) pdst)=*((uint32_t*) psrc);
			pdst+=4;
			psrc+=4;
		}
		for (int i=0;i<size %4;i++) {
			*pdst++=*psrc++;
		}
	} else {
		while(size>=4) {
			*((uint32_t*) (pdst+size-4))= *((uint32_t*) (psrc+size-4));
			size-=4;
		}
		while (size>0){
			--size;
			*(pdst+size)=*(psrc+size);
		}
	}
}




	
	
int main() {
	char arr1[] {"abcdefg"};
	char arr2[] {"gfedcba"};
	mymemmove(arr2,arr1,strlen(arr1));
	cout<<arr1;
	// for (int i=1;i<=n;i++)
	// cout<<findksmallest(arr,i)<<endl;
	
	return 0;
}