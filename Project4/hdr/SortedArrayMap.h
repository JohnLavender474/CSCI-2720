#ifndef SORTEDARRAYMAP_H
#define SORTEDARRAYMAP_H

#include "Pair.h"
#include "Iterator.h"
#include "SortedArray.h"

template<typename K, typename V>
class SortedArrayMap
{

public:
	SortedArrayMap() = default;
	
	SortedArrayMap(const SortedArrayMap<K, V> &sorted_array_map);
	
	~SortedArrayMap();
	
	SortedArrayMap<K, V> &operator=(const SortedArrayMap<K, V> &sorted_array_map);
	
	int get_size();
	
	void clear();
	
	bool contains_key(K k);
	
	bool contains_key(K k, int &index) const;
	
	V *get(K k);
	
	bool get(K k, V &v);
	
	Pair<K, V> get_pair_cpy(int i);
	
	V &get_val_ref(int i);
	
	bool put(Pair<K, V> pair);
	
	bool remove(K k);
	
	void remove_if(bool (*predicate)(Pair<K, V>));
	
	SortedArray<Pair<K, V>> sorted_entry_array();
	
	SortedArray<K> sorted_key_array();

private:
	
	SortedArray<Pair<K, V>> entries;
};

#include "../src/SortedArrayMap.tpp"

#endif
