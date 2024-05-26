#pragma once
#include <exception>
#include <vector>
using namespace std;
template <typename T>
class StaticStack
{
private:
	int size;
	int capacity;
	vector <T> DSV;
public:
	StaticStack()
	{
		size = 0;
		this->capacity = 1;
		DSV.reserve(capacity);
	}
	bool Empty()
	{
		return size == 0;
	}
	void push(T val) 
	{
		DSV.push_back(val);
		size++;
	}  
	void Pop()
	{
		if (Empty())
		{
			throw exception("Stack is empty");
		}
		size--;
	}  
	T  top()
	{
		if (Empty())
		{
			throw exception("Stack is Empty");
		}
		return DSV[size-1];
	}
};
