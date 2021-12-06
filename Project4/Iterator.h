#pragma once

#include <iterator>
#include <cstddef>

template<typename T>
class Iterator
{
public:
	using iterator_category = std::forward_iterator_tag;
	using difference_type = std::ptrdiff_t;
	using value_type = T;
	using pointer = T *;
	using reference = T &;
	
	Iterator(pointer ptr);
	
	reference operator*() const;
	
	pointer operator->();
	
	Iterator &operator++();
	
	friend bool operator==(const Iterator<T> &a, const Iterator<T> &b)
	{
		return a.ptr == b.ptr;
	}
	
	friend bool operator!=(const Iterator &a, const Iterator &b)
	{
		return a.ptr != b.ptr;
	}

private:
	pointer ptr;
};

template<typename T>
Iterator<T>::Iterator(Iterator<T>::pointer ptr) :
		ptr(ptr)
{
}

template<typename T>
typename Iterator<T>::reference Iterator<T>::operator*() const
{
	return *ptr;
}

template<typename T>
typename Iterator<T>::pointer Iterator<T>::operator->()
{
	return ptr;
}

template<typename T>
Iterator<T> &Iterator<T>::operator++()
{
	ptr++;
	return *this;
}

