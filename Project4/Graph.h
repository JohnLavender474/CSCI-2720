#pragma once

#include <vector>
#include <queue>
#include <set>

#include "DynamicArray.h"

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
	
	friend std::ostream &operator<<(std::ostream &stream, const Graph<T> &graph)
	{
		int index_v = 0;
		graph.vertices.for_each([&graph, &stream, &index_v](Vertex<T> *v)
		{
			stream << "VERTEX " << ++index_v << ": " << v->info << std::endl;
			int index_e = 0;
			for (const int &i : v->edges)
			{
				Vertex<T> * o = *graph.vertices.ptr_to(i);
				stream << "\tEDGE " << ++index_e << ": " << o->info << std::endl;
			}
		});
		return stream;
	}

private:
	
	DynamicArray<Vertex<T> *> vertices;
	
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
id(id),
predecessor_id(-1)
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
	bool contains = false;
	vertices.for_each([&t, &contains](const Vertex<T> *v)
	{
		if (t == v->info)
		{
			contains = true;
		}
	});
	return contains;
}

template<typename T>
bool Graph<T>::add_vertex(T t)
{
	if (contains_vertex(t))
	{
		return false;
	}
	int id = generate_id();
	vertices.put(id, new Vertex<T>(t, id));
	return true;
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
	Vertex<T> *u_v = *vertices.ptr_to(u_index);
	Vertex<T> *v_v = *vertices.ptr_to(v_index);
	std::set<int> u_edges = u_v->edges;
	std::set<int> v_edges = v_v->edges;
	return u_edges.find(v_index) != u_edges.end() && v_edges.find(u_index) != v_edges.end();
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
	Vertex<T> *u_v = *vertices.ptr_to(u_index);
	Vertex<T> *v_v = *vertices.ptr_to(v_index);
	u_v->edges.insert(v_index);
	v_v->edges.insert(u_index);
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
	Vertex<T> *t_v = *vertices.ptr_to(i);
	std::set<int> edges = t_v->edges;
	for (const int &j : edges)
	{
		Vertex<T> *o_v = *vertices.ptr_to(j);
		o_v->edges.erase(i);
	}
	delete t_v;
	vertices.put(i, nullptr);
	vertices.remove_at(i);
	recycled_ids.push(i);
	return true;
}

template<typename T>
bool Graph<T>::remove_edge(T u, T v)
{
	int u_index = index_of_vertex(u);
	int v_index = index_of_vertex(v);
	Vertex<T> *u_v = vertices.ptr_to(u_index);
	Vertex<T> *v_v = vertices.ptr_to(v_v);
	u_v->edges.erase(v_index);
	v_v->edges.erase(u_index);
}

template<typename T>
int Graph<T>::index_of_vertex(T t)
{
	for (auto it = vertices.begin();
	     it != vertices.end();
	     ++it)
	{
		Vertex<T> *v = *it;
		if (v != nullptr)
		{
			if (t == v->info)
			{
				return v->id;
			}
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
