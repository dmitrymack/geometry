all: geometry

build/circle_calculation.o: src/circle_calculation.cpp
	g++ src/circle_calculation.cpp -o build/circle_calculation.o -c -Wall -Werror

build/circle.o: src/circle.cpp
	g++ src/circle.cpp -o build/circle.o -c -Wall -Werror

build/geometry.o: src/geometry.cpp
	g++ src/geometry.cpp -o build/geometry.o -c -Wall -Werror

geometry: build/geometry.o build/circle.o build/circle_calculation.o
	g++ build/geometry.o build/circle.o build/circle_calculation.o -Wall -Werror -o bin/geometry -lgraph

clean:
	rm -rf build/*.o bin/geometry
