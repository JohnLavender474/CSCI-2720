#ifndef AVL_NODE_HPP
#define AVL_NODE_HPP

#include "Comparable.h"

template<typename K, typename V>
class AVL_Tree;

template<typename K, typename V>
class AVL_Node
{
	static_assert(std::is_base_of<Comparable<K>, K>::value, "Key must derive Comparable<Key>");
	
	friend class AVL_Tree<K, V>;

public:
	K get_key();
	
	V get_value();

private:
	AVL_Node() = delete;
	
	AVL_Node(K key, V value);
	
	~AVL_Node() = default;
	
	K key;
	V value;
	size_t height;
	AVL_Node<K, V> *left;
	AVL_Node<K, V> *right;
};

#include "../src/AVL_Node.tpp"

#endif

