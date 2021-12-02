#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "Comparable.h"
#include "Pair.h"
#include "Iterator.h"

#include <functional>
#include <vector>
#include <cstddef>

template<typename T>
class SortedArray
{
	
	template<typename K, typename V>
	friend class SortedArrayMap;

public:
	
	SortedArray();
	
	SortedArray(const SortedArray<T> &sorted_array);
	
	~SortedArray();
	
	SortedArray<T> &operator=(const SortedArray<T> &sorted_array);
	
	int get_size() const;
	
	int get_capacity() const;
	
	void clear();
	
	T get(int i) const;
	
	bool contains(T t) const;
	
	bool contains(T t, int &index) const;
	
	Pair<int, int> range_of_occurrences(T t) const;
	
	void add(T t);
	
	bool add_if_not_present(T t);
	
	T remove(int i);
	
	void remove_if(bool (*predicate)(T));
	
	bool remove_first(T t);
	
	bool remove_all(T t);
	
	bool binary_search(T t, int &index);
	
	bool binary_search(T t, int low, int high, int &index);
	
	Iterator<T> begin();
	
	Iterator<T> end();

private:
	
	void resize();
	
	void arr_cpy(const SortedArray<T> &sorted_array);
	
	void shift_forward(int index);
	
	void shift_back(int index);

	T *array;
	unsigned int size;
	unsigned int capacity;
	bool allow_duplicates;
	const static int INIT_ARRAY_CAP = 16;
	const static int DYN_ARRAY_MULTI = 2;
};

#include "../src/SortedArray.tpp"

#endif
