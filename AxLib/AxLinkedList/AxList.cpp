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
	size++;
}

template<class T>
int AxList<T>::Find(T element)
{
	AxLinkedList<T>* temp = data;
	int index = 0;
	while(temp)
	{
		if(temp->Get() == element)
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

template<class T>
void AxList<T>::Remove(int index)
{
	AxLinkedList<T>* temp = data;
	AxLinkedList<T>* previous = NULL;
	while(temp && index > 0)
	{
		previous = temp;
		temp = temp->GetNext();
		index--;
	}

	if(index == 0)
	{
		if(previous)
		{
			if(temp->GetNext())
			{
				previous->SetNext(temp->GetNext());
			}
			else
			{	
				previous->SetNext(NULL);
			}
		}
		else
		{
			data = temp->GetNext();
		}

		delete temp;
		size--;
	}
	else
	{
		return;
	}

}
template<class T>
int AxList<T>::GetSize()
{
	return size;
}

template class AxList<int>;
