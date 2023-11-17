
main: main.cpp src/*.hpp
	g++ -o main main.cpp -lncurses -g

clean:
	rm -f main *.o
