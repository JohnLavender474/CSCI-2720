#pragma once

#include <iostream>
#include <vector>
#include <queue>

#include "Modulo.h"
#include "LinkedList.h"
#include "Predicate.h"

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
};

template<typename K, typename V>
Entry<K, V>::Entry(K key, V value) :
		key(key), value(value)
{
}

template<typename K, typename V>
bool Entry<K, V>::operator==(Entry<K, V> const &other) const
{
	return key == other.key && value == other.value;
}

template<typename K, typename V>
void Entry<K, V>::print()
{
	std::cout << "key: " << key << " value: " << value << std::endl;
}

template<typename K, typename V>
class HashMap
{
public:
	HashMap();
	
	~HashMap();
	
	void put(K key, V value);
	
	bool get(K key, V &val_ref);
	
	bool remove(K key);
	
	const size_t get_size();
	
	void print();

protected:
	const size_t hash_func(K key);
	
	void rehash();
	
	const size_t prime_size();
	
	const float get_load_factor();
	
	const float MAX_LOAD_FACTOR = 0.75f;

private:
	size_t prime_bit;
	size_t num_entries;
	std::vector<LinkedList<Entry<K, V>> *> buckets;
};

template<typename K, typename V>
HashMap<K, V>::HashMap() :
		prime_bit(2),
		num_entries(0),
		buckets(11, nullptr)
{
}

template<typename K, typename V>
HashMap<K, V>::~HashMap()
{
	for (size_t i = 0; i < buckets.capacity(); i++)
	{
		delete buckets.at(i);
	}
}

template<typename K, typename V>
void HashMap<K, V>::put(K key, V value)
{
	if (get_load_factor() > MAX_LOAD_FACTOR)
	{
		rehash();
	}
	Entry<K, V> entry(key, value);
	size_t hash = hash_func(key);
	if (buckets.at(hash) == nullptr)
	{
		buckets.at(hash) = new LinkedList<Entry<K, V>>();
	}
	if (buckets.at(hash)
			->contains(entry))
	{
		int i = buckets.at(hash)
				->get_index_of(entry);
		buckets.at(hash)
				->get(i)
				.value = value;
		return;
	}
	buckets.at(hash)
			->add(entry);
	num_entries++;
}

template<typename K, typename V>
bool HashMap<K, V>::get(K key, V &val_ref)
{
	size_t hash = hash_func(key);
	LinkedList<Entry<K, V>> *bucket = buckets.at(hash);
	for (size_t i = 0;
	     i < bucket->get_size();
	     i++)
	{
		Entry<K, V> entry = bucket->get(i);
		if (key == entry->key)
		{
			val_ref = entry->value;
			return true;
		}
	}
	return false;
}


template<typename K, typename V>
bool HashMap<K, V>::remove(K key)
{
	size_t hash = hash_func(key);
	LinkedList<Entry<K, V>> *bucket = buckets.at(hash);
	if (bucket == nullptr)
	{
		return false;
	}
	for (size_t i = 0;
	     i < bucket->get_size();
	     i++)
	{
		Entry<K, V> entry = bucket->get(i);
		if (key == entry->key)
		{
			bucket->remove(i);
			num_entries--;
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
const size_t HashMap<K, V>::hash_func(K key)
{
	return key % buckets.capacity();
}

template<typename K, typename V>
void HashMap<K, V>::rehash()
{
	std::queue<Entry<K, V>> q;
	for (size_t i = 0;
	     i < buckets.max_size();
	     i++)
	{
		LinkedList<Entry<K, V>> *bucket = buckets.at(i);
		if (bucket != nullptr)
		{
			while (!bucket->empty())
			{
				q.push(bucket->pop());
			}
		}
	}
	buckets.resize(prime_size());
	for (size_t i = 0; i < buckets.capacity(); i++)
	{
		buckets.at(i) = nullptr;
	}
	while (!q.empty())
	{
		Entry<K, V> entry = q.front();
		put(entry.key, entry.value);
		q.pop();
	}
}

template<typename K, typename V>
const size_t HashMap<K, V>::get_size()
{
	return num_entries;
}

template<typename K, typename V>
void HashMap<K, V>::print()
{
	for (size_t i = 0; i < buckets.capacity(); i++)
	{
		std::cout << "Bucket " << i + 1 << std::endl;
		if (buckets.at(i) != nullptr)
		{
			buckets.at(i)->print();
		}
	}
	std::cout << "\nnum_entries: " << num_entries << std::endl;
}

template<typename K, typename V>
const size_t HashMap<K, V>::prime_size()
{
	return 6 * ++prime_bit + 1;
}

template<typename K, typename V>
const float HashMap<K, V>::get_load_factor()
{
	return num_entries / buckets.capacity();
}










