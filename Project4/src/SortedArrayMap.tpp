#include "../hdr/SortedArrayMap.h"

#include <iostream>
#include <sstream>

template<typename K, typename V>
SortedArrayMap<K, V>::SortedArrayMap(const SortedArrayMap<K, V> &sorted_array_map)
{
	entries.arr_cpy(sorted_array_map.entries);
}

template<typename K, typename V>
SortedArrayMap<K, V>::SortedArrayMap(SortedArrayMap<K, V> &sorted_array_map)
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
SortedArrayMap<K, V> &SortedArrayMap<K, V>::operator=(SortedArrayMap<K, V> &sorted_array_map)
{
	entries = sorted_array_map.entries;
	return *this;
}

template<typename K, typename V>
int SortedArrayMap<K, V>::get_size() const
{
	return entries.get_size();
}

template<typename K, typename V>
void SortedArrayMap<K, V>::clear()
{
	entries.clear();
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::contains_key(K k) const
{
	int dummy;
	return contains_key(k, dummy);
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::contains_key(K k, int &index) const
{
	return sorted_key_array().contains(k, index);
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::get(K k, V &v) const
{
	int index = 0;
	if (binary_key_search(k, index))
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
int SortedArrayMap<K, V>::index_of(K k) const
{
	return sorted_key_array().index_of(k);
}

template<typename K, typename V>
Pair<K, V> SortedArrayMap<K, V>::get_pair(int i) const
{
	return entries.get(i);
}

template<typename K, typename V>
V &SortedArrayMap<K, V>::get_val_ref(int i) const
{
	entries.throw_err_if_not_in_size_range("get_val_ref_from_index", i);
	return entries.array[i].v;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::put(K k, V v)
{
	int index;
	if (!sorted_key_array().contains(k, index))
	{
		entries.add(Pair<K, V>(k, v));
		return true;
	}
	else
	{
		get_val_ref(index) = v;
		return false;
	}
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::remove(K k)
{
	return false;
}

template<typename K, typename V>
void SortedArrayMap<K, V>::remove_index(int i)
{
	entries.remove_index(i);
}

template<typename K, typename V>
void SortedArrayMap<K, V>::remove_if(std::function<bool(const Pair<K, V> &)> predicate)
{
	entries.remove_if(predicate);
}

template<typename K, typename V>
SortedArray<Pair<K, V>> SortedArrayMap<K, V>::sorted_entry_array() const
{
	return entries;
}

template<typename K, typename V>
SortedArray<K> SortedArrayMap<K, V>::sorted_key_array() const
{
	SortedArray<K> sorted_keys;
	for (int i = 0; i < entries.get_size(); i++)
	{
		sorted_keys.array[i] = entries.get(i).k;
		++sorted_keys.size;
	}
	return sorted_keys;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::binary_key_search(K k, int &index) const
{
	V dummy_v;
	return binary_key_search(k, index, dummy_v);
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::binary_key_search(K k, int &index, V &v) const
{
	return binary_key_search(k, 0, get_size(), index, v);
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::binary_key_search(K k, int low, int high, int &index, V &v) const
{
	std::cout << "made it to binary_key_search" << std::endl;
	if (get_size() <= 0)
	{
		index = -1;
		return false;
	}
	if (high <= low)
	{
		if (low >= get_size())
		{
			index = low;
		}
		else
		{
			index = (k > entries.array[index].k) ? (low + 1) : low;
		}
		std::cout << "made it to comparison" << std::endl;
		return entries.array[index].k == k;
	}
	int mid = floor((low + high) / 2);
	if (k > entries.get(mid).k)
	{
		return binary_key_search(k, mid + 1, high, index, v);
	}
	else if (k < entries.get(mid).k)
	{
		return binary_key_search(k, low, mid - 1, index, v);
	}
	else
	{
		index = mid;
		return true;
	}
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator>(const SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries > sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator>(SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries > sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator>=(const SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries >= sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator>=(SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries >= sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator<(const SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries < sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator<(SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries < sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator<=(const SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries <= sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator<=(SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries <= sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator==(const SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries == sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator==(SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries == sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator!=(const SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries != sorted_array_map.entries;
}

template<typename K, typename V>
bool SortedArrayMap<K, V>::operator!=(SortedArrayMap<K, V> &sorted_array_map) const
{
	return entries != sorted_array_map.entries;
}

template<typename K, typename V>
void SortedArrayMap<K, V>::for_each(std::function<void(Pair<K, V> &)> apply)
{
	entries.for_each(apply);
}

















