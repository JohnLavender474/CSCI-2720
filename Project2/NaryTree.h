#pragma once

#include <cstddef>
#include <iostream>
#include <queue>
#include <random>

#include "T3SolverImplementation.h"

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
	void insert(T data_field, int max_num_children);
	void preorder_apply(Apply<NaryNode<T> *> & apply);
	void postorder_apply(Apply<NaryNode<T> *> & apply);
	void levelorder_apply(Apply<NaryNode<T> *> & apply);
	void linked_inversion_apply(Apply<NaryNode<T> *> & apply, std::string traversal);
	void random_branch_apply(Apply<NaryNode<T> *> & apply);
	int get_size();
protected:
	NaryNode<T> * create(NaryNode<T> * parent, T data_field, int max_num_children);
	void protected_preorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply);
	void protected_postorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply);
	void protected_levelorder_apply(NaryNode<T> *& temp, Apply<NaryNode<T> *> & apply);
	void delete_tree(NaryNode<T> * node);
private:
	NaryNode<T> * root;
	int size;
};

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === NaryNode === */

template<typename T>
class NaryNode
{
public:
	friend class NaryTree<T>;
	T & get_data();
	~NaryNode();
	NaryNode() = delete;
protected:
	NaryNode(NaryNode<T> * parent, T data_field, int max_num_children);
	T data_field;
	NaryNode<T> * parent;
	std::vector<NaryNode<T> *> children;
	int max_num_children;
	bool inversion_bit;
	int traversal_bit;
	int initialized;
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
void NaryTree<T>::insert(T data_field, int max_num_children)
{
	if (this->root == nullptr)
	{
		this->root = this->create(nullptr, data_field, max_num_children);
	}
	else
	{
		std::queue<NaryNode<T> *> q;
		q.push(this->root);
		while (!q.empty())
		{
			NaryNode<T> * parent = q.front();
			q.pop();
			for (int n = 0; n < parent->max_num_children; n++)
			{
				if (parent->children.at(n) != nullptr)
				{
					q.push(parent->children.at(n));
				}
				else
				{
					parent->children.at(n) = this->create(parent, data_field, max_num_children);
					return;
				}
			}
		}
	}
}

template<typename T>
NaryNode<T> * NaryTree<T>::create(NaryNode<T> * parent, T data_field, int max_num_children)
{
	size++;
	return new NaryNode<T>(parent, data_field, max_num_children);
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
		for (int n = 0; n < temp->max_num_children; n++)
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
		for (int n = 0; n < temp->max_num_children; n++)
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
				for (int n = 0; n < node->max_num_children; n++)
				{
					q.push(node->children.at(n));
				}
			}
		}
	}
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
void NaryTree<T>::linked_inversion_apply(Apply<NaryNode<T> *> & apply, std::string traversal)
{
	try {
		NaryNode<T> * prev, * temp, * curr;
		curr = this->root;
		while (1)
		{
			while (curr != nullptr)
			{
				if (traversal.compare("preorder") == 0)
				{
					apply.apply(curr);
				}
				curr->inversion_bit = false;
				temp = curr->children.at(curr->traversal_bit);
				curr->children.at(curr->traversal_bit) = prev;
				prev = curr;
				curr = temp;
			}
			while (prev != nullptr && prev->inversion_bit && prev->initialized == 0)
			{
				temp = prev->children.at(prev->traversal_bit);
				prev->children.at(prev->traversal_bit) = curr;
				curr = prev;
				prev = temp;
				curr->traversal_bit = 0;
				if (traversal.compare("postorder") == 0)
				{
					apply.apply(curr);
				}
			}
			if (prev == nullptr || prev->initialized != 0)
			{
				return;
			}
			else
			{
				temp = prev->children.at(prev->traversal_bit);
				prev->children.at(prev->traversal_bit) = curr;
				curr = prev;
				prev = temp;
				if (curr->traversal_bit < curr->children.size() - 1)
				{
					curr->traversal_bit++;
				}
				else
				{
					curr->inversion_bit = true;
				}
				temp = curr->children.at(curr->traversal_bit);
				curr->children.at(curr->traversal_bit) = prev;
				prev = curr;
				curr = temp;
			}
		}
	}
	catch (const std::out_of_range & oor)
	{
		std::cout << "/*" << std::endl;
		std::cout << "linked inversion traversal has stopped either because" << std::endl;
		std::cout << "the traversal has reached its end or because an error" << std::endl;
		std::cout << "has been encountered. if the number of print statments" << std::endl;
		std::cout << "is less than that of the normal preorder, postorder, or" << std::endl;
		std::cout << "levelorder print function, then an error has occurred." << std::endl;
		std::cout << "*/" << std::endl;
	}
}


template<typename T>
int NaryTree<T>::get_size()
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
		for (int n = 0; n < node->max_num_children; n++)
		{
			delete_tree(node->children.at(n));
		}
		delete node;
	}
}

template<typename T>
void NaryTree<T>::random_branch_apply(Apply<NaryNode<T> *> & apply)
{
	NaryNode<T> * temp = root;
	std::queue<NaryNode<T> *> q;
	q.push(temp);
	srand(time(0));
	while (1)
	{
		if (temp->children.size() == 0)
		{
			goto done;
		}
		int random = rand() % temp->children.size();
		while (temp->children.at(random) == nullptr)
		{
			random--;
			if (random < 0)
			{
				goto done;
			}
		}
		temp = temp->children.at(random);
		q.push(temp);
	}
	done:
	std::queue<NaryNode<T> *> reversed_q;
	while (!q.empty())
	{
		reversed_q.push(q.front());
		q.pop();
	}
	while (!reversed_q.empty())
	{
		apply.apply(reversed_q.front());
		reversed_q.pop();
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
NaryNode<T>::NaryNode(NaryNode<T> * parent, T data_field, int max_num_children) :
data_field(data_field),
parent(parent),
children(max_num_children + 1, nullptr),
max_num_children(max_num_children),
inversion_bit(true),
traversal_bit(0),
initialized(0)
{}

template<typename T>
NaryNode<T>::~NaryNode()
{
	children.clear();
}

/* ========================================================================================================== */
