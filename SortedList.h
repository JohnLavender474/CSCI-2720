#ifndef CSCI2720_PROJECT1_SORTEDLIST_H
#define CSCI2720_PROJECT1_SORTEDLIST_H

#include "Node.h"

template<class T>
class SortedList {
public:
    SortedList();
    ~SortedList();
    T & get(int index);
    void insert(T data);
    void remove(int index);
    int indexOf(T data);
    int getLength();
    void display();
private:
    int length;
    Node<T> * head;
    Node<T> * getNode(int index);
    void indexedInsert(int index, T data);
}; // SortedList

#endif