#include "../hdr/Pair.h"

template<typename K, typename V>
Pair<K, V>::Pair(K k, V v) :
		k(k),
		v(v)
{
}

template<typename K, typename V>
bool Pair<K, V>::operator>(const Pair<K, V> &other) const
{
	return k > other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator>=(const Pair<K, V> &other) const
{
	return k >= other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator<(const Pair<K, V> &other) const
{
	return k < other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator<=(const Pair<K, V> &other) const
{
	return k <= other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator==(const Pair<K, V> &other) const
{
	return (k == other.k) && (v == other.v);
}

template<typename K, typename V>
bool Pair<K, V>::operator!=(const Pair<K, V> &other) const
{
	return (k != other.k) || (v != other.v);
}

template<typename K, typename V>
bool Pair<K, V>::operator>(Pair<K, V> &other) const
{
	return k > other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator>=(Pair<K, V> &other) const
{
	return k >= other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator<(Pair<K, V> &other) const
{
	return k < other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator<=(Pair<K, V> &other) const
{
	return k <= other.k;
}

template<typename K, typename V>
bool Pair<K, V>::operator==(Pair<K, V> &other) const
{
	return (k == other.k) && (v == other.v);
}

template<typename K, typename V>
bool Pair<K, V>::operator!=(Pair<K, V> &other) const
{
	return (k != other.k) || (v != other.v);
}
