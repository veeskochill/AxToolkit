all: main.exe

main.exe: AxList.o AxLinkedList.o
	g++ -o main.exe main.cpp AxList.o AxLinkedList.o

AxList.o: AxList.h 
	g++ -c AxList.cpp

AxLinkedList.o: AxLinkedList.h
	g++ -c AxLinkedList.cpp

clean:
	del AxLinkedList.o AxList.o main.exe