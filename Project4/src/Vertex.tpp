#include "../hdr/Vertex.h"

template<typename T>
Vertex<T>::Vertex(T info) :
		info(info)
{
}

template<typename T>
bool Vertex<T>::operator>(const Vertex<T> &other) const
{
	return info > other.info;
}

template<typename T>
bool Vertex<T>::operator<(const Vertex<T> &other) const
{
	return info < other.info;
}

template<typename T>
bool Vertex<T>::operator==(const Vertex<T> &other) const
{
	return info == other.info;
}

template<typename T>
bool Vertex<T>::operator!=(const Vertex<T> &other) const
{
	return info != other.info;
}
