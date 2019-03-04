all: geometry

geometry: geometry.o
	g++ geometry.o -Wall -o geometry

geometry.o: geometry.cpp
	g++ geometry.cpp -c -Wall
