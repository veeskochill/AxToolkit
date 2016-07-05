#include <stdlib.h>   

class AxLinkedList;
//interface for a List
/*
Add element,
Find element,
Get element,
Remove element
*/

template<class T>
class AxList
{
public:
	AxList();
	~AxList();

	void Add(T element);
	int Find(T element);
	T Get(int index);
	void Remove(int index);

private:
	TAxLinkedList<T>* data;
	int size;
	
};
