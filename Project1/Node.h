#ifndef CSCI2720_PROJECT1_NODE_H
#define CSCI2720_PROJECT1_NODE_H

template<class T>
class Node {
public:
	Node() {
	    this->next = nullptr;
    } // Node
    T data;
    Node<T> * next;
}; // public

#endif //CSCI2720_PROJECT1_NODE_H
