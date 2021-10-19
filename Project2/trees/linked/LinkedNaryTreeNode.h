#ifndef CSCI2720_PROJECT2_LINKEDNARYTREENODE_H
#define CSCI2720_PROJECT2_LINKEDNARYTREENODE_H

#include <vector>

template<class T>
class LinkedNaryTreeNode {
public:
	LinkedNaryTreeNode();
	LinkedNaryTreeNode(size_t size);
	LinkedNaryTreeNode(size_t size, T value);
	LinkedNaryTreeNode(T value, std::vector<LinkedNaryTreeNode<T> *>);
	~LinkedNaryTreeNode();
	void setData(const T & new_data);
	void setChildAt(size_t index, LinkedNaryTreeNode<T> * newChild);
	void clear(LinkedNaryTreeNode<T> *& root_ptr);
	LinkedNaryTreeNode * copy(const LinkedNaryTreeNode<T> * rootPtr);
	T & getData() const;
	size_t numOfChildren() const;
	LinkedNaryTreeNode<T> *& getChildAt(size_t index) const;
private:
	T data_field;
	std::vector<LinkedNaryTreeNode<T> * > children;
};

#endif
