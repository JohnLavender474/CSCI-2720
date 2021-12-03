#ifndef VERTEX_H
#define VERTEX_H

#include "Comparable.h"
#include "SortedArray.h"
#include "Pair.h"

template<typename T>
class Vertex
		: public Comparable<Vertex<T>>
{

public:
	Vertex();
	
	Vertex(T info);
	
	~Vertex() = default;
	
	Vertex<T> &get_predecessor();
	
	void set_predecessor(Vertex<T> const &_predecessor);
	
	void reset();
	
	bool operator>(Vertex<T> const &other) const override;
	
	bool operator>(Vertex<T> &other) const override;
	
	bool operator>=(Vertex<T> const &other) const override;
	
	bool operator>=(Vertex<T> &other) const override;
	
	bool operator<(Vertex<T> const &other) const override;
	
	bool operator<(Vertex<T> &other) const override;
	
	bool operator<=(Vertex<T> const &other) const override;
	
	bool operator<=(Vertex<T> &other) const override;
	
	bool operator==(Vertex<T> const &other) const override;
	
	bool operator==(Vertex<T> &other) const override;
	
	bool operator!=(Vertex<T> const &other) const override;
	
	bool operator!=(Vertex<T> &other) const override;
	
	friend std::ostream &operator<<(std::ostream &stream, const Vertex<T> &vertex);
	
	T info;
	Vertex<T> *predecessor;
	bool is_discovered;
};

#include "../src/Vertex.tpp"

#endif
