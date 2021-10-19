#include "LinkedNaryTreeNode.h"

#include <vector>

template<class T>
LinkedNaryTreeNode<T>::LinkedNaryTreeNode() :
		data_field(), children(9, nullptr) {}

template<class T>
LinkedNaryTreeNode<T>::LinkedNaryTreeNode(size_t size) :
		data_field(), children(size, nullptr) {}

template<class T>
LinkedNaryTreeNode<T>::LinkedNaryTreeNode(size_t size, T value) :
		data_field(value), children(size, nullptr) {}

template<class T>
LinkedNaryTreeNode<T>::LinkedNaryTreeNode(T value, std::vector<LinkedNaryTreeNode<T> *> constructChildren) :
		data_field(value), children(constructChildren) {}
		
template<class T>
LinkedNaryTreeNode<T>::~LinkedNaryTreeNode() {
	for (size_t i = 0; i < children.size(); i++) {
		delete children.at(i);
	} // for
} // destructor
		
template<class T>
void LinkedNaryTreeNode<T>::setData(const T & new_data) {
	data_field = new_data;
} // setData

template<class T>
void LinkedNaryTreeNode<T>::setChildAt(size_t index, LinkedNaryTreeNode<T> * newChild) {
	children.at(index) = newChild;
} // setChildAt

template<class T>
size_t LinkedNaryTreeNode<T>::numOfChildren() const {
	return children.size();
} // numOfChildren

template<class T>
T & LinkedNaryTreeNode<T>::getData() const {
	return data_field;
} // data

template<class T>
LinkedNaryTreeNode<T> *& LinkedNaryTreeNode<T>::getChildAt(size_t index) const {
	return children.at(index);
} // getChildAt

template<class T>
void LinkedNaryTreeNode<T>::clear(LinkedNaryTreeNode<T> *& root_ptr) {
	LinkedNaryTreeNode<T> * child;
	if (root_ptr != nullptr) {
		for (size_t i = 0; i < root_ptr->numOfChildren(); i++) {
			child = root_ptr->getChildAt(i);
			clearTree(child);
			delete root_ptr;
			root_ptr = nullptr;
		} // for
	} // if
} // clear

template<class T>
LinkedNaryTreeNode<T> * LinkedNaryTreeNode<T>::copy(const LinkedNaryTreeNode<T> * rootPtr) {
	if (rootPtr == nullptr) {
		return nullptr;
	} // if
	std::vector<LinkedNaryTreeNode<T> * > copy_children;
	for (size_t i = 0; i < rootPtr->numOfChildren(); i++) {
		copy_children.push_back(rootPtr->getChildAt(i));
	} // for
	return new LinkedNaryTreeNode<T>(rootPtr->getData(), copy_children);
} // copy










