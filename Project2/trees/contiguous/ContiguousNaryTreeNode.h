#ifndef CSCI2720_PROJECT2_CONTIGUOUSNARYTREENODE_H
#define CSCI2720_PROJECT2_CONTIGUOUSNARYTREENODE_H

#include <vector>

template<class T>
class ContiguousNaryTreeNode {
public:
	ContiguousNaryTreeNode();
	ContiguousNaryTreeNode(int index);
	std::vector<int> getChildIndexes();
	
private:
	T data_field;
};


#endif
