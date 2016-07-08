#include <stdio.h>
#include "AxList.h"

using namespace std;
	
//Test Linked List
int main(){

	AxList<int>* myList = new AxList<int>();

//Populate the list
	myList->Add(1);
	myList->Add(2);
	myList->Add(3);
	myList->Add(5);
	myList->Add(7);
	myList->Add(9);

//Try to find something not in the list
	int loc = myList->Find(4);
	printf("%d ",loc);
	printf("%d\n", myList->Get(loc));

//Find something in the list
	loc = myList->Find(5);
	printf("%d ",loc);
	printf("%d\n", myList->Get(loc));

//remove something from the list
	myList->Remove(loc);

//print out the list
	AxList<int>* temp = myList;
	while(temp->GetSize())
	{
		printf("%d\n", myList->Get(0));
		temp->Remove(0);
	}


//cleanup
	delete myList;
	
	return 0;
}