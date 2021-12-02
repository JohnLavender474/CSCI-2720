#ifndef PAIR_H
#define PAIR_H

template<typename K, typename V>
class Pair
		: public Comparable<Pair<K, V>>
{
public:
	Pair() = default;
	Pair(K k, V v);
	~Pair() = default;
	K k;
	V v;
	bool operator>(Pair<K, V> const &other) const override;
	bool operator<(Pair<K, V> const &other) const override;
	bool operator==(Pair<K, V> const &other) const override;
	bool operator!=(Pair<K, V> const &other) const override;
};

#include "../src/Pair.tpp"

#endif
