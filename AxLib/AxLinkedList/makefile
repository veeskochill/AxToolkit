all: main.exe

main.exe: AxLinkedList.o
	g++ -o main.exe main.cpp AxLinkedList.o

AxStack.o: AxLinkedList.h
	g++ -c AxLinkedList.cpp

clean:
	del AxLinkedList.o main.exe