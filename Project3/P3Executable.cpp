#include <iostream>

#include "hdr/String.h"
#include "hdr/Integer.h"
#include "hdr/Function.h"
#include "hdr/LinkedList.h"
#include "hdr/AVL_Node.h"
#include "hdr/AVL_Tree.h"
#include "hdr/HashMap.h"

/* PRINT ----------------------------------------------------------------------------------------------------------- */

class Print_AVL_Data
		: public Function<AVL_Node<Integer, String> *>
{
	void function(AVL_Node<Integer, String> *t) override;
};

void Print_AVL_Data::function(AVL_Node<Integer, String> *t)
{
	std::cout << "key: " << t->get_key()
			.get() << " value: " << t->get_value()
			          .get() << std::endl;
}

/* ----------------------------------------------------------------------------------------------------------------- */

/* DECLARATIONS ---------------------------------------------------------------------------------------------------- */

void testLinkedList()
{
	Integer int1(10);
	Integer int2(20);
	Integer int3(30);
	Integer int4(5);
	Integer int5(25);
	Integer int6(15);
	
	std::cout << "\n\nLINKEDLIST:\n" << std::endl;
	LinkedList<Integer> *linkedList = new LinkedList<Integer>();
	std::cout << "aded 10" << std::endl;
	linkedList->add(int1);
	std::cout << "aded 20" << std::endl;
	linkedList->add(int2);
	std::cout << "aded 30" << std::endl;
	linkedList->add(int3);
	std::cout << "aded 5" << std::endl;
	linkedList->add(int4);
	std::cout << "aded 25" << std::endl;
	linkedList->add(int5);
	std::cout << "aded 15" << std::endl;
	linkedList->add(int6);
	std::cout << "\nprint:" << std::endl;
	linkedList->print();
	std::cout << "\nremove 5" << std::endl;
	linkedList->remove(5);
	std::cout << "\nprint:" << std::endl;
	linkedList->print();
	std::cout << "\ncontains 10:" << std::endl;
	std::cout << linkedList->contains(10) << std::endl;
	std::cout << "\ncontains 100:" << std::endl;
	std::cout << linkedList->contains(100) << std::endl;
	std::cout << "\nget element at index 3:" << std::endl;
	std::cout << linkedList->get(3) << std::endl;
	for (size_t i = 0;
	     i < 3;
	     i++)
	{
		std::cout << "\npop:" << std::endl;
		std::cout << linkedList->pop() << std::endl;
	}
	std::cout << "\nprint:" << std::endl;
	linkedList->print();
	
	delete linkedList;
}

void testAVL()
{
	Integer int1(10);
	Integer int2(20);
	Integer int3(30);
	Integer int4(5);
	Integer int5(25);
	Integer int6(15);
	Integer int7(100);
	Integer int8(18);
	Integer int9(12);
	Integer int10(3);
	Integer int11(27);
	Integer int12(31);
	
	String s1("Hello");
	String s2("World");
	String s3("This");
	String s4("Is");
	String s5("A");
	String s6("Test");
	
	std::cout << "\n\nAVL TREE:\n" << std::endl;
	
	AVL_Tree<Integer, String> *avl_tree = new AVL_Tree<Integer, String>();
	
	avl_tree->insert(int1, s1);
	avl_tree->insert(int2, s2);
	avl_tree->insert(int3, s3);
	avl_tree->insert(int4, s4);
	avl_tree->insert(int5, s5);
	avl_tree->insert(int6, s6);
	avl_tree->insert(int7, s1);
	avl_tree->insert(int8, s2);
	avl_tree->insert(int9, s3);
	avl_tree->insert(int10, s4);
	avl_tree->insert(int11, s5);
	avl_tree->insert(int12, s6);
	
	Print_AVL_Data print_AVL_Data;
	
	std::cout << "\ninorder function\n" << std::endl;
	avl_tree->inorder_function(print_AVL_Data);
	
	std::cout << "\npreorder function\n" << std::endl;
	avl_tree->preorder_function(print_AVL_Data);
	
	std::cout << "\npostorder function\n" << std::endl;
	avl_tree->postorder_function(print_AVL_Data);
	
	std::cout << "\nlevelorder function\n" << std::endl;
	avl_tree->levelorder_function(print_AVL_Data);
	
	delete avl_tree;
}

void testHashMap()
{
	Integer int1(10);
	Integer int2(20);
	Integer int3(30);
	Integer int4(5);
	Integer int5(25);
	Integer int6(15);
	Integer int7(100);
	Integer int8(18);
	Integer int9(12);
	Integer int10(3);
	Integer int11(27);
	Integer int12(31);
	
	String s1("Hello");
	String s2("World");
	String s3("This");
	String s4("Is");
	String s5("A");
	String s6("Test");
	
	std::vector<Integer> ints;
	
	ints.push_back(int1);
	ints.push_back(int2);
	ints.push_back(int3);
	ints.push_back(int4);
	ints.push_back(int5);
	ints.push_back(int6);
	ints.push_back(int7);
	ints.push_back(int8);
	ints.push_back(int9);
	ints.push_back(int10);
	ints.push_back(int11);
	ints.push_back(int12);
	
	HashMap<Integer, String> *hashMap = new HashMap<Integer, String>();
	for (size_t i = 0;
	     i < ints.size();
	     i++)
	{
		hashMap->put(ints.at(i), s1);
		std::cout << std::endl;
	}
	hashMap->print();
	
	std::cout << "Put 3 with World" << std::endl;
	hashMap->put(int10, s2);
	hashMap->print();
	delete hashMap;
}

int main()
{
	//testAVL();
	//testLinkedList();
	testHashMap();
	return 0;
}