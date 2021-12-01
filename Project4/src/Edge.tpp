#include "../hdr/Edge.h"

template<typename T>
Edge<T>::Edge(Vertex<T> &from, Vertex<T> &to, unsigned int weight) :
		from(from),
		to(to),
		weight(weight)
{
}

template<typename T>
bool Edge<T>::operator>(const Edge<T> &other) const
{
	return from > other.from;
}

template<typename T>
bool Edge<T>::operator<(const Edge<T> &other) const
{
	return from < other.from;
}

template<typename T>
bool Edge<T>::operator==(const Edge<T> &other) const
{
	return from == other.from;
}

template<typename T>
bool Edge<T>::operator!=(const Edge<T> &other) const
{
	return from != other.from;
}

