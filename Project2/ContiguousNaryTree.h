#ifndef CSCI2720_PROJECTS_CONTIGUOUSNARYTREE_H
#define CSCI2720_PROJECTS_CONTIGUOUSNARYTREE_H

#include "NaryTree.h"

template<class T>
class ContiguousNaryTree : public NaryTree<T, size_t>
{
public:
	ContiguousNaryTree() = delete;
	ContiguousNaryTree(size_t max_num_children_per_node, T data_field);
	~ContiguousNaryTree();
	const size_t & n_ary_size() override;
	void push_back(NaryTreeNode<T> * back_node) override;
	NaryTreeNode<T> * get_root() override;
	void set_root(NaryTreeNode<T> * new_root) override;
	NaryTreeNode<T> * get_parent(size_t node_access) override;
	void set_parent(size_t node_access, NaryTreeNode<T> * new_parent) override;
	NaryTreeNode<T> * get_nth_child(size_t parent_access, size_t nth_child) override;
	size_t get_nth_child_index(size_t parent_access, size_t nth_child);
	void set_nth_child(size_t parent_access, size_t nth_child, NaryTreeNode<T> * new_child) override;
	std::vector<NaryTreeNode<T> *> * get_children(size_t node_access) override;
	void set_children(size_t node_access, std::vector<NaryTreeNode<T> *> children) override;
	void clear() override;
	size_t size() override;
	NaryTree<T, size_t> * copy(size_t first_access, size_t last_access) override;
	std::vector<NaryTreeNode<T> *> * get_preorder_vector(
			size_t access, std::vector<NaryTreeNode<T> *> & container) override;
protected:
	std::vector<NaryTreeNode<T> *> nodes;
};

#endif
