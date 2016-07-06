#include "AxLinkedList.h"
#include <stdlib.h>   


template<class T>
AxLinkedList<T>::AxLinkedList(T element, AxLinkedList<T> next): data(element), forward(next)
{

}

template<class T>
AxLinkedList<T>::~AxLinkedList()
{
}

template<class T>
T AxLinkedList<T>::Get()
{
	return data;
}

template<class T>
void SetNext(AxLinkedList<T>* next)
{
	forward = next;
}

template<class T>
AxLinkedList<T>* AxLinkedList<T>::GetNext()
{
	return forward;
}

template class AxLinkedList<int>;




/****** No longer needed *****/

//Create a new node. If there is a node ahead, insert between.
template<class T>
void AxLinkedList<T>::Add(T element)
{
	AxLinkedList<T>* next = new AxLinkedList<T>(element);
	if(forward)
	{
		next->forward = forward;
		forward = next;
	}
	else
	{
		forward = next;
	}
}

//Remove this information, not the memory.
//Copy the members from forward
template<class T>
void AxLinkedList<T>::Remove()
{
	if(forward)
	{
		//copy the member
		data = forward->Get();
		//store it's 'next' pointer
		AxLinkedList<T>* temp = forward->GetNext();
		//clear the memory
		delete forward;
		//point to the next
		forward = temp;
	}
}



