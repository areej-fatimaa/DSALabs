#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

int main() {
    DoublyLinkedList<int> list;
    DoublyLinkedList<int>::GeneralIterator it = list.begin();

    // Test insertAt
    list.InsertAtFront(1);
    list.InsertAtTail(3);
    list.insertAt(it, 2);

    // Print the list
    for (DoublyLinkedList<int>::GeneralIterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Test insertAtAfter and insertAtBefore
    DoublyLinkedList<int>::GeneralIterator it2 = list.begin();
    ++it2;
    list.insertAtAfter(it2, 4);
    list.insertAtBefore(it2, 5);

    // Print the list
    for (DoublyLinkedList<int>::GeneralIterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Test RemoveAt
    DoublyLinkedList<int>::GeneralIterator it3 = list.begin();
    ++it3;
    list.RemoveAt(it3);

    // Print the list
    for (DoublyLinkedList<int>::GeneralIterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    // Test splice
    DoublyLinkedList<int> list2;
    list2.InsertAtTail(6);
    list2.InsertAtTail(7);

    DoublyLinkedList<int>::GeneralIterator it4 = list.begin();
    ++it4;
    list.splice(it4, list2);

    // Print the list
    for (DoublyLinkedList<int>::GeneralIterator it = list.begin(); it != list.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}

