#include "ContiguousNaryTree.h"

template<class T>
ContiguousNaryTree<T>::ContiguousNaryTree(size_t max_num_children_per_node, T data_field) :
		NaryTree<T, size_t>(max_num_children_per_node)
{
	nodes.at(0) = new NaryTreeNode<T>(data_field);
}

template<class T>
ContiguousNaryTree<T>::~ContiguousNaryTree() {
	for (auto p : nodes)
	{
		delete p;
	}
	nodes.clear();
}

template<class T>
const size_t & ContiguousNaryTree<T>::n_ary_size()
{
	return nodes.size();
}

template<class T>
void ContiguousNaryTree<T>::push_back(NaryTreeNode<T> * back_node)
{
	nodes.push_back(back_node);
}


template<class T>
NaryTreeNode<T> * ContiguousNaryTree<T>::get_root()
{
	return nodes.at(0);
}

template<class T>
void ContiguousNaryTree<T>::set_root(NaryTreeNode<T> * new_root)
{
	nodes.at(0) = new_root;
}

template<class T>
NaryTreeNode<T> * ContiguousNaryTree<T>::get_parent(size_t node_access)
{
	NaryTreeNode<T> * returnNode;
	node_access = (node_access - 1) / NaryTree<T, size_t>::n_ary_num();
	try
	{
		returnNode = nodes.at(node_access);
	}
	catch (const std::out_of_range & oor)
	{
		returnNode = nullptr;
	}
	return returnNode;
}

template<class T>
void ContiguousNaryTree<T>::set_parent(size_t node_access, NaryTreeNode<T> * new_parent)
{
	NaryTreeNode<T> * parent_node = this->get_parent(node_access);
	if (parent_node != nullptr)
	{
		parent_node = new_parent;
	}
}

template<class T>
NaryTreeNode<T> * ContiguousNaryTree<T>::get_nth_child(size_t parent_access, size_t nth_child)
{
	if (nth_child > NaryTree<T, size_t>::n_ary_num())
	{
		return nullptr;
	}
	if (parent_access >= this->nodes.size()) {
		return nullptr;
	}
	size_t child_index = (parent_access * NaryTree<T, size_t>::n_ary_num()) + nth_child;
	NaryTreeNode<T> * nth_child_node;
	try
	{
		nth_child_node = nodes.at(child_index);
	}
	catch (const std::out_of_range & oor)
	{
		nth_child_node = nullptr;
	}
	return nth_child_node;
}

template<class T>
size_t ContiguousNaryTree<T>::get_nth_child_index(size_t parent_access, size_t nth_child)
{
	if (nth_child > NaryTree<T, size_t>::n_ary_num() || nth_child < 1)
	{
		throw std::invalid_argument("nth_child value must be > 0 and <= max_num_children");
	}
	return parent_access * NaryTree<T, size_t>::n_ary_num() + nth_child;
}

template<class T>
void ContiguousNaryTree<T>::set_nth_child(size_t parent_access, size_t nth_child, NaryTreeNode<T> * new_child)
{
	NaryTreeNode<T> * child = this->get_nth_child(parent_access, nth_child);
	if (child != nullptr)
	{
		child = new_child;
	}
}

template<class T>
std::vector<NaryTreeNode<T> *> * ContiguousNaryTree<T>::get_children(size_t node_access)
{
	std::vector<NaryTreeNode<T> *> * children = new std::vector<NaryTreeNode<T>>;
	NaryTreeNode<T> * child;
	for (size_t i = 1; i <= NaryTree<T, size_t>::n_ary_num(); i++)
	{
		child = this->get_nth_child(node_access, i);
		if (child != nullptr)
		{
			children->push_back(child);
		}
		else
		{
			break;
		}
	}
	return children;
}

template<class T>
void ContiguousNaryTree<T>::set_children(size_t node_access, std::vector<NaryTreeNode<T> *> children)
{
	for (size_t i = 1; i <= NaryTree<T, size_t>::n_ary_num(); i++)
	{
		if (i > children.size())
		{
			return;
		}
		NaryTreeNode<T> * child = this->get_nth_child(node_access, i);
		if (child != nullptr)
		{
			child = children.at(i - 1);
		}
	}
}

template<class T>
void ContiguousNaryTree<T>::clear()
{
	for (size_t i = 0; i < nodes.size(); i++)
	{
		delete nodes.at(i);
	}
	nodes.clear();
}

template<class T>
size_t ContiguousNaryTree<T>::size()
{
	return nodes.size();
}

template<class T>
NaryTree<T, size_t> *ContiguousNaryTree<T>::copy(size_t first_access, size_t last_access)
{
	// unimplemented
	return nullptr;
}

template<class T>
std::vector<NaryTreeNode<T> *> *ContiguousNaryTree<T>::get_preorder_vector(
		size_t access, std::vector<NaryTreeNode<T> *> & container) {
	if (access < nodes.size())
	{
		if (nodes.at(access) != nullptr)
		{
			container.push_back(nodes.at(access));
			
		}
	}
	
}





























