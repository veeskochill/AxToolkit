#include "AxStack.h"
#include <stdlib.h>   


template<class T>
AxStack<T>::AxStack(): data(NULL), size(0)
{

}

template<class T>
AxStack<T>::~AxStack()
{
	if(data)
	{
		free(data);
	}
	size = 0;
}

template<class T>
void AxStack<T>::Push(T element)
{
	size++;
	data = (T*)realloc(data, size*sizeof(T));
	data[size] = element;
}

template<class T>
T AxStack<T>::Pop()
{
	T temp = data[size];
	size--;
	data = (T*)realloc(data, size*sizeof(T));
	return temp;
}


template class AxStack<int>;
