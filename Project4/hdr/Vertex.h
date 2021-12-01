#ifndef VERTEX_H
#define VERTEX_H

#include "Comparable.h"

template<typename T>
class Graph;

template<typename T>
class Vertex
		: public Comparable<Vertex<T>>
{
	friend class Graph<T>;
private:
	Vertex() = delete;
	Vertex(T info);
	T info;
	unsigned int degree;
	bool operator>(Vertex<T> const &other) const override;
	bool operator<(Vertex<T> const &other) const override;
	bool operator==(Vertex<T> const &other) const override;
	bool operator!=(Vertex<T> const &other) const override;
};

#include "../src/Vertex.tpp"

#endif
