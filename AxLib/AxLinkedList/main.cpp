#include <stdio.h>
#include "AxList.h"

using namespace std;

int main(){
	
	//Test Linked List
	AxList<int>* myList = new AxList<int>();

	myList->Add(1);
	myList->Add(2);
	myList->Add(4);
	myList->Add(8);

	int loc = myList->Find(4);
	printf("%d ",loc);
	printf("%d\n", myList->Get(loc));

	myList->Remove(loc);



	delete myList;
	
	return 0;
}