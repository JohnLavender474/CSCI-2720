#ifndef CSCI2720_PROJECTS_NARYTREE_H
#define CSCI2720_PROJECTS_NARYTREE_H

#include <cstddef>
#include <iostream>

/* ========================================================================================================== */
/* === Apply === */
/*
 * A functional interface allowing a set function to be applied to a data type.
 * typename A designates the type that will undergo application in the function.
 */
template<typename A>
class Apply
{
	virtual void apply(A a) = 0;
};

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === NaryNode === */
/*
 * A base class for nodes in an NaryTree.
 * The destructor is abstract, so this class must be derived.
 * typename T designates the data type to be stored in var data_field.
 */
template<typename T>
class NaryNode
{
public:
	NaryNode() = delete;
	NaryNode(T data_field);
	virtual ~NaryNode() = 0;
	virtual bool is_filled() = 0;
	virtual size_t get_max_num_children() = 0;
	virtual void insert_child(NaryNode<T> * child) = 0;
	virtual NaryNode<T> * get_nth_child(size_t n) = 0;
	virtual NaryNode<T> * get_parent() = 0;
	virtual T get_data_field();
protected:
	T _data_field;
};

template<typename T>
NaryNode<T>::NaryNode(T data_field) : _data_field(data_field) {}

template<typename T>
NaryNode<T>::~NaryNode() {}

template<typename T>
T NaryNode<T>::get_data_field()
{
	return this->_data_field;
}

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === NaryTree === */
/*
 * typename T designates the data type to be stored in var data_field of NaryNode instances.
 * typename A designates the type to be passed into the apply function.
 */
template<typename T, typename A>
class NaryTree {
public:
	virtual ~NaryTree() = 0;
	virtual void insert(T data) = 0;
protected:
	virtual NaryNode<T> * create(T data_field, NaryNode<T> * parent) = 0;
	virtual void preorder_apply(NaryNode<T> * temp, Apply<A> apply) = 0;
	virtual void postorder_apply(NaryNode<T> * temp, Apply<A> apply) = 0;
	virtual void levelorder_apply(NaryNode<T> * temp, Apply<A> apply) = 0;
};

template<typename T, typename A>
NaryTree<T, A>::~NaryTree<T, A>() {}

/* ========================================================================================================== */

#endif