all: bin/geometry

build/circle_calculation.o: src/circle_calculation.cpp
	g++ src/circle_calculation.cpp -o build/circle_calculation.o -c -Wall -Werror

build/circle.o: src/circle.cpp
	g++ src/circle.cpp -o build/circle.o -c -Wall -Werror

build/triangle.o: src/triangle.cpp
	g++ src/triangle.cpp -o build/triangle.o -c -Wall -Werror

build/triangle_calculation.o: src/triangle_calculation.cpp
	g++ src/triangle_calculation.cpp -o build/triangle_calculation.o -c -Wall -Werror

build/geometry.o: src/geometry.cpp
	g++ src/geometry.cpp -o build/geometry.o -c -Wall -Werror

bin/geometry: build/geometry.o build/circle.o build/triangle.o build/circle_calculation.o build/triangle_calculation.o build/print.o
	g++ build/geometry.o build/circle.o build/triangle.o build/circle_calculation.o build/triangle_calculation.o build/print.o -Wall -Werror -o bin/geometry -lgraph

clean:
	rm -rf build/*.o bin/geometry
