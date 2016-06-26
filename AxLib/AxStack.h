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