#include "../hdr/AVL_Node.h"

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