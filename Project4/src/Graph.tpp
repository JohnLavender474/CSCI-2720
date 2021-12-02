#include "../hdr/Graph.h"
#include "../hdr/Vertex.h"

template<typename T>
bool Graph<T>::add_vertex(T t)
{
	return vertices.put(Vertex<T>(t), SortedArray<Vertex<T>>());
}

template<typename T>
bool Graph<T>::add_edge(T u, T v)
{
	int i_u;
	int i_v;
	if (vertices.contains_key(Vertex<T>(u), i_u) &&
	    vertices.contains_key(Vertex<T>(v), i_v))
	{
		vertices.get_val_ref(i_u).add_if_not_present(Vertex<T>(v));
		vertices.get_val_ref(i_v).add_if_not_present(Vertex<T>(u));
	}
}

template<typename T>
bool Graph<T>::remove_vertex(T v)
{
	int i;
	if (vertices.contains_key(Vertex<T>(v), i))
	{
		SortedArray<Vertex<T>> v_adjacencies = vertices.get_val_ref(i);
		for (auto it = v_adjacencies.begin(); it != v_adjacencies.end(); ++it)
		{
			
		}
	}
}



