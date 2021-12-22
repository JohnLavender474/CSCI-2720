#pragma once

#include "Node.h"

template<class T> class SortedList {
public:
	SortedList();
	
	~SortedList();
	
	void insert(T data);
	
	void remove(int index);
	
	int indexOf(T data);
	
	void indexedInsert(int index, T data);
	
	int getLength();
	
	void display();
	
	T &get(int index);
	
	Node<T> *head;
	
	Node<T> *getNode(int index);
	
	int length;
};
