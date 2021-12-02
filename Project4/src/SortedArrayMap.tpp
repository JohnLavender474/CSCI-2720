#include "../hdr/SortedArrayMap.h"

template<typename K, typename V>
SortedArrayMap<K, V>::~SortedArrayMap()
{
	delete entries;
}

template<typename K, typename V>
SortedArrayMap<K, V>::SortedArrayMap(const SortedArrayMap<K, V> &sorted_array_map)
{
	entries.arr_cpy(sorted_array_map.entries);
}

template<typename K, typename V>
SortedArrayMap<K, V> &SortedArrayMap<K, V>::operator=(const SortedArrayMap<K, V> &sorted_array_map)
{
	entries = sorted_array_map.entries;
	return *this;
}

template<typename K, typename V>
int SortedArrayMap<K, V>::get_size()
{
	return entries.get_size();
}

template<typename K, typename V>
void SortedArrayMap<K, V>::clear()
{
	entries.clear();
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::contains_key(K k)
{
	int dummy;
	return contains_key(k, dummy);
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::contains_key(K k, int &index) const
{
	if (sorted_key_array().contains(k, index))
	{
		return true;
	}
	else
	{
		index = -1;
		return false;
	}
}

template<typename K, typename V>
V *SortedArrayMap<K, V>::get(K k)
{
	V *v;
	int index;
	if (binary_key_search(k, 0, entries.get_size(), index))
	{
		v = &entries.get(index).v;
		return v;
	}
	else
	{
		return nullptr;
	}
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::get(K k, V &v)
{
	int index;
	if (binary_key_search(k, 0, entries.get_size(), index))
	{
		Pair<K, V> p = entries.get(index);
		v = p.v;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename K, typename V>
Pair<K, V> SortedArrayMap<K, V>::get_pair_cpy(int i)
{
	return entries.get(i);
}

template<typename K, typename V>
V &SortedArrayMap<K, V>::get_val_ref(int i)
{
	return entries[i].v;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::put(Pair<K, V> pair)
{
	int index;
	if (contains_key(pair.k, index))
	{
		entries.get(index).v = pair.v;
	}
	else
	{
		entries.add_if_not_present(pair);
	}
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::remove(K k)
{
	return false;
}

template<typename K, typename V>
void SortedArrayMap<K, V>::remove_if(bool (*predicate)(Pair<K, V>))
{
	entries.remove_if(predicate);
}

template<typename K, typename V>
SortedArray<Pair<K, V>> SortedArrayMap<K, V>::sorted_entry_array()
{
	return entries;
}

template<typename K, typename V>
SortedArray<K> SortedArrayMap<K, V>::sorted_key_array()
{
	SortedArray<K> sorted_keys;
	for (auto it = entries.begin(); it != entries.end(); ++it)
	{
		sorted_keys.add(it->k);
	}
	return sorted_keys;
}














