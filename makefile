CXX = clang++
CC = clang

main: functions.o
	clang++ -o main main.cpp functions.o
test: main
	./main
clean:
	rm -f *.o main	