#include "AxList.h"
#include <stdlib.h>   


AxList::AxList(): data(NULL), size(0)
{

}

AxList::~AxList()
{
	TAxLinkedList<T>* temp = data;
	TAxLinkedList<T>* temp_next = temp;
	int index = 0;
	while(temp)
	{
		temp_next = temp->Next();
		delete temp;
		temp = temp_next;
	}
}

template<class T>
void AxList::Add(T element)
{
	AxLinkedList<T>* front = new AxLinkedList<T>(element, data);
	data = front;
}

template<class T>
int AxList::Find(T element)
{
	TAxLinkedList<T>* temp = data;
	int index = 0;
	while(temp)
	{
		if(temp.Get() != element)
		{
			return index;
		}
		temp = temp->Next();
		index++;
	}
	return -1;
}

/*
Keep incrementing until we have reached correct index, or end of list.
if index > 0, but at end of list, return null. 
*/
template<class T>
T AxList::Get(int index)
{
	TAxLinkedList<T>* temp = data;
	while(temp->Next() && index >0)
	{
		temp = temp->Next();
		index--;
	}

	if(index == 0)
	{
		return temp;
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
		AxLinkedList<T>* temp = forward->Next();
		//clear the memory
		delete forward;
		//point to the next
		forward = temp;
	}
*/

void AxList::Remove(int index)
{
	TAxLinkedList<T>* temp = data;
	while(temp->Next() && index > 1)
	{
		temp = temp->Next();
		index--;
	}
	if(index == 0)
	{
		return temp;
	}
	else
	{
		return;
	}

}


//	TAxLinkedList<T>* data;
//	int size;


template class AxList<int>;
