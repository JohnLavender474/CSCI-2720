#include "../hdr/AVL_Tree.h"

template<typename K, typename V>
AVL_Tree<K, V>::AVL_Tree() :
		root(nullptr), size(0)
{}

template<typename K, typename V>
AVL_Tree<K, V>::~AVL_Tree()
{
	delete_tree(root);
}

template<typename K, typename V>
int AVL_Tree<K, V>::get_size()
{
	return size;
}

template<typename K, typename V>
int AVL_Tree<K, V>::get_height()
{
	return (int) protected_height(root);
}

template<typename K, typename V>
void AVL_Tree<K, V>::insert(K key, V value)
{
	root = protected_insert(root, key, value);
}

template<typename K, typename V>
void AVL_Tree<K, V>::remove(K key)
{
	root = protected_delete(root, key);
}

template<typename K, typename V>
void AVL_Tree<K, V>::inorder_function(Function<AVL_Node<K, V> *> &function)
{
	protected_inorder_function(root, function);
}

template<typename K, typename V>
void AVL_Tree<K, V>::levelorder_function(Function<AVL_Node<K, V> *> &function)
{
	protected_levelorder_function(root, function);
}

template<typename K, typename V>
void AVL_Tree<K, V>::preorder_function(Function<AVL_Node<K, V> *> &function)
{
	protected_preorder_function(root, function);
}

template<typename K, typename V>
void AVL_Tree<K, V>::postorder_function(Function<AVL_Node<K, V> *> &function)
{
	protected_postorder_function(root, function);
}

template<typename K, typename V>
void AVL_Tree<K, V>::delete_tree(AVL_Node<K, V> *&node)
{
	if (node != nullptr)
	{
		delete node->left;
		delete node->right;
		delete node;
	}
}

template<typename K, typename V>
AVL_Node<K, V> *AVL_Tree<K, V>::create(K key, V value)
{
	std::cout << "creating new node" << std::endl;
	return new AVL_Node<K, V>(key, value);
}

template<typename K, typename V>
void AVL_Tree<K, V>::protected_inorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function)
{
	if (node == nullptr)
	{
		return;
	}
	protected_inorder_function(node->left, function);
	function.function(node);
	protected_inorder_function(node->right, function);
}


template<typename K, typename V>
void AVL_Tree<K, V>::protected_levelorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function)
{
	if (node == nullptr)
	{
		return;
	}
	else
	{
		std::queue<AVL_Node<K, V> *> q;
		q.push(node);
		while (!q.empty())
		{
			AVL_Node<K, V> *temp = q.front();
			q.pop();
			if (temp == nullptr)
			{
				continue;
			}
			else
			{
				function.function(temp);
				q.push(temp->left);
				q.push(temp->right);
			}
		}
	}
}

template<typename K, typename V>
void AVL_Tree<K, V>::protected_preorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function)
{
	if (node == nullptr)
	{
		return;
	}
	function.function(node);
	protected_preorder_function(node->left, function);
	protected_preorder_function(node->right, function);
}

template<typename K, typename V>
void AVL_Tree<K, V>::protected_postorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function)
{
	if (node == nullptr)
	{
		return;
	}
	protected_postorder_function(node->left, function);
	protected_postorder_function(node->right, function);
	function.function(node);
}

template<typename K, typename V>
int AVL_Tree<K, V>::protected_height(AVL_Node<K, V> *&node)
{
	int h = 0;
	if (node != nullptr)
	{
		int l_height = protected_height(node->left);
		int r_height = protected_height(node->right);
		int max_height = std::max(l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

template<typename K, typename V>
AVL_Node<K, V> *AVL_Tree<K, V>::protected_insert(AVL_Node<K, V> *&node, K key, V value)
{
	if (node == nullptr)
	{
		return create(key, value);
	}
	if (node->key > key)
	{
		node->left = protected_insert(node->left, key, value);
	}
	else
	{
		node->right = protected_insert(node->right, key, value);
	}
	node->height = protected_height(node);
	int balance = get_balance(node);
	if (balance > 1)
	{
		if (key > node->left
				->key)
		{
			node->left = left_left_rotate(node->left);
		}
		return right_right_rotate(node);
	}
	else if (balance < -1)
	{
		if (key < node->right
				->key)
		{
			node->right = right_right_rotate(node->right);
		}
		return left_left_rotate(node);
	}
	return node;
}

template<typename K, typename V>
AVL_Node<K, V> *AVL_Tree<K, V>::left_left_rotate(AVL_Node<K, V> *&x)
{
	AVL_Node<K, V> *y = x->right;
	AVL_Node<K, V> *a = y->left;
	y->left = x;
	x->right = a;
	x->height = protected_height(x);
	y->height = protected_height(y);
	return y;
}

template<typename K, typename V>
AVL_Node<K, V> *AVL_Tree<K, V>::right_right_rotate(AVL_Node<K, V> *&y)
{
	AVL_Node<K, V> *x = y->left;
	AVL_Node<K, V> *a = x->right;
	x->right = y;
	y->left = a;
	x->height = protected_height(x);
	y->height = protected_height(y);
	return x;
}

template<typename K, typename V>
int AVL_Tree<K, V>::get_balance(AVL_Node<K, V> *node)
{
	if (node != nullptr)
	{
		return protected_height(node->left) - protected_height(node->right);
	}
	else
	{
		return 0;
	}
}

template<typename K, typename V>
AVL_Node<K, V> *AVL_Tree<K, V>::protected_delete(AVL_Node<K, V> *&node, K key)
{
	if (node == nullptr)
	{
		return node;
	}
	if (key > node->key)
	{
		node->right = protected_delete(node->right, key);
		if (get_balance(node) > 1)
		{
			if (get_balance(node->left) >= 0)
			{
				node = left_left_rotate(node);
			}
			else
			{
				node = left_right_rotate(node);
			}
		}
	}
	else
	{
		if (key < node->key)
		{
			node->left = protected_delete(node->left, key);
			if (get_balance(node) < -1)
			{
				if (get_balance(node->right) <= 0)
				{
					node = right_right_rotate(node);
				}
				else
				{
					node = right_left_rotate(node);
				}
			}
		}
		else
		{
			if (node->right != nullptr)
			{
				AVL_Node<K, V> *temp = node->right;
				while (temp->left != nullptr)
				{
					temp = temp->left;
				}
				node->key = temp->key;
				node->value = temp->value;
				node->right = protected_delete(node->right, temp->key);
				if (get_balance(node) > 1)
				{
					if (get_balance(node->left) >= 0)
					{
						node = left_left_rotate(node);
					}
					else
					{
						node = left_right_rotate(node);
					}
				}
			}
			else
			{
				return node->left;
			}
		}
	}
	node->height = protected_height(node);
	return node;
}

template<typename K, typename V>
AVL_Node<K, V> *AVL_Tree<K, V>::left_right_rotate(AVL_Node<K, V> *&x)
{
	x->left = left_left_rotate(x->left);
	x = right_right_rotate(x);
	return x;
}

template<typename K, typename V>
AVL_Node<K, V> *AVL_Tree<K, V>::right_left_rotate(AVL_Node<K, V> *&y)
{
	y->right = right_right_rotate(y->right);
	y = left_left_rotate(y);
	return y;
}














