#include <stdio.h>
#include <stdlib.h>   

//interface for a stack
/*
Push to top
Pop from top
*/

class AxStack
{
public:
	AxStack();
	~AxStack();
	void Push(int element);
	int Pop();

private:
	int* data;
	int size;
};

AxStack::AxStack()
{
	data = NULL;
	size = 0;
}

AxStack::~AxStack()
{
	if(data)
		free(data);
	size = 0;
}

void AxStack::Push(int element)
{
	size++;
	data = (int*)realloc(data, size*sizeof(int));
	data[size] = element;
}

int AxStack::Pop()
{
	int temp = data[size];
	size--;
	data = (int*)realloc(data, size*sizeof(int));
	return temp;
}

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