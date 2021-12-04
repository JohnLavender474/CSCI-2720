#include "../hdr/SortedArray.h"

#include <cmath>
#include <iostream>
#include <queue>
#include <sstream>
#include <functional>

template<typename T>
SortedArray<T>::SortedArray() :
		size(0),
		capacity(INIT_ARRAY_CAP)
{
	array = new T[capacity];
}

template<typename T>
SortedArray<T>::SortedArray(const SortedArray<T> &sorted_array)
{
	arr_cpy(sorted_array);
}

template<typename T>
SortedArray<T>::SortedArray(SortedArray<T> &sorted_array)
{
	arr_cpy(sorted_array);
}

template<typename T>
SortedArray<T>::~SortedArray()
{
	delete[]array;
}

template<typename T>
SortedArray<T> &SortedArray<T>::operator=(const SortedArray<T> &sorted_array)
{
	if (this == &sorted_array)
	{
		goto done;
	}
	if (sorted_array.get_size() == 0)
	{
		clear();
		goto done;
	}
	arr_cpy(sorted_array);
	done:
	return *this;
}

template<typename T>
SortedArray<T> &SortedArray<T>::operator=(SortedArray<T> &sorted_array)
{
	if (this == &sorted_array)
	{
		goto done;
	}
	if (sorted_array.get_size() == 0)
	{
		clear();
		goto done;
	}
	arr_cpy(sorted_array);
	done:
	return *this;
}

template<typename T>
int SortedArray<T>::get_size() const
{
	return size;
}

template<typename T>
int SortedArray<T>::get_capacity() const
{
	return capacity;
}

template<typename T>
void SortedArray<T>::clear()
{
	size = 0;
	array = new T[INIT_ARRAY_CAP];
	capacity = INIT_ARRAY_CAP;
}

template<typename T>
T SortedArray<T>::get(int i) const
{
	throw_err_if_not_in_size_range("get", i);
	return array[i];
}

template<typename T>
int SortedArray<T>::index_of(T t) const
{
	int index;
	if (binary_search(t, index))
	{
		return index;
	}
	else
	{
		return -1;
	}
}

template<typename T>
bool SortedArray<T>::contains(T t) const
{
	int dummy;
	return binary_search(t, 0, size, dummy);
}

template<typename T>
bool SortedArray<T>::contains(T t, int &index) const
{
	if (binary_search(t, index))
	{
		return true;
	}
	else
	{
		index = -1;
		return false;
	}
}

template<typename T>
Pair<int, int> SortedArray<T>::range_of_occurrences(T t) const
{
	Pair<int, int> pair(-1, -1);
	int start_index;
	if (binary_search(t, start_index))
	{
		while (start_index > 0)
		{
			if (array[start_index - 1] == t)
			{
				--start_index;
			}
			else
			{
				break;
			}
		}
		int end_index = start_index;
		while (end_index < size - 1)
		{
			if (array[end_index + 1] == t)
			{
				++end_index;
			}
			else
			{
				break;
			}
		}
		pair.k = start_index;
		pair.v = end_index;
	}
	return pair;
}

template<typename T>
void SortedArray<T>::add(T t)
{
	if (size == 0)
	{
		array[0] = t;
		++size;
		return;
	}
	if (size == capacity)
	{
		resize();
	}
	int insertion_pos;
	binary_search(t, insertion_pos);
	shift_forward(insertion_pos);
	array[insertion_pos] = t;
	++size;
}

template<typename T>
bool SortedArray<T>::add_if_not_present(T t)
{
	if (size == 0)
	{
		array[0] = t;
		++size;
		return true;
	}
	if (size == capacity)
	{
		resize();
	}
	int insertion_pos;
	if (!binary_search(t, insertion_pos))
	{
		shift_forward(insertion_pos);
		array[insertion_pos] = t;
		++size;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void SortedArray<T>::remove_if(std::function<bool(const T&)> predicate)
{
	for (auto it = begin();
	     it != end();)
	{
		if (predicate(*it))
		{
			it = erase(it);
		}
		else
		{
			++it;
		}
	}
}

template<typename T>
void SortedArray<T>::remove_index(int i)
{
	if (i >= size || i < 0)
	{
		throw std::invalid_argument("remove_index: i must be between 0 and size - 1");
	}
	shift_back(i);
	size--;
}

template<typename T>
bool SortedArray<T>::remove(T t)
{
	int removal_pos;
	if (binary_search(t, 0, size, removal_pos))
	{
		while (removal_pos > 0)
		{
			if (array[removal_pos - 1] == t)
			{
				removal_pos--;
			}
			else
			{
				break;
			}
		}
		remove_index(removal_pos);
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void SortedArray<T>::remove_all(T t)
{
	int index;
	if (binary_search(t, index))
	{
		while (index > 0)
		{
			if (array[index - 1] == t)
			{
				--index;
			}
			else
			{
				break;
			}
		}
		auto it = iter_at(index);
		while (*it == t)
		{
			it = erase(it);
		}
	}
}

template<typename T>
Iterator<T> SortedArray<T>::erase(Iterator<T> it)
{
	remove(*it);
	return it;
}

template<typename T>
bool SortedArray<T>::binary_search(T t, int &index) const
{
	return binary_search(t, 0, size, index);
}

template<typename T>
bool SortedArray<T>::binary_search(T t, int low, int high, int &index) const
{
	if (size <= 0)
	{
		index = -1;
		return false;
	}
	if (high <= low)
	{
		if (low == size)
		{
			index = low;
		}
		else
		{
			index = (t > array[low]) ? (low + 1) : low;
		}
		return array[index] == t;
	}
	int mid = floor((low + high) / 2);
	if (t > array[mid])
	{
		return binary_search(t, mid + 1, high, index);
	}
	else if (t < array[mid])
	{
		return binary_search(t, low, mid - 1, index);
	}
	else
	{
		index = mid;
		return true;
	}
}

template<typename T>
Iterator<T> SortedArray<T>::begin() const
{
	return Iterator<T>(&array[0]);
}

template<typename T>
Iterator<T> SortedArray<T>::end() const
{
	return Iterator<T>(&array[size]);
}

template<typename T>
Iterator<T> SortedArray<T>::iter_at(int i) const
{
	throw_err_if_not_in_size_range("iter_at", i);
	return Iterator<T>(&array[i]);
}

template<typename T>
void SortedArray<T>::for_each(std::function<void(T&)> f)
{
	for (auto it = begin();
	it != end();
	++it)
	{
		f(*it);
	}
	quick_sort();
}

template<typename T>
void SortedArray<T>::resize()
{
	int new_capacity = capacity * DYN_ARRAY_MULTI;
	T *new_array = new T[new_capacity];
	for (int i = 0;
	     i < size;
	     i++)
	{
		new_array[i] = array[i];
	}
	delete[]array;
	array = new_array;
	capacity = new_capacity;
}

template<typename T>
void SortedArray<T>::arr_cpy(const SortedArray<T> &sorted_array)
{
	int cap = sorted_array.get_capacity();
	array = new T[cap];
	for (int i = 0;
	     i < sorted_array.get_size();
	     i++)
	{
		array[i] = sorted_array.get(i);
	}
	size = sorted_array.get_size();
	capacity = sorted_array.get_capacity();
}

template<typename T>
void SortedArray<T>::arr_cpy(SortedArray<T> &sorted_array)
{
	int cap = sorted_array.get_capacity();
	array = new T[cap];
	for (int i = 0;
	     i < sorted_array.get_size();
	     i++)
	{
		array[i] = sorted_array.get(i);
	}
	size = sorted_array.get_size();
	capacity = sorted_array.get_capacity();
}

template<typename T>
void SortedArray<T>::shift_forward(int index)
{
	for (int i = size;
	     i > index;
	     i--)
	{
		array[i] = array[i - 1];
	}
}

template<typename T>
void SortedArray<T>::shift_back(int index)
{
	for (int i = index;
	     i < size;
	     i++)
	{
		array[i] = array[i + 1];
	}
}

template<typename T>
void SortedArray<T>::throw_err_if_not_in_size_range(std::string func_name, int i) const
{
	if (i < 0)
	{
		goto error;
	}
	if (size > 0 && i >= size)
	{
		goto error;
	}
	else if (size == 0 && i != 0)
	{
		goto error;
	}
	else
	{
		return;
	}
	error:
	throw std::invalid_argument(func_name +
	                            ": i must be between 0 and size - 1" +
	                            ", i is " + std::to_string(i) +
	                            ", size is " + std::to_string(size));
}

template<typename T>
bool SortedArray<T>::operator>(const SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator>(SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator>=(const SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator>=(SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator<(const SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator<(SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator<=(const SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator<=(SortedArray<T> &other) const
{
	return false;
}

template<typename T>
bool SortedArray<T>::operator==(const SortedArray<T> &other) const
{
	if (size != other.size)
	{
		return false;
	}
	for (int i = 0;
	     i < size;
	     i++)
	{
		if (get(i) != other.get(i))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool SortedArray<T>::operator==(SortedArray<T> &other) const
{
	if (size != other.size)
	{
		return false;
	}
	for (int i = 0;
	     i < size;
	     i++)
	{
		if (get(i) != other.get(i))
		{
			return false;
		}
	}
	return true;
}

template<typename T>
bool SortedArray<T>::operator!=(const SortedArray<T> &other) const
{
	if (size != other.size)
	{
		return true;
	}
	for (int i = 0;
	     i < size;
	     i++)
	{
		if (get(i) != other.get(i))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool SortedArray<T>::operator!=(SortedArray<T> &other) const
{
	if (size != other.size)
	{
		return true;
	}
	for (int i = 0;
	     i < size;
	     i++)
	{
		if (get(i) != other.get(i))
		{
			return true;
		}
	}
	return false;
}

template<typename T>
void SortedArray<T>::quick_sort()
{
	quick_sort(array, 0, size - 1);
}

template<typename T>
void SortedArray<T>::quick_sort(T *arr, int begin, int end)
{
	if (begin < end)
	{
		int p = partition(arr, begin, end);
		quick_sort(arr, begin, p - 1);
		quick_sort(arr, p + 1, end);
	}
}

template<typename T>
int SortedArray<T>::partition(T *arr, int begin, int end)
{
	int pivot = end;
	int j = begin;
	for (int i = begin; i < end; ++i)
	{
		if (arr[i] < arr[pivot])
		{
			swap(arr[i], arr[j]);
			++j;
		}
	}
	swap(arr[j], arr[pivot]);
	return j;
}

template<typename T>
void SortedArray<T>::swap(T &i, T &j)
{
	T temp = i;
	i = j;
	j = temp;
}










