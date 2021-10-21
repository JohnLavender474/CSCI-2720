#include <queue>
#include "LinkedNaryTree.h"

/* ========================================================================================================== */
/* === LinkedNaryNode === */

template<class T>
LinkedNaryNode<T>::LinkedNaryNode(T data_field, LinkedNaryNode<T> * parent, size_t max_num_children) :
		NaryNode<T>::NaryNode(data_field),
		_parent(parent),
		_children(max_num_children, nullptr),
		_max_num_children(max_num_children) {}
		
template<class T>
LinkedNaryNode<T>::~LinkedNaryNode()
{
	delete this;
}

template<class T>
bool LinkedNaryNode<T>::is_filled()
{
	return this->_children.size() == _max_num_children;
}

template<class T>
void LinkedNaryNode<T>::insert_child(NaryNode<T> * child)
{
	this->_children.push_back(child);
}

template<class T>
NaryNode<T> * LinkedNaryNode<T>::get_nth_child(size_t n)
{
	if (n < this->_children.size())
	{
		return this->_children.at(n);
	}
	else
	{
		return nullptr;
	}
}

template<class T>
NaryNode<T> * LinkedNaryNode<T>::get_parent()
{
	return this->parent;
}

template<class T>
size_t LinkedNaryNode<T>::get_max_num_children()
{
	return this->_max_num_children;
}

/* ========================================================================================================== */

/* ========================================================================================================== */
/* === LinkedNaryTree === */

template<class T>
void LinkedNaryTree<T>::insert(T data_field)
{
	if (this->_root_ptr == nullptr)
	{
		this->_root_ptr = this->create(data_field, nullptr);
	}
	else
	{
		std::queue<NaryNode<T> *> q;
		q.push(this->_root_ptr);
		while (!q.empty())
		{
			NaryNode<T> * temp = q.front();
			q.pop();
			for (size_t n= 0; n < temp->_max_num_children; n++)
			{
				NaryNode<T> * child = temp->get_nth_child(n);
				if (child != nullptr)
				{
					q.push(child);
				}
				else
				{
					child = this->create(data_field, temp);
					return;
				}
			}
		}
	}
}

template<typename T>
NaryNode<T> * LinkedNaryTree<T>::create(T data_field, NaryNode<T> * parent)
{
	return new LinkedNaryNode<T>(data_field, parent);
}

template<typename T>
void LinkedNaryTree<T>::preorder_apply(NaryNode<T> * temp, Apply<NaryNode<T> *> apply)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{
		apply.apply(temp);
		for (size_t n = 0; n < temp->get_max_num_children(); n++)
		{
			preorder_apply(temp->get_nth_child(n), apply);
		}
	}
}

template<typename T>
void LinkedNaryTree<T>::postorder_apply(NaryNode<T> * temp, Apply<NaryNode<T> *> apply)
{
	if (temp == nullptr)
	{
		return;
	}
	else
	{
		for (size_t n = 0; n < temp->get_max_num_children(); n++)
		{
			postorder_apply(temp->get_nth_child(n), apply);
		}
		apply.apply(temp);
	}
}

template<typename T>
void LinkedNaryTree<T>::levelorder_apply(NaryNode<T> * temp, Apply<NaryNode<T> *> apply)
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
			apply.apply(node);
			for (size_t n = 0; n < node->get_max_num_children(); n++)
			{
				q.push(node->get_nth_child(n));
			}
		}
	}
}

/* ========================================================================================================== */