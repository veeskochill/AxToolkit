all: main.exe

main.exe: AxList.o
	g++ -o main.exe main.cpp AxList.o

AxStack.o: AxList.h AxStack.o
	g++ -c AxList.cpp AxLinkedList.o

AxStack.o: AxLinkedList.h
	g++ -c AxLinkedList.cpp

clean:
	del AxLinkedList.o AxList.o main.exe