CXX = g++
CXXFLAGS = -O3 -march=native -std=c++17 -Wall -I./include
CFLAGS = -O2 -Wall -I./include

all: build test benchmark

build:
	$(CXX) $(CXXFLAGS) -c src/symm.cpp -o symm.o

test:
	$(CC) $(CFLAGS) tests/cblas_level1_tests.c -o cblas_test -lopenblas
	./cblas_test

benchmark: build
	$(CXX) $(CXXFLAGS) -DOPENBLAS tests/benchmark.cpp symm.o -o benchmark -lopenblas -lpthread
	./benchmark

clean:
	rm -f *.o cblas_test benchmark symm.o
