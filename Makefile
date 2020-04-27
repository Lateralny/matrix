output: main.o Matrix.o
	g++ main.o Matrix.o -o output

main.o: main.cpp
	g++ -c main.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -std=c++11 -c Matrix.cpp

clean:
	rm*.o output
	
run: output
	./output
	
