#pragma once
#include<iostream>
using namespace std;
template<typename T>
class LinkedList{
	Node<T> *tail;
    Node<T> *head;
public:
	LinkedList() {
		head = nullptr;
		tail = nullptr;
	}
	//////////////////Prob1////////////////////
	bool IsEmpty()
	{
		if (head == nullptr && tail == nullptr)
		{
			return true;
	    }
		return false;
	}
	//////////////////Prob2////////////////////
	void InsertAtHead(T val)
	{
		Node<T>* node = new Node<T>(val);
		Node<T>* temp = node;
		temp->next = head;
		head = temp;
	}
	//////////////////Prob3////////////////////
	void InsertAtTail(T val)
	{
		Node<T> *node = new Node<T>(val);
		if (head == nullptr)
		{
			head = node;
			tail = node;
		}
		else
		{
			tail->next = node;
			tail = node;
		}
	}
	//////////////////Prob1////////////////////
	void Display()
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data<<endl;
			temp = temp->next;
		}
	}
	//////////////////Prob4////////////////////
	void InsertAtMid(T val)
	{
		Node<T>* FastP = head;
		Node<T>* SlowP = head;
		Node<T>* previousSlow = nullptr;
		while (FastP != nullptr&&FastP->next!=nullptr)
		{
			FastP = FastP->next->next;
			previousSlow = SlowP;
			SlowP = SlowP->next;
		}
		Node<T>* node = new Node<T>(val);
		previousSlow->next=node; 
		node->next=SlowP;
	}
	//////////////////Prob5 part a////////////////////
	void InsertAtAfter(T value, T key)
	{
		Node<T>* temp = head;
		while (temp != nullptr)
		{
			if (temp->data == key)
			{
				Node<T>* node = new Node<T>(value);
				Node<T>* temp2 = temp->next;
				temp->next = node;
				node->next = temp2;
				break;
			}
			temp = temp->next;
		}
	}
	//////////////////Prob5 part b////////////////////
	void InsertBefore(T value, T key)
	{
		Node<T>* newNode = new Node<T>(value);

		if (head == nullptr) {
			head = newNode;
			return;
		}

		if (head->data == key) {
			newNode->next = head;
			head = newNode;
			return;
		}

		Node<T>* temp = head;

		while (temp->next != nullptr && temp->next->data != key)
		{
			temp = temp->next;
		}

		if (temp->next == nullptr) {
			delete newNode;
			return;
		}
		newNode->next = temp->next;
		temp->next = newNode;
	}
	//////////////////Prob6////////////////////
	 T  Front()
	 {
		 if (!IsEmpty())
		 {
			 return head->data;
		 }
		 return 0;
	 }
	 //////////////////Prob7////////////////////
	 T  Back()
	 {
		 if (!IsEmpty())
		 {
			 return tail->data;
		 }
		 return 0;
	 }
	 //////////////////Prob8////////////////////
	 bool Search(T key)
	 {
		 Node<T>* temp = head;
		 while (temp != nullptr)
		 {
			 if (temp->data = key)
			 {
				 return true;
			 }
			 temp = temp->next;
		 }
		 return false;
	 }
	 //////////////////Prob9 part a////////////////////
	 bool RemoveFront(LinkedList<T>list)
	 {
		 Node<T>* temp = head;
		 if (list.IsEmpty())
		 {
			 return 0;
		 }
		 else if (temp->next != nullptr)
		 {
			 head = temp->next;
			 delete temp;
			 return 1;
		 }
		 else if (temp->next == nullptr)
		 {
			 head = nullptr;
			 tail = nullptr;
			 delete head;
			 return 1;
		 }
		 return 0;
	 }
	 //////////////////Prob9 part b////////////////////
	 bool RemoveTail(LinkedList<T>list)
	 {
		 Node<T>* temp = head;
		 Node<T>* tailpre = nullptr;
		 if (list.IsEmpty())
		 {
			 return 0;
		 }
		 else if (tail==head)
		 {
			 head = nullptr;
			 tail = nullptr;
			 delete tail;
			 return 1;
		 }
		 else
		 {
			 while (temp!=nullptr)
			 {
				 if (temp->next == tail)
				 {
					 delete tail;
					 tail = temp;
					 tail->next = nullptr;
					 return 1;
				 }
				 temp = temp->next;
			 }
		 }
		 return 0;
	 }
	 //////////////////Prob9 c////////////////////
	 bool RemoveMiddle(LinkedList<T>list)
	 {
		 if (list.IsEmpty())
		 {
			 return 0;
		 }
		 else if (tail == head)
		 {
			 head = nullptr;
			 tail = nullptr;
			 delete tail;
			 return 1;
		 }
		 else
		 {
			 Node<T>* FastP = head;
			 Node<T>* SlowP = head;
			 Node<T>* previousSlow = nullptr;
			 while (FastP != nullptr&&FastP->next!=nullptr)
			 {
				 FastP = FastP->next->next;
				 previousSlow = SlowP;
				 SlowP = SlowP->next;
			 }
			 previousSlow->next = SlowP->next;
			 delete SlowP;
			 return 1;
		 }
		 return 0;
	 }
	 /////////////////////////////Question 2 a///////////////////
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
	 ////////////////////////question 2 b//////////////////////////
	 void Push(T value)
	 {
		 S.InsertAtTail(value);
	 }
	 bool isEmpty()
	 {
		 return S.IsEmpty();
	 }
	 T Pop() {
		 return S.Back();
	 }
	 /////////////////////Question 3 a/////////////////////
	 void printListOriginal(Node* node) {
		 if (node == nullptr) {
			 return;
		 }
		 cout << node->data << " ";
		 printListOriginal(node->next);
	 }
	 /////////////////////////Question 3 b/////////////////////
	 void printListReverse(Node* node) {
		 if (node == nullptr) {
			 return;
		 }
		 printListReverse(node->next);
		 cout << node->data << " ";
	 }
	 //////////////////Question 3 c////////////////////
	 bool CircularLiinkedList()
	 {
		 if (head == nullptr || tail->next == head)
		 {
			 return true;
		 }
		 else
		 {
			 return false;
		 }
	 }
	 //////////////////Question 3 d////////////////////
	 void ReverseLinkedList()
	 {
		 Node<T>* previous = nullptr;
		 Node<T>*current = head;
		 Node<T>* Next = nullptr;
		 while (current != nullptr)
		 {
			 Next = current->next;
			 current->next = previous;

			 previous = current;
			 current = Next;
		 }
		 head = previous;
	 }
	 void insertionSort()
	 {
		 arr[4]={1,2,3,5,6}
		 for (int i = 1; i < sizeof(arr); i++)
		 {
			 int current = arr[i];
			 int j = i - 1;
			 while (arr[j] > current && j > 0)
			 {
				 arr[j + 1] = arr[j];
				 j--;
			 }
			 arr[j + 1] = current;
	     }
	 }
};
