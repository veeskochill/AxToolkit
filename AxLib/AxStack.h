#include <stdlib.h>   

//interface for a stack
/*
Push to top
Pop from top
*/

template<class T>
class AxStack
{
public:
	AxStack<T>();
	~AxStack();
	void Push(T element);
	T Pop();

private:
	T* data;
	T size;
};
