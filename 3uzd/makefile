CXX = clang++
CC = clang

main:	functions.o student.o StudentDerived.o
	clang++ -o main main.cpp functions.o student.o StudentDerived.o
test:	main
	./main

clean:
	rm -f *.o main