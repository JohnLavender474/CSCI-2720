#ifndef EDGE_H
#define EDGE_H

#include "Comparable.h"

template<typename T>
class Graph;

template<typename T>
class Vertex;

template<typename T>
class Edge
		: public Comparable<Edge<T>>
{
	friend class Graph<T>;
private:
	Edge() = delete;
	Edge(Vertex<T> &from, Vertex<T> &to, unsigned int weight);
	Vertex<T> &from;
	Vertex<T> &to;
	unsigned int weight;
	bool operator>(Edge<T> const &other) const override;
	bool operator<(Edge<T> const &other) const override;
	bool operator==(Edge<T> const &other) const override;
	bool operator!=(Edge<T> const &other) const override;
};

#include "../src/Edge.tpp"

#endif
