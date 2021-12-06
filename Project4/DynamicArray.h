#pragma once

#include <set>
#include <queue>
#include <functional>

#include "Iterator.h"

template<typename T>
class DynamicArray
{

public:
	
	DynamicArray();
	
	DynamicArray(T fill);
	
	DynamicArray(const DynamicArray<T> &dynamic_array);
	
	DynamicArray(DynamicArray<T> &dynamic_array);
	
	~DynamicArray();
	
	DynamicArray<T> &operator=(const DynamicArray<T> &dynamic_array);
	
	DynamicArray<T> &operator=(DynamicArray<T> &dynamic_array);
	
	bool val_at(int index, T &val) const;
	
	bool is_occupied_index(int index) const;
	
	T *ptr_to(int index) const;
	
	T poll_front();
	
	T poll_back();
	
	T peek_front();
	
	T peek_back();
	
	bool put(int index, T t);
	
	void clear();
	
	void fill_arr(T t_fill);
	
	int get_size() const;
	
	int get_capacity() const;
	
	int index_of(T t) const;
	
	bool contains(T t) const;
	
	void remove_if(std::function<bool(const T&)> predicate);
	
	void remove_at(int index);
	
	void remove(T t);
	
	void remove_first(T t);
	
	Iterator<T> begin() const;
	
	Iterator<T> end() const;
	
	Iterator<T> iter_at(int index) const;
	
	void for_each(std::function<void(T&)> function);
	
	void for_each(std::function<void(const T&)> function) const;
	
	std::vector<T> as_vector();
	
	friend std::ostream &operator<<(std::ostream &stream, const DynamicArray<T> &dynamic_array)
	{
		stream << "\n{ " << std::endl;
		for (auto it = dynamic_array.occupied.begin();
		     it != dynamic_array.occupied.end();
		     ++it)
		{
			stream << '\t' << dynamic_array.array[*it] << std::endl;
		}
		stream << "}" << std::endl;
		return stream;
	}

private:
	
	void resize();
	
	void resize_spec(int access_attempt);
	
	void arr_cpy(const DynamicArray<T> &dynamic_array);
	
	void arr_cpy(DynamicArray<T> &dynamic_array);
	
	int get_min_occupied();
	
	int get_max_occupied();
	
	T *array;
	std::set<int> occupied;
	int capacity;
	const static int INIT_CAP = 16;
	const static int INCR_FACTOR = 2;
	
};

template<typename T>
DynamicArray<T>::DynamicArray() :
		capacity(INIT_CAP)
{
	array = new T[capacity];
}

template<typename T>
DynamicArray<T>::DynamicArray(T t_fill) :
		capacity(INIT_CAP)
{
	array = new T[capacity];
	fill_arr(t_fill);
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T> &dynamic_array)
{
	arr_cpy(dynamic_array);
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &dynamic_array)
{
	arr_cpy(dynamic_array);
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
	delete[]array;
}

template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &dynamic_array)
{
	if (this == &dynamic_array)
	{
		goto done;
	}
	if (dynamic_array.get_size() == 0)
	{
		clear();
		goto done;
	}
	arr_cpy(dynamic_array);
	done:
	return *this;
}

template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=(DynamicArray<T> &dynamic_array)
{
	if (this == &dynamic_array)
	{
		goto done;
	}
	if (dynamic_array.get_size() == 0)
	{
		clear();
		goto done;
	}
	arr_cpy(dynamic_array);
	done:
	return *this;
}

template<typename T>
bool DynamicArray<T>::val_at(int index, T &val) const
{
	if (!is_occupied_index(index))
	{
		return false;
	}
	else
	{
		val = array[index];
		return true;
	}
}

template<typename T>
T *DynamicArray<T>::ptr_to(int index) const
{
	if (!is_occupied_index(index))
	{
		return nullptr;
	}
	else
	{
		return &array[index];
	}
}

template<typename T>
bool DynamicArray<T>::is_occupied_index(int index) const
{
	return occupied.find(index) != occupied.end();
}

template<typename T>
bool DynamicArray<T>::put(int index, T t)
{
	if (get_size() == capacity)
	{
		resize();
	}
	if (index >= capacity)
	{
		resize_spec(index);
	}
	array[index] = t;
	if (occupied.find(index) == occupied.end())
	{
		occupied.insert(index);
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T>
void DynamicArray<T>::clear()
{
	occupied.clear();
	capacity = INIT_CAP;
	array = new T[capacity];
}

template<typename T>
void DynamicArray<T>::fill_arr(T t_fill)
{
	for (int i = 0; i < capacity; i++)
	{
		array[i] = t_fill;
		occupied.insert(i);
	}
}

template<typename T>
int DynamicArray<T>::get_size() const
{
	return occupied.size();
}

template<typename T>
int DynamicArray<T>::get_capacity() const
{
	return capacity;
}

template<typename T>
int DynamicArray<T>::index_of(T t) const
{
	for (auto it = occupied.begin();
	     it != occupied.end();
	     ++it)
	{
		if (array[*it] == t)
		{
			return *it;
		}
	}
	return -1;
}

template<typename T>
bool DynamicArray<T>::contains(T t) const
{
	return index_of(t) != -1;
}

template<typename T>
void DynamicArray<T>::remove_if(std::function<bool(const T &)> predicate)
{
	std::queue<int> removal_q;
	for (auto it = occupied.begin();
	     it != occupied.end();
	     ++it)
	{
		int i = *it;
		if (predicate(array[*it]))
		{
			removal_q.push(i);
		}
	}
	while (!removal_q.empty())
	{
		remove_at(removal_q.front());
		removal_q.pop();
	}
}

template<typename T>
void DynamicArray<T>::remove_at(int index)
{
	occupied.erase(index);
}

template<typename T>
void DynamicArray<T>::remove(T t_remove)
{
	remove_if([t_remove](const T &t)
	{
		return t == t_remove;
	});
}

template<typename T>
void DynamicArray<T>::remove_first(T t)
{
	for (auto it = occupied.begin();
	     it != occupied.end();
	     ++it)
	{
		int i = *it;
		if (t == array[i])
		{
			remove_at(i);
			return;
		}
	}
}

template<typename T>
Iterator<T> DynamicArray<T>::begin() const
{
	return Iterator<T>(&array[0]);
}

template<typename T>
Iterator<T> DynamicArray<T>::end() const
{
	return Iterator<T>(&array[capacity]);
}

template<typename T>
Iterator<T> DynamicArray<T>::iter_at(int index) const
{
	return Iterator<T>(&array[index]);
}

template<typename T>
void DynamicArray<T>::for_each(std::function<void(T &)> function)
{
	for (auto it = occupied.begin();
	     it != occupied.end();
	     ++it)
	{
		function(array[*it]);
	}
}

template<typename T>
void DynamicArray<T>::for_each(std::function<void(const T&)> function) const
{
	for (auto it = occupied.begin();
	     it != occupied.end();
	     ++it)
	{
		function(array[*it]);
	}
}

template<typename T>
void DynamicArray<T>::resize()
{
	int new_capacity = capacity * INCR_FACTOR;
	T *new_array = new T[new_capacity];
	for (auto it = occupied.begin();
	     it != occupied.end();
	     ++it)
	{
		new_array[*it] = array[*it];
	}
	delete[]array;
	array = new_array;
	capacity = new_capacity;
}

template<typename T>
void DynamicArray<T>::resize_spec(int access_attempt)
{
	int new_capacity = (capacity + access_attempt) * INCR_FACTOR;
	T *new_array = new T[new_capacity];
	for (auto it = occupied.begin();
	     it != occupied.end();
	     ++it)
	{
		new_array[*it] = array[*it];
	}
	delete[]array;
	array = new_array;
	capacity = new_capacity;
}

template<typename T>
void DynamicArray<T>::arr_cpy(const DynamicArray<T> &dynamic_array)
{
	capacity = dynamic_array.get_capacity();
	array = new T[capacity];
	std::queue<int> temp_q = dynamic_array.occupied;
	while (!temp_q.empty())
	{
		int i = temp_q.front();
		put(i, dynamic_array.array[i]);
		temp_q.pop();
	}
	occupied = dynamic_array.occupied;
}

template<typename T>
void DynamicArray<T>::arr_cpy(DynamicArray<T> &dynamic_array)
{
	capacity = dynamic_array.get_capacity();
	array = new T[capacity];
	std::set<int> occupiers = dynamic_array.occupied;
	for (auto it = occupiers.begin();
	     it != occupiers.end();
	     ++it)
	{
		int i = *it;
		put(i, dynamic_array.array[i]);
	}
	occupied = dynamic_array.occupied;
}

template<typename T>
int DynamicArray<T>::get_min_occupied()
{
	return *occupied.begin();
}

template<typename T>
int DynamicArray<T>::get_max_occupied()
{
	return *occupied.rbegin();
}

template<typename T>
T DynamicArray<T>::poll_front()
{
	int i = get_min_occupied();
	occupied.erase(i);
	return array[i];
}

template<typename T>
T DynamicArray<T>::poll_back()
{
	int i = get_max_occupied();
	occupied.erase(i);
	return array[i];
}

template<typename T>
T DynamicArray<T>::peek_front()
{
	return array[get_min_occupied()];
}

template<typename T>
T DynamicArray<T>::peek_back()
{
	return array[get_max_occupied()];
}

template<typename T>
std::vector<T> DynamicArray<T>::as_vector()
{
	std::vector<T> vec;
	for_each([&vec](const T& t)
	{
		vec.push_back(t);
	});
	return vec;
}









