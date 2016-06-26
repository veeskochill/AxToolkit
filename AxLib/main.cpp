#include <stdio.h>
#include "AxStack.h"

int main(){
	
	AxStack* myStack = new AxStack();
	
	for(int ui = 0; ui<10; ui++)
	{
		myStack->Push(ui);
	}
	
	for(int ui = 0; ui<10; ui++)
	{
		printf("%d\n", myStack->Pop());
	}
	
	delete myStack;
	
	return 0;
}