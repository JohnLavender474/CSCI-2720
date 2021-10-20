#ifndef CSCI2720_PROJECTS_NARYTREE_H
#define CSCI2720_PROJECTS_NARYTREE_H

#include <cstddef>
#include <vector>

/* NaryTreeNode =================================================================================================== */

/* Forward declaration of NaryTree. */
template<class T, class A>
class NaryTree;

/*
 * All NaryTreeNode objects contain a data field.
 * Access to the children and parent of the object
 * is implemented in the deriving class.
 */
template<class T>
class NaryTreeNode
{
public:
	NaryTreeNode();
	NaryTreeNode(T data_field);
	~NaryTreeNode();
	void set_data(const T & new_data);
	const T & get_data() const;
	
protected:
	T data_field;
};

template<class T>
NaryTreeNode<T>::NaryTreeNode() :
		data_field(nullptr) {}

template<class T>
NaryTreeNode<T>::NaryTreeNode(T data_field) :
		data_field(data_field) {}

template<class T>
inline NaryTreeNode<T>::~NaryTreeNode() {}

template<class T>
void NaryTreeNode<T>::set_data(const T & new_data)
{
	this->data_field = new_data;
}

template<class T>
const T & NaryTreeNode<T>::get_data() const
{
	return this->data_field;
}
		
/* ================================================================================================================ */

/* NaryTree ======================================================================================================= */

/*
 * The way an NaryTreeNode object is accessed from an NaryTree
 * is left to the deriving class, and is specified by class A.
 * For example, if size_t is passed into type A, NaryTreeNode
 * objects are accessed via size_t (array-indexed access).
 * NaryTreeNode<T> could also be passed into type A, meaning
 * NaryTreeNode objects are accessed via pointers.
 */
template<class T, class A>
class NaryTree
{
public:
	NaryTree() = delete;
	NaryTree(size_t max_num_children_per_node);
	virtual ~NaryTree();
	virtual const size_t & n_ary_num();
	virtual void push_back(NaryTreeNode<T> * back_node) = 0;
	virtual NaryTreeNode<T> * get_root() = 0;
	virtual void set_root(NaryTreeNode<T> * new_root) = 0;
	virtual NaryTreeNode<T> * get_parent(A node_access) = 0;
	virtual void set_parent(A node_access, NaryTreeNode<T> * new_parent) = 0;
	virtual NaryTreeNode<T> * get_nth_child(A parent_access, size_t nth_child) = 0;
	virtual void set_nth_child(A parent_access, size_t nth_child, NaryTreeNode<T> * new_child) = 0;
	virtual std::vector<NaryTreeNode<T> *> * get_children(A node_access) = 0;
	virtual void set_children(A node_access, std::vector<NaryTreeNode<T> *> children) = 0;
	virtual void clear() = 0;
	virtual size_t size() const = 0;
	virtual NaryTree<T, A> * copy(A first_access, A last_access) const = 0;
	virtual std::vector<NaryTreeNode<T> *> * get_preorder_vector(A access) = 0;
	virtual std::vector<NaryTreeNode<T> *> * get_postorder_vector(A access) = 0;
	virtual std::vector<NaryTreeNode<T> *> * get_inorder_vector(A access) = 0;
	virtual void preorder_print(A access) = 0;
	virtual void postorder_print(A access) = 0;
	virtual void inorder_print(A access) = 0;
protected:
	const size_t max_num_children_per_node;
};

template<class T, class A>
NaryTree<T, A>::NaryTree(size_t max_num_children_per_node) :
		max_num_children_per_node(max_num_children_per_node) {}
		
template<class T, class A>
inline NaryTree<T, A>::~NaryTree() {}

template<class T, class A>
const size_t & NaryTree<T, A>::n_ary_num()
{
	return this->max_num_children_per_node;
}

/* ================================================================================================================ */

#endif
