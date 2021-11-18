#include "../hdr/HashMap.h"

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
void Entry<K, V>::set_value(V _value)
{
	this->value = _value;
}

template<typename K, typename V>
V &Entry<K, V>::get_value()
{
	return value;
}

template<typename K, typename V>
void Entry<K, V>::set_key(K _key)
{
	this->key = _key;
}

template<typename K, typename V>
K &Entry<K, V>::get_key()
{
	return key;
}


template<typename K, typename V>
HashMap<K, V>::HashMap() :
		prime_bit(1),
		num_entries(0),
		buckets(nullptr)
{
	rehash();
}

template<typename K, typename V>
HashMap<K, V>::~HashMap()
{
	delete[] buckets;
}

template<typename K, typename V>
void HashMap<K, V>::put(K key, V value)
{
	float load_factor = get_load_factor();
	if (load_factor > MAX_LOAD_FACTOR)
	{
		rehash();
	}
	Entry<K, V> entry(key, value);
	size_t hash = hash_func(key);
	if (buckets[hash] == nullptr)
	{
		buckets[hash] = new LinkedList<Entry<K, V>>();
	}
	for (size_t i = 0;
	     i < buckets[hash]->get_size();
	     i++)
	{
		if (buckets[hash]->get(i)
				    .key == entry.key)
		{
			buckets[hash]->get(i)
					.set_value(entry.value);
			return;
		}
	}
	buckets[hash]
			->add(entry);
	num_entries++;
}

template<typename K, typename V>
bool HashMap<K, V>::get(K key, V &val_ref)
{
	size_t hash = hash_func(key);
	LinkedList<Entry<K, V>> *bucket = buckets[hash];
	for (size_t i = 0;
	     i < bucket->get_size();
	     i++)
	{
		Entry<K, V> entry = bucket->get(i);
		if (key == entry.key)
		{
			val_ref = entry.value;
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
bool HashMap<K, V>::contains(K key)
{
	size_t hash = hash_func(key);
	LinkedList<Entry<K, V>> *bucket = buckets[hash];
	for (size_t i = 0;
	     i < bucket->get_size();
	     i++)
	{
		Entry<K, V> entry = bucket->get(i);
		if (key == entry.key)
		{
			return true;
		}
	}
	return false;
}

template<typename K, typename V>
bool HashMap<K, V>::remove(K key)
{
	size_t hash = hash_func(key);
	LinkedList<Entry<K, V>> *bucket = buckets[hash];
	if (bucket == nullptr)
	{
		return false;
	}
	for (size_t i = 0;
	     i < bucket->get_size();
	     i++)
	{
		Entry<K, V> entry = bucket->get(i);
		if (key == entry.key)
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
	size_t hash_func_val = key % capacity;
	return hash_func_val;
}

template<typename K, typename V>
void HashMap<K, V>::rehash()
{
	// If buckets has already been initialized, then copy over all of the Entry elements
	// from each bucket into the queue and delete memory for each bucket afterwards.
	std::queue<Entry<K, V>> q;
	if (buckets != nullptr)
	{
		for (size_t i = 0;
		     i < capacity;
		     i++)
		{
			LinkedList<Entry<K, V>> *bucket = buckets[i];
			if (bucket != nullptr)
			{
				while (!bucket->empty())
				{
					q.push(bucket->pop());
				}
			}
		}
		for (size_t i = 0;
		     i < capacity;
		     i++)
		{
			delete buckets[i];
		}
		delete[] buckets;
	}
	// Reset number of elements to 0. Reset capacity to next approximate prime value.
	// Put each Entry element from the queue back into a bucket.
	num_entries = 0;
	capacity = prime_size();
	buckets = new LinkedList<Entry<K, V>> *[capacity]();
	while (!q.empty())
	{
		Entry<K, V> entry = q.front();
		put(entry.key, entry.value);
		q.pop();
	}
}

template<typename K, typename V>
size_t HashMap<K, V>::get_size()
{
	return num_entries;
}

template<typename K, typename V>
void HashMap<K, V>::print()
{
	for (size_t i = 0;
	     i < capacity;
	     i++)
	{
		std::cout << "Bucket " << i + 1 << std::endl;
		if (buckets[i] != nullptr)
		{
			buckets[i]->print();
		}
	}
	std::cout << "\nnum_entries: " << num_entries << std::endl;
	std::cout << "current load factor: " << get_load_factor() << std::endl;
	std::cout << "if load factor is greater than 0.85, next put op will cause rehash" << std::endl;
}

template<typename K, typename V>
size_t HashMap<K, V>::prime_size()
{
	return 6 * ++prime_bit + 1;
}

template<typename K, typename V>
float HashMap<K, V>::get_load_factor()
{
	return (float) num_entries / capacity;
}
