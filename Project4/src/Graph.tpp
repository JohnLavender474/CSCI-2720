#include "../hdr/Graph.h"
#include "../hdr/Vertex.h"

#include <queue>

template<typename T, typename W>
bool Graph<T, W>::add_vertex(T t)
{
	if (!vertices.contains_key(Vertex<T>(t)))
	{
		vertices.put(Vertex<T>(t), SortedArrayMap<Vertex<T>, W>());
		return true;
	}
	else
	{
		return false;
	}
}

template<typename T, typename W>
bool Graph<T, W>::put_edge(T u, T v, W w)
{
	Vertex<T> u_v(u);
	Vertex<T> v_v(v);
	int u_index;
	if (!vertices.contains_key(u_v, u_index))
	{
		return false;
	}
	int v_index;
	if (!vertices.contains_key(v_v, v_index))
	{
		return false;
	}
	vertices.get_val_ref(u_index).put(v_v, w);
	vertices.get_val_ref(v_index).put(u_v, w);
	return true;
}

template<typename T, typename W>
bool Graph<T, W>::remove_vertex(T t)
{
	Vertex<T> v(t);
	int v_index;
	if (vertices.contains_key(v, v_index))
	{
		SortedArray<Vertex<T>> v_arr = vertices.get_val_ref(v_index).sorted_key_array();
		for (auto it = v_arr.begin(); it != v_arr.end(); ++it)
		{
			int e_index = vertices.index_of(*it);
			vertices.get_val_ref(e_index).remove(v);
		}
		vertices.remove(v);
		return true;
	}
	return false;
}

template<typename T, typename W>
bool Graph<T, W>::remove_edge(T u, T v)
{
	Vertex<T> u_v(u);
	Vertex<T> v_v(v);
	int u_index;
	if (!vertices.contains_key(u_v, u_index))
	{
		return false;
	}
	int v_index;
	if (!vertices.contains_key(v_v, v_index))
	{
		return false;
	}
	vertices.get_val_ref(u_index).remove(v_v);
	vertices.get_val_ref(v_index).remove(u_v);
}



