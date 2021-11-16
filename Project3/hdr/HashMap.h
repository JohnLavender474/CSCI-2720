#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

#include "Modulo.h"
#include "LinkedList.h"
#include "Predicate.h"

template<typename K, typename V>
class Entry;

template<typename K, typename V>
class HashMap
{
public:
	HashMap();
	
	~HashMap();
	
	void put(K key, V value);
	
	bool get(K key, V &val_ref);
	
	bool remove(K key);
	
	size_t get_size();
	
	void print();

protected:
	size_t hash_func(K key);
	
	void rehash();
	
	size_t prime_size();
	
	float get_load_factor();
	
	float MAX_LOAD_FACTOR = 0.70f;

private:
	size_t prime_bit;
	size_t num_entries;
	size_t capacity;
	LinkedList<Entry<K, V>> **buckets;
};


template<typename K, typename V>
class Entry
{
	static_assert(std::is_base_of<Modulo<K>, K>::value, "Key must derive from Modulo");
public:
	Entry() = delete;
	
	Entry(K key, V value);
	
	void print();
	
	bool operator==(Entry<K, V> const &other) const;
	
	friend std::ostream &operator<<(std::ostream &stream, Entry<K, V> const &entry)
	{
		return stream << "key: " << entry.key << ", value: " << entry.value;
	}
	
	K key;
	V value;
	
	void set_key(K _key);
	
	K &get_key();
	
	void set_value(V _value);
	
	V &get_value();
};

#include "../src/HashMap.tpp"

#endif




