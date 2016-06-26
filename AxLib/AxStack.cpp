#include "AxStack.h"

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
