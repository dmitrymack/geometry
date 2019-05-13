all: geometry

.PHONY: test

test: bin/maintest

.PHONY: clean

build/src/print.o: src/print.cpp
	g++ src/print.cpp -o build/src/print.o -c -Wall -Werror -lgraph

build/src/polygon_calculation.o: src/polygon_calculation.cpp
	g++ src/polygon_calculation.cpp -o build/src/polygon_calculation.o -c -Wall -Werror

build/src/circle_calculation.o: src/circle_calculation.cpp
	g++ src/circle_calculation.cpp -o build/src/circle_calculation.o -c -Wall -Werror

build/src/circle.o: src/circle.cpp
	g++ src/circle.cpp -o build/src/circle.o -c -Wall -Werror

build/src/triangle.o: src/triangle.cpp
	g++ src/triangle.cpp -o build/src/triangle.o -c -Wall -Werror

build/src/triangle_calculation.o: src/triangle_calculation.cpp
	g++ src/triangle_calculation.cpp -o build/src/triangle_calculation.o -c -Wall -Werror

build/src/polygon.o: src/polygon.cpp
	g++ src/polygon.cpp -o build/src/polygon.o -c -Wall -Werror

build/src/intersect.o: src/intersect.cpp
	g++ src/intersect.cpp -o build/src/intersect.o -c -Wall -Werror

build/src/geometry.o: src/geometry.cpp
	g++ src/geometry.cpp -o build/src/geometry.o -c -Wall -Werror

geometry: build/src/print.o build/src/intersect.o build/src/circle.o build/src/triangle.o build/src/circle_calculation.o build/src/triangle_calculation.o build/src/polygon_calculation.o build/src/polygon.o build/src/geometry.o
	g++ build/src/geometry.o build/src/intersect.o build/src/circle.o build/src/triangle.o build/src/circle_calculation.o build/src/triangle_calculation.o build/src/polygon.o build/src/polygon_calculation.o build/src/print.o -Wall -Werror -o bin/geometry -lgraph

build/test/maintest.o: test/maintest.cpp
	g++ test/maintest.cpp -o build/test/maintest.o -lgtest_main -lgtest -pthread -c -Wall -Werror

bin/maintest: build/test/maintest.o
	g++ build/test/maintest.o -lgtest_main -lgtest -pthread -o bin/maintest -Wall -Werror

clean_src:
	rm -rf build/src/*.o bin/geometry

clean_test:
	rm -rf build/test/*.o bin/maintest

