#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include <iostream>

#include "Function.h"
#include "Comparable.h"

template<typename T> class LinkedList;

template<typename T> class LinkedNode {
	
	friend class LinkedList<T>;

public:
	T get_data();

private:
	LinkedNode() = delete;
	
	LinkedNode(T data);
	
	T data;
	LinkedNode<T> *prior;
	LinkedNode<T> *next;
};

template<class T> class LinkedList {
public:
	LinkedList();
	
	~LinkedList();
	
	void function(Function<T> &function);
	
	void add(T data);
	
	void add(size_t index, T data);
	
	T peek();
	
	T pop();
	
	void remove(T data);
	
	void remove(size_t index);
	
	size_t get_size();
	
	bool contains(T data);
	
	bool empty();
	
	T &get(size_t index);
	
	int get_index_of(T data);
	
	void print();

private:
	LinkedNode<T> *head;
	size_t size;
};

#include "../src/LinkedList.tpp"

#endif