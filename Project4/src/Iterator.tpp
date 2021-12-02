#include "../hdr/Iterator.h"

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




