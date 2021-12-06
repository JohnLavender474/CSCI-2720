#include <iostream>
#include <vector>

#include "Graph.h"
#include "DynamicArray.h"

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
	graph.add_vertex(10);
	graph.add_vertex(15);
	graph.add_vertex(20);
	graph.add_vertex(25);
	graph.add_vertex(30);
	graph.add_vertex(35);
	graph.add_vertex(40);
	graph.add_vertex(45);
	graph.add_vertex(50);
	graph.put_edge(10, 15);
	graph.put_edge(10, 20);
	graph.put_edge(30, 40);
	graph.put_edge(30, 10);
	graph.put_edge(50, 45);
	graph.put_edge(10, 45);
	std::cout << graph << std::endl;
	/*
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