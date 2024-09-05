#pragma once
template <typename T>
#include "LinkedList.h"
class Queue
{
public:
	LinkedList<T> Q;
	void Enqueue(T val)
	{
		Q.InsertAtTail(val);
	}
	void DeQueue()
	{
		Q.RemoveTail(Q);
	}
	bool IsEmpty()
	{
		return Q.IsEmpty();
	}
};

