#ifndef SORTEDARRAYMAP_H
#define SORTEDARRAYMAP_H

#include <iostream>

#include "Pair.h"
#include "../Project4/Iterator.h"
#include "SortedArray.h"

template<typename K, typename V>
class SortedArrayMap
		: public Comparable<SortedArrayMap<K, V>>
{

public:
	SortedArrayMap() = default;
	
	SortedArrayMap(SortedArrayMap<K, V> &sorted_array_map);
	
	SortedArrayMap(const SortedArrayMap<K, V> &sorted_array_map);
	
	SortedArrayMap(SortedArray<K> &keys, V default_val);
	
	SortedArrayMap(const SortedArray<K> &keys, V default_val);
	
	~SortedArrayMap() = default;
	
	SortedArrayMap<K, V> &operator=(const SortedArrayMap<K, V> &sorted_array_map);
	
	SortedArrayMap<K, V> &operator=(SortedArrayMap<K, V> &sorted_array_map);
	
	int get_size() const;
	
	void clear();
	
	bool contains_key(K k) const;
	
	bool contains_key(K k, int &index) const;
	
	bool get(K k, V &v) const;
	
	int index_of(K k) const;
	
	Pair<K, V> get_pair(int i) const;
	
	V &get_val_ref(int i) const;
	
	bool put(K k, V v);
	
	bool remove(K k);
	
	void remove_index(int i);
	
	void remove_if(std::function<bool(const Pair<K, V>&)> predicate);
	
	SortedArray<Pair<K, V>> sorted_entry_array() const;
	
	SortedArray<K> sorted_key_array() const;
	
	void for_each(std::function<void(Pair<K, V>&)> f);
	
	void for_each_const(std::function<void(const Pair<K, V>&)> f) const;
	
	bool operator>(const SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator>(SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator>=(const SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator>=(SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator<(const SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator<(SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator<=(const SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator<=(SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator==(const SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator==(SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator!=(const SortedArrayMap<K, V> &sorted_array_map) const override;
	
	bool operator!=(SortedArrayMap<K, V> &sorted_array_map) const override;
	
	friend std::ostream &operator<<(std::ostream &stream, const SortedArrayMap<K, V> &sorted_array_map)
	{
		stream << "{";
		for (int i = 0;
		     i < sorted_array_map.get_size();
		     i++)
		{
			Pair<K, V> pair = sorted_array_map.get_pair(i);
			stream << pair;
			if (i != sorted_array_map.get_size() - 1)
			{
				stream << ", ";
			}
		}
		stream << "}";
		return stream;
	}

private:
	
	SortedArray<Pair<K, V>> entries;
	
	bool binary_key_search(K k, int &index) const;
	
	bool binary_key_search(K k, int &index, V &v) const;
	
	bool binary_key_search(K k, int low, int high, int &index, V &v) const;
	
};

#include "SortedArrayMap.tpp"

#endif
