#include <stdexcept>
#include <iostream>

#include "Node.h"
#include "SortedList.h"

using namespace std;

template<class T>
SortedList<T>::SortedList() {
    Node<T> *headNode = new Node<T>();
    this->head = headNode;
    this->head->next = nullptr;
    this->length = 0;
} // constructor

template<class T>
SortedList<T>::~SortedList() {
    Node<T> *temp;
    while (head != NULL) {
        temp = this->head;
        head = head->next;
        delete temp;
    } // while
} // destructor

template<class T>
int SortedList<T>::getLength() {
    return this->length;
} // getLength

template<class T>
T & SortedList<T>::get(int index) {
    return this->getNode(index)->data;
} // get

template<class T>
void SortedList<T>::insert(T data) {
    if (this->length == 0) {
        this->head->data = data;
        this->length++;
    } else {
        for (int i = 0; i < this->getLength(); i++) {
            if ((data) <= this->get(i)) {
                this->indexedInsert(i, data);
                return;
            } // if
        } // for
        this->indexedInsert(this->getLength(), data);
    } // sortedInsert
} // insert

template<class T>
void SortedList<T>::remove(int index) {
    if (index < 0 || index >= this->length) {
        throw invalid_argument("invalid index");
    } else if (index == 0) {
        Node<T> *temp = this->head;
        this->head = this->head->next;
        delete temp;
        this->length--;
    } else {
        Node<T> *beforeRemove = this->head;
        for (int i = 0; i < index - 1; i++) {
            beforeRemove = beforeRemove->next;
        } // for
        Node<T> *toRemove = beforeRemove->next;
        beforeRemove->next = toRemove->next;
        delete toRemove;
        this->length--;
    } // if
} // remove

template<class T>
int SortedList<T>::indexOf(T data) {
    for (int i = 0; i < length; i++) {
        if (this->get(i)->data == data) {
            return i;
        } // if
    } // for
    return -1;
} // getIndexOf

template<class T>
void SortedList<T>::display() {
    if (this->head == NULL) {
        cout << "NULL" << endl;
    } else {
        Node<T> *temp = this->head;
        while (temp != NULL) {
            cout << temp->data;
            temp = temp->next;
        } // while
    } // if
} // display

template<class T>
void SortedList<T>::indexedInsert(int index, T data) {
    if (index < 0 || index > this->length) {
        throw invalid_argument("invalid index");
    } else if (index == 0) {
        Node<T> *insertion = new Node<T>();
        insertion->data = data;
        insertion->next = this->head;
        this->head = insertion;
    } else if (this->head == NULL) {
        Node<T> *insertion = new Node<T>;
        insertion->data = data;
        this->head = insertion;
    } else {
        Node<T> *beforeInsertion = this->head;
        for (int i = 0; i < index - 1; i++) {
            if (beforeInsertion->next != NULL) {
                beforeInsertion = beforeInsertion->next;
            } else {
                throw invalid_argument("invalid index");
            } // if
        } // for
        Node<T> *afterInsertion = beforeInsertion->next;
        Node<T> *insertion = new Node<T>();
        insertion->data = data;
        insertion->next = afterInsertion;
        beforeInsertion->next = insertion;
    } // if
    this->length++;
} // indexedInsert

// Private
template<class T>
Node<T> *SortedList<T>::getNode(int index) {
    if (index == 0) {
        return this->head;
    } else if (index > this->length || index < 0) {
        throw invalid_argument("invalid index");
    } else {
        Node<T> *temp = this->head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        } // for
        return temp;
    } // if
} // getNode<T>





