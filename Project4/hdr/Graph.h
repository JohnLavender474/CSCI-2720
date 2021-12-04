#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

#include "Comparable.h"
#include "Pair.h"
#include "SortedArray.h"
#include "SortedArrayMap.h"
#include "Vertex.h"

template<typename T, typename W>
class Graph
{
	
public:
	Graph() = default;
	
	~Graph() = default;
	
	bool add_vertex(T t);
	
	bool put_edge(T u, T v, W w);
	
	bool remove_vertex(T t);
	
	bool remove_edge(T u, T v);
	
	// std::queue<Pair<T, W>> edges_of(T t);
	
	// std::queue<Pair<T, W>> shortest_path(T u, T v);
	
	friend std::ostream &operator<<(std::ostream &stream, const Graph<T, W> &graph)
	{
		/*
		 * graph.for_each([](Pair<Vertex<T>, SortedArrayMap<Vertex<T>, W>> &p)
		 * {
		 *     Vertex<T> vertex = p.k;
		 *     SortedArrayMap<Vertex<T>, W> edge_weight_map = p.v;
		 *     stream << "vertex: " << vertex << std::endl;
		 *     edge_weight_map.for_each([&stream](Pair<Vertex<T>, W w> &q)
		 *     {
		 *          Vertex<T> v = q.k;
		 *          W w = q.v;
		 *          stream << "\tedge --> {" << v << "} with weight = " << w << std::endl;
		 *     }
		 * }
		 */
		return stream;
	}

private:
	
	SortedArrayMap<Vertex<T>, SortedArrayMap<Vertex<T>, W>> vertices;
	
};

#include "../src/Graph.tpp"

#endif


