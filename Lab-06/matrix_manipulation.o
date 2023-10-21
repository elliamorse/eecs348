all: matrix_manipulation

matrix_manipulation: matrix_manipulation.o
	g++ -o matrix_manipulation matrix_manipulation.o

matrix_manipulation.o: matrix_manipulation.cpp
	g++ -c matrix_manipulation.cpp

clean:
	rm -rf *.o matrix_manipulation