#pragma once

template<class T> class Node {
public:
	Node() {
		this->next = nullptr;
	}
	
	T data;
	Node<T> *next;
};

