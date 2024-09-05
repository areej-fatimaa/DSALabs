#pragma once
template<typename T>
class Node
{
public:
	Node* next;
	T data;
	Node(T value)
	{
		data = value;
		next = nullptr;
	}

};



