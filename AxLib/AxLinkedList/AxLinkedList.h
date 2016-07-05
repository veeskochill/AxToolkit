#include <stdlib.h>   

//interface for a stack
/*
Push to top
Pop from top
*/

template<class T>
class AxLinkedList
{
public:
	AxLinkedList<T>(T element, AxLinkedList<T>* next = NULL);
	~AxLinkedList();

	T Get();
	void SetNext(AxLinkedList<T>* next);
	AxLinkedList<T>* GetNext();

private:
	T data;
	AxLinkedList<T>* forward;
};
