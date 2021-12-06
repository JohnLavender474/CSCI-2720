#include <iostream>
#include <vector>

#include "Graph.h"
#include "US_States.h"

class Object
{
public:
	int info = 0;
};

template<typename T>
class O_Container
{
public:
	std::vector<T> t_container;
	T *get_ptr(int i)
	{
		return &t_container.at(i);
	}
};

int main()
{
	Graph<int> graph;
	for (int i = 1; i < 13; i++)
	{
		graph.add_vertex(i);
	}
	graph.put_edge(1, 2);
	graph.put_edge(1, 4);
	graph.put_edge(1, 5);
	graph.put_edge(1, 12);
	graph.put_edge(2, 5);
	graph.put_edge(2, 3);
	graph.put_edge(3, 5);
	graph.put_edge(3, 6);
	graph.put_edge(4, 5);
	graph.put_edge(4, 7);
	graph.put_edge(5, 8);
	graph.put_edge(6, 8);
	graph.put_edge(7, 9);
	graph.put_edge(8, 10);
	graph.put_edge(9, 10);
	graph.put_edge(9, 11);
	graph.put_edge(2, 1);
	graph.put_edge(4, 1);
	graph.put_edge(5, 1);
	graph.put_edge(12, 11);
	std::cout << graph << std::endl;
	std::vector<int> path = graph.shortest_path(1, 11);
	for (auto it = path.rbegin();
	     it != path.rend();
	     ++it)
	{
		std::cout << *it << std::endl;
	}
	std::cout << "shortest path tree" << std::endl;
	std::vector<std::vector<int>> shortest_path_tree = graph.shortest_path_tree(1);
	for (std::vector<int> &v : shortest_path_tree)
	{
		for (auto it = v.rbegin();
		     it != v.rend();
		     ++it)
		{
			std::cout << *it << " ";
		}
		std::cout << std::endl;
	}
	/*
	std::deque<int> d;
	(graph.shortest_path(1, 11, d));
	while (!d.empty())
	{
		std::cout << d.front() << std::endl;
		d.pop_front();
	}
	 */
	/*
	std::cout << "remove vertex 10" << std::endl;
	graph.remove_vertex(10);
	graph.remove_vertex(6);
	graph.remove_edge(1, 2);
	std::cout << graph << std::endl;
	std::cout << "put 2 new vertices: 20 and 25. connect 20 to 13 and 7, connect 25 to 7" << std::endl;
	graph.add_vertex(20);
	graph.add_vertex(25);
	graph.put_edge(20, 7);
	graph.put_edge(20, 13);
	graph.put_edge(25, 7);
	std::cout << graph << std::endl;
	O_Container<Object *> o_container;
	Object *o1 = new Object;
	Object *o2 = new Object;
	Object *o3 = new Object;
	o1->info = 1;
	o2->info = 2;
	o3->info = 3;
	o_container.t_container.push_back(o1);
	o_container.t_container.push_back(o2);
	o_container.t_container.push_back(o3);
	Object *o_p = *o_container.get_ptr(1);
	o_p->info = 100;
	std::cout << o1->info << std::endl;
	std::cout << o2->info << std::endl;
	std::cout << o3->info << std::endl;

	DynamicArray<int> dynamic_array;
	dynamic_array.put(0, 1);
	dynamic_array.put(1, 2);
	dynamic_array.put(2, 3);
	dynamic_array.put(3, 8);
	dynamic_array.put(55, 10);
	dynamic_array.put(0, 100);
	dynamic_array.put(4, 3);
	dynamic_array.put(5, 3);
	dynamic_array.put(6, 4);
	std::cout << dynamic_array.get_size() << std::endl;
	std::cout << dynamic_array.get_capacity() << std::endl;
	std::cout << dynamic_array << std::endl;
	dynamic_array.put(50, 7);
	std::cout << dynamic_array.get_size() << std::endl;
	std::cout << dynamic_array.get_capacity() << std::endl;
	std::cout << dynamic_array << std::endl;
	dynamic_array.remove(3);
	std::cout << dynamic_array.get_size() << std::endl;
	std::cout << dynamic_array.get_capacity() << std::endl;
	std::cout << dynamic_array << std::endl;
	
	DynamicArray<int *> ints;
	ints.put(0, new int(0));
	ints.put(100, new int(100));
	ints.put(50, new int(50));
	ints.put(25, new int(25));
	ints.for_each([](const int *i)
	{
		std::cout << *i << std::endl;
	});
	std::cout << ints.get_size() << std::endl;
	std::cout << ints.get_capacity() << std::endl;
	
	Object *o1 = new Object;
	Object *o2 = o1;
	o2->info = 1;
	std::cout << o1->info << std::endl;
	 */
	return 0;
}