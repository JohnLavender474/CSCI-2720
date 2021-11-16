#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP

#include <iostream>
#include <utility>
#include <queue>

#include "Function.h"
#include "AVL_Node.h"

template<typename K, typename V>
class AVL_Node;

template<typename K, typename V>
class AVL_Tree
{
public:
	AVL_Tree();
	
	~AVL_Tree();
	
	int get_size();
	
	int get_height();
	
	void insert(K key, V value);
	
	void remove(K key);
	
	bool get(K key, V &value);
	
	bool contains(K key, bool print_path);
	
	void inorder_function(Function<AVL_Node<K, V> *> &function);
	
	void levelorder_function(Function<AVL_Node<K, V> *> &function);
	
	void preorder_function(Function<AVL_Node<K, V> *> &function);
	
	void postorder_function(Function<AVL_Node<K, V> *> &function);

protected:
	AVL_Node<K, V> *create(K key, V value);
	
	int get_balance(AVL_Node<K, V> *node);
	
	int protected_height(AVL_Node<K, V> *&node);
	
	AVL_Node<K, V> *protected_insert(AVL_Node<K, V> *&node, K key, V value);
	
	AVL_Node<K, V> *protected_remove(AVL_Node<K, V> *&node, K key);
	
	bool protected_get(AVL_Node<K, V> *&node, K key, V &value);
	
	bool protected_contains(AVL_Node<K, V> *&node, K key, bool print_path);
	
	void protected_inorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function);
	
	void protected_levelorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function);
	
	void protected_preorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function);
	
	void protected_postorder_function(AVL_Node<K, V> *&node, Function<AVL_Node<K, V> *> &function);

private:
	void delete_tree(AVL_Node<K, V> *&node);
	
	AVL_Node<K, V> *left_left_rotate(AVL_Node<K, V> *&x);
	
	AVL_Node<K, V> *right_right_rotate(AVL_Node<K, V> *&y);
	
	AVL_Node<K, V> *left_right_rotate(AVL_Node<K, V> *&x);
	
	AVL_Node<K, V> *right_left_rotate(AVL_Node<K, V> *&y);
	
	int size;
	AVL_Node<K, V> *root;
};

#include "../src/AVL_Tree.tpp"

#endif