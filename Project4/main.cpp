#include "hdr/SortedArray.h"
#include "hdr/Integer.h"
#include "hdr/Pair.h"

#include <iostream>

int main()
{
	SortedArray<Integer> sorted_int_array;
	Integer int1(5);
	Integer int2(7);
	Integer int3(2);
	Integer int4(9);
	Integer int5(100);
	Integer int6(-3);
	Integer int7(3);
	Integer int8(99);
	sorted_int_array.add(int1);
	sorted_int_array.add(int2);
	sorted_int_array.add(int3);
	sorted_int_array.add(int4);
	sorted_int_array.add(int1);
	sorted_int_array.add(int5);
	sorted_int_array.add(int6);
	sorted_int_array.add(int2);
	sorted_int_array.add(int2);
	sorted_int_array.add(int7);
	std::cout << "size: " << sorted_int_array.get_size() << std::endl;
	std::cout << "capacity: " << sorted_int_array.get_capacity() << std::endl;
	for (int i = 0; i < sorted_int_array.get_size(); i++)
	{
		std::cout << sorted_int_array.get(i) << std::endl;
	}
	std::cout << "get range of occurrences of 7:" << std::endl;
	Pair<int, int> occurrences_of_7 = sorted_int_array.range_of_occurrences(int2);
	std::cout << "from " << occurrences_of_7.k << " to " << occurrences_of_7.v << std::endl;
	int index;
	bool contains_7 = sorted_int_array.contains(int2, index);
	std::cout << "contains 7: " << contains_7 << " at index " << index << std::endl;
	bool contains_99 = sorted_int_array.contains(int8, index);
	std::cout << "contains 99: " << contains_99 << " at index " << index << std::endl;
	std::cout << "remove 7:" << std::endl;
	sorted_int_array.remove_all(int2);
	for (int i = 0; i < sorted_int_array.get_size(); i++)
	{
		std::cout << sorted_int_array.get(i) << std::endl;
	}
	return 0;
}

