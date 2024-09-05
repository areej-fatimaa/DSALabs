#pragma once
template <typename T>
class Stack
{
public:
	LinkedList<T> S;
	void Push(T value)
	{
		S.InsertAtTail(value);
	}
	bool isEmpty()
	{
		return S.IsEmpty();
	}
	T Pop(){
		return S.Back();
	}
};

