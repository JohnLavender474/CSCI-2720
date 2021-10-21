#ifndef CSCI2720_PROJECTS_LINKEDNARYTREE_H
#define CSCI2720_PROJECTS_LINKEDNARYTREE_H

#include "NaryTree.h"

/* ========================================================================================================== */
/* === LinkedNaryTreeNode === */
template<class T>
class LinkedNaryNode : public NaryNode<T>
{
public:
	LinkedNaryNode() = delete;
	LinkedNaryNode(T data_field, LinkedNaryNode<T> * parent, size_t max_num_children);
	~LinkedNaryNode() override;
	bool is_filled() override;
	size_t get_max_num_children() override;
	void insert_child(NaryNode<T> * child) override;
	NaryNode<T> * get_nth_child(size_t n) override;
	NaryNode<T> * get_parent() override;
protected:
	LinkedNaryNode<T> * _parent;
	std::vector<LinkedNaryNode<T> *> _children;
	size_t _max_num_children;
};

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === LinkedNaryTree === */
/*
 * An NaryTree implementation using pointers to link nodes.
 */
template<typename T>
class LinkedNaryTree : public NaryTree<T, NaryNode<T> *>
{
public:
	void insert(T data_field) override;
protected:
	NaryNode<T> * create(T data_field, NaryNode<T> * parent) override;
	void preorder_apply(NaryNode<T> * temp, Apply<NaryNode<T> *> apply) override;
	void postorder_apply(NaryNode<T> * temp, Apply<NaryNode<T> *> apply) override;
	void levelorder_apply(NaryNode<T> * temp, Apply<NaryNode<T> *> apply) override;
private:
	NaryNode<T> _root_ptr;
	size_t size;
};

/* ========================================================================================================== */

#endif
