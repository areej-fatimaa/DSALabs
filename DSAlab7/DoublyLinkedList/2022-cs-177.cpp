#pragma once
template<typename T>
struct Node {
    int data;
    Node* next;
    Node* prev;
};  
template <typename T>
class DoublyLinkedList {
public:
    Node<T>* head;
    Node<T>* tail;
    // Define Forward Iterator
    class ForwardIterator {
    public:
        Node<T>* current;
        ForwardIterator(Node<T>* node) : current(node) {}

        ForwardIterator& operator++() {
            current = current->next;
            return *this;
        }

        bool operator==(const ForwardIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const ForwardIterator& other) const {
            return current != other.current;
        }

        int& operator*() {
            return current->data;
        }
    };

    // Define Reverse Iterator
    class ReverseIterator {
    public:
        Node<T>* current;
        ReverseIterator(Node<T>* node) : current(node) {}

        ReverseIterator& operator++() {
            current = current->prev;
            return *this;
        }

        bool operator==(const ReverseIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const ReverseIterator& other) const {
            return current != other.current;
        }

        int& operator*() {
            return current->data;
        }
    };

    // Define General Iterator
    class GeneralIterator {
    public:
        Node<T>* current;
        GeneralIterator(Node<T>* node) : current(node) {}

        GeneralIterator& operator++() {
            current = current->next;
            return *this;
        }

        GeneralIterator& operator--() {
            current = current->prev;
            return *this;
        }

        bool operator==(const GeneralIterator& other) const {
            return current == other.current;
        }

        bool operator!=(const GeneralIterator& other) const {
            return current != other.current;
        }

        int& operator*() {
            return current->data;
        }
    };

    ForwardIterator fbegin() {
        return ForwardIterator(head);
    }

    ForwardIterator fend() {
        return ForwardIterator(nullptr);
    }
    ReverseIterator rbegin() {
        return ReverseIterator(tail);
    }

    ReverseIterator rend() {
        return ReverseIterator(nullptr);
    }

    GeneralIterator begin() {
        return GeneralIterator(head);
    }
    GeneralIterator end() {
        return GeneralIterator(nullptr);
    }



    bool Empty() {
        return head == nullptr;
    }

    void insertAt(GeneralIterator& it, int data) {
        Node<T>* newNode = new Node<T>{ data };

        if (it == end()) {
            InsertAtTail(data);
            return;
        }

        newNode->next = it.current;
        newNode->prev = it.current->prev;

        if (it.current->prev) {
            it.current->prev->next = newNode;
        }

        it.current->prev = newNode;

        if (it == begin()) {
            head = newNode;
        }
    }
    void insertAtAfter(GeneralIterator& it, int data) {
        Node<T>* newNode = new Node<T>{ data};

        newNode->next = it.current->next;
        newNode->prev = it.current;

        if (it.current->next) {
            it.current->next->prev = newNode;
        }

        it.current->next = newNode;

        if (it.current == tail) {
            tail = newNode;
        }
    }
    void insertAtBefore(GeneralIterator& it, int data) {
        insertAt(it, data);
    }
    void InsertAtFront(int data) {
        Node<T>* newNode = new Node<T>{ data,nullptr,nullptr};

        if (Empty()) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void InsertAtTail(int data) {
        Node<T>* newNode = new Node<T>{ data };

        if (Empty()) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void RemoveAt(GeneralIterator& it) {
        if (it == end()) return;

        if (it.current->prev) {
            it.current->prev->next = it.current->next;
        }
        if (it.current->next) {
            it.current->next->prev = it.current->prev;
        }

        if (it == begin()) {
            head = it.current->next;
        }
        if (it.current == tail) {
            tail = it.current->prev;
        }

        delete it.current;
    }
    void splice(GeneralIterator& it, DoublyLinkedList& otherList) {
        if (it == end()) {
            tail->next = otherList.head;
            otherList.head->prev = tail;
            tail = otherList.tail;
        }
        else {
            it.current->next->prev = otherList.tail;
            otherList.tail->next = it.current->next;
            it.current->next = otherList.head;
            otherList.head->prev = it.current;
        }
    }
};
//////////////////////////Problem1///////////////////
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

    ListNode* result;
    if (list1 == nullptr)
    {
        return list2;
    }
    else if (list2 == nullptr)
    {
        return list1;
    }
    else if (list1->val <= list2->val)
    {
        result = list1;
        result->next = mergeTwoLists(list1->next, list2);
    }
    else if (list1->val >= list2->val)
    {
        result = list2;
        result->next = mergeTwoLists(list1, list2->next);
    }
    return result;
}
//////////////////////////Problem02//////////////////////////
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    ListNode* temp2 = head;
    int c = 0;
    while (temp != nullptr)
    {
        c++;
        temp = temp->next;
    }
    if (n > c)
    {
        return nullptr;
    }
    if (c - n == 0)
    {
        return head->next;
    }
    temp = head;
    for (int i = 0; i < c - n; i++)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = temp->next;
    return head;
}
//////////////////////////Problem03///////////////////////
ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    ListNode* present = head, * previous = nullptr, * pre_previous = nullptr;
    int count = 0;
    while (present)
    {
        if (present->next == nullptr)break;
        if (count > 0)
        {
            pre_previous = previous;
        }
        previous = present;
        present = present->next;
        previous->next = present->next;
        if (count > 0)
        {
            pre_previous->next = present;
        }
        if (present)
        {
            present->next = previous;
        }
        if (count == 0)
        {
            head = present;
        }
        present = previous->next;
        count += 1;
    }
    return head;
}
///////////////////////////////////Problem04/////////////////////////////////
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};
class MyLinkedList {
public:
    int size = 0;
    Node* head = NULL;
    Node* tail = NULL;
    MyLinkedList() {

    }

    int get(int index) {
        if (index >= size)
            return -1;
        Node* temp = head;
        for (int i = 0; i < index; ++i)
            temp = temp->next;

        return temp->val;
    }

    void addAtHead(int val) {
        Node* nnode = new Node(val);
        nnode->next = head;
        head = nnode;
        if (size == 0)
            tail = nnode;
        size++;
    }

    void addAtTail(int val) {
        if (size == 0) {
            addAtHead(val);
            return;
        }
        Node* nnode = new Node(val);
        tail->next = nnode;
        tail = nnode;
        size++;
    }

    void addAtIndex(int index, int val) {
        if (index > size)
            return;
        else if (index == size)
            addAtTail(val);
        else if (index == 0)
            addAtHead(val);
        else {
            Node* temp = head;
            Node* nnode = new Node(val);
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            nnode->next = temp->next;
            temp->next = nnode;
            size++;
        }
    }

    void deleteAtIndex(int index) {
        if (index >= size)
            return;
        else if (index == size - 1) {

            if (index == 0) {
                head == NULL;
                tail == NULL;
            }
            else {
                Node* temp = head;
                while (temp->next != tail) {
                    temp = temp->next;
                }
                tail = temp;
                temp->next = NULL;
            }

        }
        else if (index == 0) {
            Node* temp = head;
            head = head->next;
            temp = NULL;
        }
        else {
            Node* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node* t = temp->next;
            temp->next = temp->next->next;
            t->next = NULL;

        }
        size--;
    }
};
