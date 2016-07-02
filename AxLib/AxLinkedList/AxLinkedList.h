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
	AxLinkedList<T>(T);
	~AxLinkedList();

	void Add(T element);
	void Remove();
	T Get();
	AxLinkedList<T>* Next();

private:
	T data;
	AxLinkedList<T>* forward;
};
