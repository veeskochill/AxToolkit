#include <stdio.h>
#include "AxLinkedList.h"

using namespace std;

int main(){
	
	//Test Stack
	/*
	AxStack<int>* myStack = new AxStack<int>();
	
	for(int ui = 0; ui<10; ui++)
	{
		myStack->Push(ui);
	}
	
	for(int ui = 0; ui<10; ui++)
	{
		printf("%d\n", myStack->Pop());
	}
	
	delete myStack;
	
	*/

	//Test Linked List
	AxLinkedList<int>* myList = new AxLinkedList<int>(1);

	for(int ui = 1; ui<10; ui++)
	{
		myList->Add(ui);

	}
	printf("Added\n");

	AxLinkedList<int>* third = myList->Next()->Next();
	printf("%d\n", third->Get());
	third->Remove();

	AxLinkedList<int>* temp = myList;
	while(temp->Next())
	{
		printf("%d\n", temp->Get());
		temp = temp->Next();
	}

	while(myList->Next())
	{
		myList->Remove();
	}

	return 0;
}