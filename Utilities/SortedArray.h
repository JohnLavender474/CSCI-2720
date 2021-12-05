#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "Comparable.h"
#include "Pair.h"
#include "Iterator.h"

#include <iostream>
#include <functional>
#include <vector>
#include <cstddef>

template<typename T>
class SortedArray
		: public Comparable<SortedArray<T>>
{
	
	template<typename K, typename V>
	friend class SortedArrayMap;

public:
	
	SortedArray();
	
	SortedArray(const SortedArray<T> &sorted_array);
	
	SortedArray(SortedArray<T> &sorted_array);
	
	~SortedArray();
	
	SortedArray<T> &operator=(const SortedArray<T> &sorted_array);
	
	SortedArray<T> &operator=(SortedArray<T> &sorted_array);
	
	int get_size() const;
	
	int get_capacity() const;
	
	void clear();
	
	T get(int i) const;
	
	int index_of(T t) const;
	
	bool contains(T t) const;
	
	bool contains(T t, int &index) const;
	
	Pair<int, int> range_of_occurrences(T t) const;
	
	void add(T t);
	
	bool add_if_not_present(T t);
	
	void remove_if(std::function<bool(const T&)> predicate);
	
	void remove_index(int i);
	
	bool remove(T t);
	
	void remove_all(T t);
	
	Iterator<T> erase(Iterator<T> it);
	
	bool binary_search(T t, int &index) const;
	
	bool binary_search(T t, int low, int high, int &index) const;
	
	Iterator<T> begin() const;
	
	Iterator<T> end() const;
	
	Iterator<T> iter_at(int i) const;
	
	void for_each(std::function<void(T&)> f);
	
	void for_each_const(std::function<void(const T&)> f) const;
	
	bool operator>(const SortedArray<T> &other) const override;
	
	bool operator>(SortedArray<T> &other) const override;
	
	bool operator>=(const SortedArray<T> &other) const override;
	
	bool operator>=(SortedArray<T> &other) const override;
	
	bool operator<(const SortedArray<T> &other) const override;
	
	bool operator<(SortedArray<T> &other) const override;
	
	bool operator<=(const SortedArray<T> &other) const override;
	
	bool operator<=(SortedArray<T> &other) const override;
	
	bool operator==(const SortedArray<T> &other) const override;
	
	bool operator==(SortedArray<T> &other) const override;
	
	bool operator!=(const SortedArray<T> &other) const override;
	
	bool operator!=(SortedArray<T> &other) const override;
	
	friend std::ostream &operator<<(std::ostream &stream, const SortedArray<T> &sorted_array)
	{
		stream << "{";
		auto it = sorted_array.begin();
		while (true)
		{
			stream << *it;
			if (++it == sorted_array.end())
			{
				break;
			}
			else
			{
				stream << ", ";
			}
		}
		stream << "}";
		return stream;
	}
	
private:
	
	void resize();
	
	void arr_cpy(const SortedArray<T> &sorted_array);
	
	void arr_cpy(SortedArray<T> &sorted_array);
	
	void shift_forward(int index);
	
	void shift_back(int index);
	
	void throw_err_if_not_in_size_range(std::string func_name, int i) const;
	
	void quick_sort();
	
	static int partition(T *arr, int begin, int end);
	
	static void quick_sort(T *arr, int begin, int end);
	
	static void swap(T &i, T &j);
	
	T *array;
	unsigned int size;
	unsigned int capacity;
	const static int INIT_ARRAY_CAP = 16;
	const static int DYN_ARRAY_MULTI = 2;
};

#include "SortedArray.tpp"

#endif
