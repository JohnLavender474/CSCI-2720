#pragma once

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

template<typename K, typename V>
AVL_Node<K, V>::AVL_Node(K key, V value) :
		key(key), value(value), height(0), left(nullptr), right(nullptr)
{}

template<typename K, typename V>
K AVL_Node<K, V>::get_key()
{
	return key;
}

template<typename K, typename V>
V AVL_Node<K, V>::get_value()
{
	return value;
}

