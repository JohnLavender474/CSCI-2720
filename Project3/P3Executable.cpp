#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>

#include "hdr/String.h"
#include "hdr/Integer.h"
#include "hdr/Function.h"
#include "hdr/LinkedList.h"
#include "hdr/AVL_Node.h"
#include "hdr/AVL_Tree.h"
#include "hdr/HashMap.h"

/* CONST VARS ------------------------------------------------------------------------------------------------------ */

const std::string AVL_TREE = "avl";
const std::string HASH_MAP = "hashmap";
const std::string INSERT = "insert";
const std::string REMOVE = "remove";
const std::string PUT = "put";
const std::string CONTAINS = "contains";
const std::string GET = "get";
const std::string CLEAR = "clear";
const std::string SIZE = "size";
const std::string HEIGHT = "height";
const std::string PRINT = "print";
const std::string INORDER = "inorder";
const std::string PREORDER = "preorder";
const std::string POSTORDER = "postorder";
const std::string LEVELORDER = "levelorder";
const std::string RETURN = "return";
const std::string EXIT = "exit";

/* ----------------------------------------------------------------------------------------------------------------- */

/* PRINT ----------------------------------------------------------------------------------------------------------- */

class Print_AVL_Data
		: public Function<AVL_Node<Integer, String> *>
{
	void function(AVL_Node<Integer, String> *t) override;
};

void Print_AVL_Data::function(AVL_Node<Integer, String> *t)
{
	std::cout << "(" << t->get_key()
			.get() << ", " << t->get_value()
			          .get() << ")" << std::endl;
}

Print_AVL_Data print_avl_data;

/* ----------------------------------------------------------------------------------------------------------------- */

/* INTEGER_STRING_PAIR --------------------------------------------------------------------------------------------- */

class Integer_String_Pair
{
public:
	Integer_String_Pair() = delete;
	
	Integer_String_Pair(Integer _integer, String _string);
	
	~Integer_String_Pair() = default;
	
	String string;
	Integer integer;
};

/* ----------------------------------------------------------------------------------------------------------------- */

/* BAD_PROJECT3_TEST_FILE------------------------------------------------------------------------------------------- */

class BadInput
		: public std::exception
{
public:
	BadInput(const std::string &msg);
	
	std::string get_msg();

private:
	std::string msg;
};

/* ----------------------------------------------------------------------------------------------------------------- */

/* FORWARD DECLARATIONS -------------------------------------------------------------------------------------------- */

void program_loop();

void avl_program_loop(AVL_Tree<Integer, String> *&avl_tree);

void hashmap_program_loop(HashMap<Integer, String> *&hashmap);

void hashmap_program_loop();

std::queue<Integer_String_Pair> parse_int_str_file(const std::string &src);

Integer generate_integer_obj(const std::string &str);

bool is_num(const std::string &str, int &num);

void test_AVL();

void test_linked_list();

void test_hashmap();

bool file_exists(const std::string &src);

void leave_program();

/* ----------------------------------------------------------------------------------------------------------------- */

int main()
{
	/*
	test_AVL();
	test_linked_list();
	test_hashmap();
	 */
	while (1)
	{
		program_loop();
	}
	return 0;
}

void program_loop()
{
	while (1)
	{
		try
		{
			std::string input;
			std::cout << "\n\nAVL_Tree or HashMap: ";
			getline(std::cin, input);
			if (input.compare(AVL_TREE) == 0)
			{
				AVL_Tree<Integer, String> *avl_tree = new AVL_Tree<Integer, String>();
				avl_program_loop(avl_tree);
				delete avl_tree;
			}
			else if (input.compare(HASH_MAP) == 0)
			{
				HashMap<Integer, String> *hashmap = new HashMap<Integer, String>();
				hashmap_program_loop(hashmap);
				delete hashmap;
			}
			else if (input.compare(RETURN) == 0)
			{
				std::cout << "Nothing to return to. This is the main hub of the program..." << std::endl;
			}
			else if (input.compare(EXIT) == 0)
			{
				leave_program();
			}
			else
			{
				std::cout << "Your input could not be read. Please try again..." << std::endl;
			}
		}
		catch (BadInput bi)
		{
			std::cout << bi.get_msg() << std::endl;
		}
	}
}

void avl_program_loop(AVL_Tree<Integer, String> *&avl_tree)
{
	std::string src;
	std::cout << "Enter file path: ";
	std::getline(std::cin, src);
	std::queue<Integer_String_Pair> q = parse_int_str_file(src);
	while (!q.empty())
	{
		Integer_String_Pair int_str_pair = q.front();
		avl_tree->insert(int_str_pair.integer, int_str_pair.string);
		q.pop();
	}
	std::cout << "Enter help for more info -------------------------------------------------------------" << std::endl;
	std::string input;
	while (1)
	{
		try
		{
			std::cout << "AVL_TREE ------------------------------------------------------------------" << std::endl;
			std::cout << "Command: ";
			getline(std::cin, input);
			if (input.compare(EXIT) == 0)
			{
				leave_program();
			}
			else if (input.compare(RETURN) == 0)
			{
				std::cout << "Returning to main hub..." << std::endl;
				break;
			}
			else if (input.compare(PUT) == 0)
			{
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				std::cout << "String Value: ";
				getline(std::cin, input);
				String str(input);
				avl_tree->insert(num, str);
			}
			else if (input.compare(REMOVE) == 0)
			{
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				avl_tree->remove(num);
			}
			else if (input.compare(GET) == 0)
			{
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				String str;
				if (avl_tree->get(num, str))
				{
					std::cout << "Found value: " << str << std::endl;
				}
				else
				{
					std::cout << "No value associated with key <" << num << ">" << std::endl;
				}
			}
			else if (input.compare(CONTAINS) == 0)
			{
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				if (avl_tree->contains(num, true))
				{
					std::cout << "True" << std::endl;
				}
				else
				{
					std::cout << "False" << std::endl;
				}
			}
			else if (input.compare(PRINT) == 0)
			{
				std::cout << "Print type: ";
				std::getline(std::cin, input);
				if (input.compare(PREORDER) == 0)
				{
					std::cout << "Performing preorder function..." << std::endl;
					avl_tree->preorder_function(print_avl_data);
				}
				else if (input.compare(POSTORDER) == 0)
				{
					std::cout << "Performing postorder function..." << std::endl;
					avl_tree->postorder_function(print_avl_data);
				}
				else if (input.compare(LEVELORDER) == 0)
				{
					std::cout << "Performing levelorder function..." << std::endl;
					avl_tree->levelorder_function(print_avl_data);
				}
				else if (input.compare(INORDER) == 0)
				{
					std::cout << "Performing inorder function..." << std::endl;
					avl_tree->inorder_function(print_avl_data);
				}
			}
			else if (input.compare(CLEAR) == 0)
			{
				delete avl_tree;
				avl_tree = new AVL_Tree<Integer, String>();
				std::cout << "Successfully cleared avl tree.\n" << std::endl;
			}
			else
			{
				throw BadInput("Could not read input: " + input);
			}
		}
		catch (BadInput reenter_while_loop)
		{
			std::cout << reenter_while_loop.get_msg() << std::endl;
			std::cout << "Try your command again..." << std::endl;
		}
	}
}

void hashmap_program_loop(HashMap<Integer, String> *&hashmap)
{
	std::string src;
	std::cout << "Enter file path: ";
	std::getline(std::cin, src);
	std::queue<Integer_String_Pair> q = parse_int_str_file(src);
	while (!q.empty())
	{
		Integer_String_Pair int_str_pair = q.front();
		hashmap->put(int_str_pair.integer, int_str_pair.string);
		q.pop();
	}
	std::cout << "Enter help for more info -------------------------------------------------------------" << std::endl;
	std::string input;
	while (1)
	{
		try
		{
			std::cout << "HASH MAP ------------------------------------------------------------------" << std::endl;
			std::cout << "Command: ";
			getline(std::cin, input);
			if (input.compare(EXIT) == 0)
			{
				leave_program();
			}
			else if (input.compare(RETURN) == 0)
			{
				std::cout << "Returning to main hub..." << std::endl;
				break;
			}
			else if (input.compare(INSERT) == 0)
			{
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				std::cout << "String Value: ";
				getline(std::cin, input);
				String str(input);
				hashmap->put(num, str);
			}
			else if (input.compare(REMOVE) == 0)
			{
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				hashmap->remove(num);
			}
			else if (input.compare(GET) == 0)
			{
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				String str;
				if (hashmap->get(num, str))
				{
					std::cout << "Found value: " << str << std::endl;
				}
				else
				{
					std::cout << "No value associated with key <" << num << ">" << std::endl;
				}
			}
			else if (input.compare(CONTAINS) == 0)
			{
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				if (hashmap->contains(num))
				{
					std::cout << "True" << std::endl;
				}
				else
				{
					std::cout << "False" << std::endl;
				}
			}
			else if (input.compare(PRINT) == 0)
			{
				hashmap->print();
			}
			else if (input.compare(CLEAR) == 0)
			{
				delete hashmap;
				hashmap = new HashMap<Integer, String>();
				std::cout << "Successfully cleared hashmap.\n" << std::endl;
			}
			else
			{
				throw BadInput("Invalid input: " + input);
			}
		}
		catch (BadInput reenter_while_loop)
		{
			std::cout << reenter_while_loop.get_msg() << std::endl;
			std::cout << "Try your command again..." << std::endl;
		}
	}
}

Integer generate_integer_obj(const std::string &str)
{
	int num;
	if (!is_num(str, num))
	{
		throw BadInput(str + " cannot be converted to integer.");
	}
	Integer num_int(num);
	return num_int;
}

std::queue<Integer_String_Pair> parse_int_str_file(const std::string &src)
{
	if (!file_exists(src))
	{
		throw BadInput("File does not exist. Try again.");
	}
	std::queue<Integer_String_Pair> int_str_pair_q;
	std::string line;
	std::ifstream rfile;
	rfile.open(src);
	if (rfile.is_open())
	{
		while (std::getline(rfile, line) && line.length() != 0)
		{
			std::vector<std::string> tokens;
			std::stringstream checkl(line);
			std::string intermediate;
			while (std::getline(checkl, intermediate, ' '))
			{
				std::cout << intermediate << std::endl;
				tokens.push_back(intermediate);
			}
			std::string str_tok1 = tokens.at(0);
			std::cout << "token 1: " << str_tok1 << std::endl;
			int num;
			if (!is_num(str_tok1, num))
			{
				throw BadInput(str_tok1 + " cannot be converted to type int.");
			}
			Integer i(num);
			std::string str_tok2 = tokens.at(1);
			std::cout << "token 2: " << str_tok2 << std::endl;
			String str(str_tok2);
			Integer_String_Pair int_string_pair(i, str);
			int_str_pair_q.push(int_string_pair);
		}
		rfile.close();
	}
	return int_str_pair_q;
}

bool is_num(const std::string &str, int &num)
{
	for (int i = 0;
	     i < str.size();
	     i++)
	{
		if (!isnumber(str[i]) && str[i] != ' ')
		{
			num = -1;
			return false;
		}
	}
	num = atoi(str.c_str());
	return true;
}

void test_linked_list()
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

void test_AVL()
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
	
	std::cout << "\ndelete 10\n" << std::endl;
	avl_tree->remove(int1);
	std::cout << "\ndelete 30\n" << std::endl;
	avl_tree->remove(int3);
	
	std::cout << "\nlevelorder function\n" << std::endl;
	avl_tree->levelorder_function(print_AVL_Data);
	
	delete avl_tree;
}

void test_hashmap()
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

bool file_exists(const std::string &src)
{
	std::ifstream f(src.c_str());
	return f.good();
}

Integer_String_Pair::Integer_String_Pair(Integer _integer, String _string)
		: integer(_integer), string(_string)
{
}

BadInput::BadInput(const std::string &msg)
		: msg(msg)
{
}

std::string BadInput::get_msg()
{
	return msg;
}

void leave_program()
{
	std::cout << "Hope you enjoyed using my Project 3 program! :)" << std::endl;
	exit(0);
}
