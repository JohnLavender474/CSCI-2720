#include "../hdr/Graph.h"
#include "../hdr/Vertex.h"


template<typename T>
Graph<T>::Graph()
{

}

template<typename T>
void Graph<T>::add(T data)
{

}

template<typename T>
void Graph<T>::remove(T data)
{

}

template<typename T>
void Graph<T>::connect(T from, T to, size_t weight)
{

}

template<typename T>
void Graph<T>::disconnect(T from, T to)
{

}

template<typename T>
std::vector<Pair<T, size_t>> Graph<T>::adjacencies(T data)
{
	return std::vector<Pair<T, size_t>>();
}

template<typename T>
std::vector<Pair<T, size_t>> Graph<T>::shortest_path()
{
	return std::vector<Pair<T, size_t>>();
}