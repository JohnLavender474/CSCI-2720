#pragma once

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
	
	bool operator==(Entry<K, V> const &other) const;
	
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
class HashMap
{
public:
	HashMap();
	
	~HashMap() = default;
	
	void put(K key, V value);
	
	bool get(K key, V &val_ref);
	
	bool remove(K key);
	
	size_t get_size();
	
	const float MAX_LOAD_FACTOR = 0.75f;

protected:
	size_t hash_func(K key);
	
	void rehash();

private:
	float load_factor;
	size_t num_entries;
	size_t num_buckets;
	std::vector<LinkedList<Entry<K, V> *> *> buckets;
};

template<typename K, typename V>
HashMap<K, V>::HashMap() :
		load_factor(0.0f),
		num_entries(0),
		num_buckets(10),
		buckets(11, nullptr)
{
}

template<typename K, typename V>
void HashMap<K, V>::put(K key, V value)
{
	Entry<K, V> *entry = new Entry<K, V>(key, value);
	size_t hash = hash_func(key);
	if (buckets.at(hash) == nullptr)
	{
		buckets.at(hash) = new LinkedList<Entry<K, V> *>();
	}
	if (buckets.at(hash)->contains(entry))
	{
		int i = buckets.at(hash)->get_index_of(entry);
		buckets.at(hash)->get(i)->value = value;
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
	LinkedList<Entry<K, V> *> *bucket = buckets.at(hash);
	for (size_t i = 0;
	     i < bucket->get_size();
	     i++)
	{
		Entry<K, V> *entry = bucket->get(i);
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
	LinkedList<Entry<K, V> *> *bucket = buckets.at(hash);
	for (size_t i = 0;
	     i < bucket->get_size();
	     i++)
	{
		Entry<K, V> *entry = bucket->get(i);
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
size_t HashMap<K, V>::hash_func(K key)
{
	return key % num_buckets;
}

template<typename K, typename V>
void HashMap<K, V>::rehash()
{
	std::queue<Entry<K, V> *> q;
	for (size_t i = 0;
	     i < buckets.size();
	     i++)
	{
		LinkedList<Entry<K, V> *> *bucket = buckets.at(i);
		while (!bucket->empty())
		{
			q.push(bucket->pop());
		}
	}
	num_buckets = 6 * ++prime_bit + 1;
	while (!q.empty())
	{
		Entry<K, V> * entry = q.front();
		put(entry->key, entry->value);
		q.pop();
	}
}

template<typename K, typename V>
size_t HashMap<K, V>::get_size()
{
	return num_entries;
}






