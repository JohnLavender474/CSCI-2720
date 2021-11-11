#pragma once

template<typename K, typename V>
struct Entry
{
	K key;
	V value;
};

template<typename K, typename V>
class HashMap
{
public:
	HashMap() = delete;
	HashMap(size_t init_capacity);
	~HashMap() = default;
private:
	size_t size;
	size_t capacity;
};

template<typename K, typename V>
HashMap<K, V>::HashMap(size_t init_capacity)
{

}
