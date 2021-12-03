#include "../hdr/Vertex.h"

template<typename T>
Vertex<T>::Vertex() :
		info(T()),
		predecessor(nullptr),
		is_discovered(false)
{
}

template<typename T>
Vertex<T>::Vertex(T info) :
		info(info),
		predecessor(nullptr),
		is_discovered(false)
{
}

template<typename T>
Vertex<T> &Vertex<T>::get_predecessor()
{
	return *predecessor;
}

template<typename T>
void Vertex<T>::set_predecessor(Vertex<T> const &_predecessor)
{
	predecessor = _predecessor;
}

template<typename T>
void Vertex<T>::reset()
{
	predecessor(nullptr);
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

template<typename T>
std::ostream &operator<<(std::ostream &stream, const Vertex<T> &vertex)
{
	return stream << vertex.info;
}

template<typename T>
bool Vertex<T>::operator>(Vertex<T> &other) const
{
	return info > other.info;
}

template<typename T>
bool Vertex<T>::operator>=(const Vertex<T> &other) const
{
	return info >= other.info;
}

template<typename T>
bool Vertex<T>::operator>=(Vertex<T> &other) const
{
	return info >= other.info;
}

template<typename T>
bool Vertex<T>::operator<(Vertex<T> &other) const
{
	return info < other.info;
}

template<typename T>
bool Vertex<T>::operator<=(const Vertex<T> &other) const
{
	return info <= other.info;
}

template<typename T>
bool Vertex<T>::operator<=(Vertex<T> &other) const
{
	return info <= other.info;
}

template<typename T>
bool Vertex<T>::operator==(Vertex<T> &other) const
{
	return info == other.info;
}

template<typename T>
bool Vertex<T>::operator!=(Vertex<T> &other) const
{
	return info != other.info;
}









