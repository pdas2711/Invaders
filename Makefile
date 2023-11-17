
main: main.cpp src/*.hpp
	g++ main.cpp -lncurses -o main

clean:
	rm -f main *.o
