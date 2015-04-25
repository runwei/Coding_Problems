all: Helloworld

Helloworld: Helloworld.cpp
	gcc -std=c++11 Helloworld.cpp -g -o Helloworld  -lstdc++

clean:
	rm -rf *o Helloworld