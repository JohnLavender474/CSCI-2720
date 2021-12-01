#ifndef PAIR_H
#define PAIR_H

template<typename K, typename V>
class Pair
{
public:
	Pair() = default;
	Pair(K k, V v);
	K k;
	V v;
};

template<typename K, typename V>
Pair<K, V>::Pair(K k, V v) :
		k(k),
		v(v)
{
}

#endif
