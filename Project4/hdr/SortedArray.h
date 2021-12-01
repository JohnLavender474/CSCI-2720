#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H

#include "Comparable.h"
#include "Pair.h"

#include <functional>
#include <vector>
#include <cstddef>

template<typename T>
class SortedArray
{
	static_assert(std::is_base_of<Comparable<T>, T>::value, "SortedArray: T must derive Comparable<T>");

public:
	
	SortedArray();
	
	SortedArray(const SortedArray<T> &sorted_array);
	
	~SortedArray();
	
	SortedArray<T> &operator=(const SortedArray<T> &sorted_array);
	
	int get_size();
	
	int get_capacity();
	
	void clear();
	
	T get(int i);
	
	bool contains(T t);
	
	bool contains(T t, int &index);
	
	Pair<int, int> range_of_occurrences(T t);
	
	void add(T t);
	
	T remove(int i);
	
	void remove_if(bool (*predicate)(T));
	
	bool remove_first(T t);
	
	bool remove_all(T t);
	
	bool binary_search(T t, int low, int high, int &index);

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
