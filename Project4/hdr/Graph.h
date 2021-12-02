#ifndef GRAPH_H
#define GRAPH_H

#include "Comparable.h"
#include "Pair.h"
#include "Edge.h"
#include "SortedArray.h"
#include "SortedArrayMap.h"
#include "Vertex.h"

#include <cstddef>
#include <vector>
#include <memory>
#include <type_traits>

template<typename T>
class Graph
{
	
public:
	Graph() = default;
	
	~Graph() = default;
	
	bool add_vertex(T t);
	
	bool add_edge(T u, T v);
	
	bool remove_vertex(Vertex<T> v);
	
	bool remove_edge(Vertex<T> u, Vertex<T> v);

private:
	
	SortedArrayMap<Vertex<T>, SortedArray<Vertex<T>>> vertices;
	
};

#include "../src/Graph.tpp"

#endif


