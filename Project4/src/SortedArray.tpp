#include "../hdr/SortedArray.h"

#include <cmath>
#include <iostream>

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
SortedArray<T>::~SortedArray()
{
	delete []array;
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
	if (i < 0 || i >= size)
	{
		throw std::invalid_argument("get: i must be between 0 and size - 1");
	}
	return array[i];
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
	if (binary_search(t, 0, size, index))
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
	int index;
	if (binary_search(t, 0, size, index))
	{
		int left_index = index;
		int right_index = index;
		while (left_index > 0)
		{
			if (array[left_index - 1] == t)
			{
				left_index--;
			}
			else
			{
				break;
			}
		}
		while (right_index != size)
		{
			if (array[right_index + 1] == t)
			{
				right_index++;
			}
			else
			{
				break;
			}
		}
		pair.k = left_index;
		pair.v = right_index;
	}
	return pair;
}

template<typename T>
void SortedArray<T>::add(T t)
{
	if (size == capacity)
	{
		resize();
	}
	int insertion_pos;
	binary_search(t, insertion_pos);
	shift_forward(insertion_pos);
	array[insertion_pos] = t;
	size++;
}

template<typename T>
bool SortedArray<T>::add_if_not_present(T t)
{
	if (size == capacity)
	{
		resize();
	}
	int insertion_pos;
	if (!binary_search(t, insertion_pos))
	{
		shift_forward(insertion_pos);
		array[insertion_pos] = t;
		size++;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void SortedArray<T>::remove_if(bool (*predicate)(T))
{
	for (auto it = begin(); it != end(); ++it)
	{
		T t = *it;
		if (predicate(t))
		{
			remove(t);
		}
	}
}

template<typename T>
bool SortedArray<T>::remove_first(T t)
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
		shift_back(removal_pos);
		size--;
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
bool SortedArray<T>::remove_all(T t)
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
		int temp_removal_pos = removal_pos;
		int removal_count = 0;
		while (temp_removal_pos != size)
		{
			if (array[temp_removal_pos] == t)
			{
				temp_removal_pos++;
				removal_count++;
			}
			else
			{
				break;
			}
		}
		for (int i = 0; i < removal_count; i++)
		{
			shift_back(removal_pos);
			size--;
		}
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
T SortedArray<T>::remove(int i)
{
	if (i < 0 || i >= size)
	{
		throw std::invalid_argument("remove: i must be between 0 and size - 1");
	}
	T t = array[i];
	shift_back(i);
	size--;
	return t;
}

template<typename T>
bool SortedArray<T>::binary_search(T t, int &index)
{
	return binary_search(t, 0, size, index);
}

template<typename T>
bool SortedArray<T>::binary_search(T t, int low, int high, int &index)
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
Iterator<T> SortedArray<T>::begin()
{
	return Iterator<T>(&array[0]);
}

template<typename T>
Iterator<T> SortedArray<T>::end()
{
	return Iterator<T>(&array[size]);
}

template<typename T>
void SortedArray<T>::resize()
{
	int new_capacity = capacity * DYN_ARRAY_MULTI;
	T *new_array = new T[new_capacity];
	for (int i = 0; i < size; i++)
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
	array = new T[sorted_array.get_capacity()];
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






