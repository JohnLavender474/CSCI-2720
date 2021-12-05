#pragma once

#include <vector>
#include <queue>
#include <set>

template<typename T>
class Vertex;

template<typename T>
class Graph
{

public:
	
	Graph();
	
	~Graph();
	
	bool contains_vertex(T t);
	
	bool add_vertex(T t);
	
	bool contains_edge(T u, T v);
	
	bool put_edge(T u, T v);
	
	bool remove_vertex(T t);
	
	bool remove_edge(T u, T v);

private:
	
	std::vector<Vertex<T> *> vertices;
	
	int index_of_vertex(T t);
	
	int generate_id();
	
	int max_id;
	
	std::queue<int> recycled_ids;
	
};

template<typename T>
class Vertex
{
	friend class Graph<T>;

private:
	
	Vertex() = delete;
	
	Vertex(T info, int id);
	
	~Vertex() = default;
	
	T info;
	int id;
	std::set<int> edges;
	int predecessor_id;
	
	friend bool operator==(const Vertex<T> &v1, const Vertex<T> &v2)
	{
		return v1.info == v2.info;
	}
	
};

template<typename T>
Vertex<T>::Vertex(T info, int id) :
info(info),
predecessor_id(-1),
{
}

template<typename T>
Graph<T>::Graph() :
max_id(0)
{
}

template<typename T>
Graph<T>::~Graph()
{
	for (Vertex<T> *v : vertices)
	{
		delete v;
	}
}

template<typename T>
bool Graph<T>::contains_vertex(T t)
{
	for (Vertex<T> * v : vertices)
	{
		if (t == v->info)
		{
			return true;
		}
	}
	return false;
}

template<typename T>
bool Graph<T>::add_vertex(T t)
{
	if (contains_vertex(t))
	{
		return false;
	}
	int id = generate_id();
	vertices.at(id) = new Vertex<T>(t, id);
}

template<typename T>
bool Graph<T>::contains_edge(T u, T v)
{
	int u_index = index_of_vertex(u);
	int v_index = index_of_vertex(v);
	if (u_index == -1 || v_index == -1)
	{
		return false;
	}
	std::set<int> u_edges = vertices.at(u_index)->edges;
	std::set<int> v_edges = vertices.at(v_index)->edges;
	return u_edges.find(v_index) != u_edges.end() && v_edges.template find(u_index) != v_edges.end();
}

template<typename T>
bool Graph<T>::put_edge(T u, T v)
{
	int u_index = index_of_vertex(u);
	int v_index = index_of_vertex(v);
	if (u_index == -1 || v_index == -1)
	{
		return false;
	}
	vertices.at(u_index)->edges.insert(v_index);
	vertices.at(v_index)->edges.insert(u_index);
	return true;
}

template<typename T>
bool Graph<T>::remove_vertex(T t)
{
	int i = index_of_vertex(t);
	if (i == -1)
	{
		return false;
	}
	std::set<int> edges = vertices.at(i)->edges;
	for (int j : edges)
	{
		vertices.at(j)->edges.erase(i);
	}
	delete vertices.at(i);
	vertices.at(i) = nullptr;
	recycled_ids.push(i);
	return true;
}

template<typename T>
bool Graph<T>::remove_edge(T u, T v)
{
	int u_index = index_of_vertex(u);
	int v_index = index_of_vertex(v);
	vertices.at(u_index)->edges.erase(v_index);
	vertices.at(v_index)->edges.erase(u_index);
}

template<typename T>
int Graph<T>::index_of_vertex(T t)
{
	for (int i = 0; i < vertices.size(); i++)
	{
		if (t == vertices.at(i)->info)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
int Graph<T>::generate_id()
{
	if (recycled_ids.empty())
	{
		return max_id++;
	}
	else
	{
		int i = recycled_ids.front();
		recycled_ids.pop();
		return i;
	}
}
