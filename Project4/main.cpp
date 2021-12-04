#include "hdr/SortedArray.h"
#include "hdr/SortedArrayMap.h"
#include "hdr/Pair.h"
#include "hdr/Graph.h"

#include <iostream>

void test_sorted_array();
void test_sorted_array_map();
void test_graph();

int main()
{
	/*
	std::cout << "\n\nSORTED ARRAY\n" << std::endl;
	test_sorted_array();
	std::cout << "\n\nSORTED ARRAY MAP\n" << std::endl;
	test_sorted_array_map();
	 */
	std::cout << "\n\nGRAPH\n" << std::endl;
	test_graph();
	return 0;
}

void test_graph()
{
	Graph<int, int> graph;
	graph.add_vertex(10);
	graph.add_vertex(2);
	graph.add_vertex(3);
	graph.put_edge(10, 2, 1);
	graph.put_edge(10, 3, 2);
}

void test_sorted_array_map()
{
	SortedArrayMap<int, std::string> sorted_int_str_map;
	sorted_int_str_map.put(7, "hello");
	sorted_int_str_map.put(4, "world");
	sorted_int_str_map.put(8, "my");
	sorted_int_str_map.put(2, "name");
	sorted_int_str_map.put(5, "is");
	sorted_int_str_map.put(3, "john");
	sorted_int_str_map.put(6, "lavender");
	sorted_int_str_map.put(10, "YAY!");
	sorted_int_str_map.put(2, "TRAP!");
	sorted_int_str_map.put(3, "YES! TRAP!");
	sorted_int_str_map.put(6, "TRAP?");
	sorted_int_str_map.put(11, "not a trap");
	std::cout << sorted_int_str_map << std::endl;
	std::string str_10;
	sorted_int_str_map.get(10, str_10);
	std::cout << str_10 << std::endl;
	std::cout << "contains key 8: " << sorted_int_str_map.contains_key(8) << std::endl;
	std::cout << "contains key 12: " << sorted_int_str_map.contains_key(12) << std::endl;
	std::cout << "contains key 9: " << sorted_int_str_map.contains_key(9) << std::endl;
	std::cout << "contains key 2: " << sorted_int_str_map.contains_key(2) << std::endl;
	Pair<int, std::string> i_3_pair = sorted_int_str_map.get_pair(3);
	std::cout << i_3_pair << std::endl;
	sorted_int_str_map.remove_index(3);
	std::cout << "removed index 3: " << sorted_int_str_map << std::endl;
}

void test_sorted_array()
{
	SortedArray<int> sorted_int_array;
	sorted_int_array.add_if_not_present(2);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(5);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(10);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(3);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(11);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(7);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(1);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(14);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(15);
	std::cout << sorted_int_array << std::endl;
	std::cout << "for each, increment or decrement key by rand val:" << std::endl;
	bool incr = true;
	srand(time(NULL));
	sorted_int_array.for_each([&incr](int &r)
	{
		std::cout << "incr: " << incr << std::endl;
		int d = rand() % 10;
		r = incr ? r - d : r + d;
		incr = !incr;
	});
	std::cout << sorted_int_array << std::endl;
	std::cout << "at index 2: " << sorted_int_array.get(2) << std::endl;
	std::cout << "at index 4: " << sorted_int_array.get(4) << std::endl;
	std::cout << "at index 5: " << sorted_int_array.get(5) << std::endl;
	std::cout << "at index 0: " << sorted_int_array.get(0) << std::endl;
	std::cout << "size: " << sorted_int_array.get_size() << std::endl;
	sorted_int_array.remove_if([](const int &r){return r > 3 && r < 11;});
	std::cout << "removed r > 3 && r < 11: " << sorted_int_array << std::endl;
	std::cout << "size: " << sorted_int_array.get_size() << std::endl;
	sorted_int_array.add(50);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add(38);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add(38);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(1);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(-2);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add_if_not_present(-10);
	sorted_int_array.add_if_not_present(-10);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add(-11);
	std::cout << sorted_int_array << std::endl;
	sorted_int_array.add(-10);
	std::cout << sorted_int_array << std::endl;
	for (int i = 0; i < 6; i++)
	{
		sorted_int_array.add(2);
	}
	std::cout << sorted_int_array << std::endl;
	std::cout << "contains 2: " << sorted_int_array.contains(2) << std::endl;
	std::cout << "range of 2: " << sorted_int_array.range_of_occurrences(2) << std::endl;
	sorted_int_array.remove_all(2);
	std::cout << "removed all 2's: " << sorted_int_array << std::endl;
	std::cout << "contains 2: " << sorted_int_array.contains(2) << std::endl;
}



