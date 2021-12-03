#ifndef PAIR_H
#define PAIR_H

#include <iostream>

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
	
	bool operator>(Pair<K, V> &other) const override;
	
	bool operator>=(Pair<K, V> const &other) const override;
	
	bool operator>=(Pair<K, V> &other) const override;
	
	bool operator<(Pair<K, V> const &other) const override;
	
	bool operator<(Pair<K, V> &other) const override;
	
	bool operator<=(Pair<K, V> const &other) const override;
	
	bool operator<=(Pair<K, V> &other) const override;
	
	bool operator==(Pair<K, V> const &other) const override;
	
	bool operator==(Pair<K, V> &other) const override;
	
	bool operator!=(Pair<K, V> const &other) const override;
	
	bool operator!=(Pair<K, V> &other) const override;
	
	friend std::ostream &operator<<(std::ostream &stream, const Pair<K, V> &pair)
	{
		return stream << "(" << pair.k << ", " << pair.v << ")";
	}
};

#include "../src/Pair.tpp"

#endif
