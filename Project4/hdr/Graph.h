#ifndef GRAPH_H
#define GRAPH_H

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
	
	std::queue<Pair<T, W>> shortest_path(T u, T v);
	
	/*
	friend std::ostream &operator<<(std::ostream &stream, const Graph<T, W> &graph)
	{
		int i = 0;
		SortedArray<Vertex<T>> sorted_array = graph.vertices.sorted_key_array();
		
	}
	 */

private:
	
	SortedArrayMap<Vertex<T>, SortedArrayMap<Vertex<T>, W>> vertices;
	
};

#include "../src/Graph.tpp"

#endif


