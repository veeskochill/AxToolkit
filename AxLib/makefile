all: main.exe

main.exe: AxStack.o
	g++ -o main.exe main.cpp AxStack.o

AxStack.o: AxStack.h
	g++ -c AxStack.cpp

clean:
	del AxStack.o main.exe