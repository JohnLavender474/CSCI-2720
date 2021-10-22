#pragma once

#include <cstddef>
#include <iostream>
#include <queue>

/* ========================================================================================================== */
/* === Apply === */

template<typename T>
class Apply {
public:
	Apply();
	virtual ~Apply();
	virtual void apply(T t) = 0;
};

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === NaryTree === */

// NaryNode forward declaration
template<typename T>
class NaryNode;

template<typename T>
class NaryTree
{
public:
	NaryTree();
	~NaryTree();
	void insert(T data_field, size_t max_num_children);
	void preorder_apply(Apply<NaryNode<T> *> & apply);
	void postorder_apply(Apply<NaryNode<T> *> & apply);
	void levelorder_apply(Apply<NaryNode<T> *> & apply);
	void linked_inversion_apply(Apply<NaryNode<T> *> & apply);
	size_t get_size();
protected:
	NaryNode<T> * create(T data_field, size_t max_num_children);
	void protected_preorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply);
	void protected_postorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply);
	void protected_levelorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply);
	void protected_linked_inversion_apply(NaryNode<T> *& Q, Apply<NaryNode<T> *> & apply);
	void delete_tree(NaryNode<T> * node);
private:
	NaryNode<T> * root;
	size_t size;
};

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === NaryNode === */

template<typename T>
class NaryNode {
public:
	friend class NaryTree<T>;
	T & get_data();
	~NaryNode();
	NaryNode() = delete;
private:
	NaryNode(T data_field, size_t max_num_children);
	T data_field;
	std::vector<NaryNode<T> *> children;
	size_t max_num_children;
	size_t inversion_bit;
};

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === Apply === */
template<typename T>
Apply<T>::Apply() {}

template<typename T>
Apply<T>::~Apply() {}

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === NaryTree === */

template<typename T>
NaryTree<T>::NaryTree() :
root(nullptr)
{}

template<typename T>
NaryTree<T>::~NaryTree()
{
	delete_tree(root);
}

template<typename T>
void NaryTree<T>::insert(T data_field, size_t max_num_children)
{
	if (this->root == nullptr)
	{
		this->root = this->create(data_field, max_num_children);
	}
	else
	{
		std::queue<NaryNode<T> *> q;
		q.push(this->root);
		while (!q.empty())
		{
			NaryNode<T> * parent = q.front();
			q.pop();
			for (size_t n = 0; n < parent->max_num_children; n++)
			{
				if (parent->children.at(n) != nullptr)
				{
					q.push(parent->children.at(n));
				}
				else
				{
					parent->children.at(n) = this->create(data_field, max_num_children);
					return;
				}
			}
		}
	}
}

template<typename T>
NaryNode<T> * NaryTree<T>::create(T data_field, size_t max_num_children)
{
	size++;
	return new NaryNode<T>(data_field, max_num_children);
}

template<typename T>
void NaryTree<T>::protected_preorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{
		apply.apply(temp);
		for (size_t n = 0; n < temp->max_num_children; n++)
		{
			protected_preorder_apply(temp->children.at(n), apply);
		}
	}
}

template<typename T>
void NaryTree<T>::protected_postorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{
		for (size_t n = 0; n < temp->max_num_children; n++)
		{
			protected_postorder_apply(temp->children.at(n), apply);
		}
		apply.apply(temp);
	}
}

template<typename T>
void NaryTree<T>::protected_levelorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{
		std::queue<NaryNode<T> *> q;
		q.push(temp);
		while (!q.empty())
		{
			NaryNode<T> * node = q.front();
			q.pop();
			if (node == nullptr)
			{
				return;
			}
			else
			{
				apply.apply(node);
				for (size_t n = 0; n < node->max_num_children; n++)
				{
					q.push(node->children.at(n));
				}
			}
		}
	}
}

template<typename T>
void NaryTree<T>::protected_linked_inversion_apply(NaryNode<T> *& Q, Apply<NaryNode<T> *> & apply)
{
	// The following works for a binary tree.
	// How to generalize this for variable n-ary tree?
	/*
	NaryNode<T> * P = nullptr;
	while (1)
	{
		while (Q != nullptr)
		{
			Q->inversion_bit = 0;
			P = Q;
			Q = Q->children.at(0);
			Q->children.at(0) = P;
		}
		while (P != nullptr && P->inversion_bit == 1)
		{
			Q = P;
			P = P->children.at(P->children.size() - 1);
			P->children.at(P->children.size() - 1) = Q;
		}
		if (P == nullptr)
		{
			return;
		}
		else
		{
			Q = P;
			P = P->children.at(0);
			P->children.at(0) = Q;
			Q->inversion_bit = 1;
			P = Q;
			Q = Q->children.at(0);
			Q->children.at(0) = P;
		}
		
	}
	 */
}

template<typename T>
void NaryTree<T>::preorder_apply(Apply<NaryNode<T> *> & apply)
{
	protected_preorder_apply(root, apply);
}

template<typename T>
void NaryTree<T>::postorder_apply(Apply<NaryNode<T> *> & apply)
{
	protected_postorder_apply(root, apply);
}

template<typename T>
void NaryTree<T>::levelorder_apply(Apply<NaryNode<T> *> & apply)
{
	protected_levelorder_apply(root, apply);
}


template<typename T>
void NaryTree<T>::linked_inversion_apply(Apply<NaryNode<T> *> &apply)
{

}


template<typename T>
size_t NaryTree<T>::get_size()
{
	return size;
}

template<typename T>
void NaryTree<T>::delete_tree(NaryNode<T> * node)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		for (size_t n = 0; n < node->max_num_children; n++)
		{
			delete_tree(node->children.at(n));
		}
		delete node;
	}
}

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === NaryNode === */

template<typename T>
T & NaryNode<T>::get_data()
{
	return data_field;
}

template<typename T>
NaryNode<T>::NaryNode(T data_field, size_t max_num_children) :
data_field(data_field),
children(max_num_children, nullptr),
max_num_children(max_num_children),
inversion_bit(0)
{}

template<typename T>
NaryNode<T>::~NaryNode()
{
	children.clear();
}

/* ========================================================================================================== */
