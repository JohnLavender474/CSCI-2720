#ifndef GRAPH_H
#define GRAPH_H

#include "Comparable.h"
#include "Pair.h"
#include "Edge.h"


#include <cstddef>
#include <vector>

template<typename T>
class Vertex;

template<typename T>
class Edge;

template<typename T>
class Graph
{
	static_assert(std::is_base_of<Comparable<T>, T>::value, "T type must derive Comparable<T>");
public:
	Graph();
	
	void add(T data);
	
	void remove(T data);
	
	void connect(T from, T to, size_t weight);
	
	void disconnect(T from, T to);
	
	std::vector<Pair<T, size_t>> adjacencies(T data);
	
	std::vector<Pair<T, size_t>> shortest_path();

private:
	
	std::vector<Vertex<T>> vertices;
	std::vector<Edge<T>> edges;
};

#include "../src/Graph.tpp"

#endif


