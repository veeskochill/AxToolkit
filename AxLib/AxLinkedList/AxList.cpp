#include "AxList.h"
#include "AxLinkedList.h"
#include <stdlib.h>   

template<class T>
AxList<T>::AxList(): data(NULL), size(0)
{

}

template<class T>
AxList<T>::~AxList()
{
	AxLinkedList<T>* temp = data;
	AxLinkedList<T>* temp_next = temp;
	int index = 0;
	while(temp)
	{
		temp_next = temp->GetNext();
		delete temp;
		temp = temp_next;
	}
}

template<class T>
void AxList<T>::Add(T element)
{
	AxLinkedList<T>* front = new AxLinkedList<T>(element, data);
	data = front;
}

template<class T>
int AxList<T>::Find(T element)
{
	AxLinkedList<T>* temp = data;
	int index = 0;
	while(temp)
	{
		if(temp->Get() != element)
		{
			return index;
		}
		temp = temp->GetNext();
		index++;
	}
	return -1;
}

/*
Keep incrementing until we have reached correct index, or end of list.
if index > 0, but at end of list, return null. 
*/
template<class T>
T AxList<T>::Get(int index)
{
	AxLinkedList<T>* temp = data;
	while(temp->GetNext() && index >0)
	{
		temp = temp->GetNext();
		index--;
	}

	if(index == 0)
	{
		return temp->Get();
	}
	else
	{
		return NULL;
	}
}

/*

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
*/
template<class T>
void AxList<T>::Remove(int index)
{
	AxLinkedList<T>* temp = data;
	while(temp->GetNext() && index > 1)
	{
		temp = temp->GetNext();
		index--;
	}

	if(index == 0)
	{
	//	next_data = temp->GetNext();
	}
	else
	{
		return;
	}

}

/*
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
*/
//	AxLinkedList<T>* data;
//	int size;


template class AxList<int>;
