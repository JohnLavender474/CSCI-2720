#include <iostream>
#include <fstream>
#include <sstream>
#include <exception>
#include <algorithm>
#include <cctype>

#include "hdr/String.h"
#include "hdr/Integer.h"
#include "hdr/Function.h"
#include "hdr/AVL_Node.h"
#include "hdr/AVL_Tree.h"
#include "hdr/HashMap.h"

/* CONST VARS ------------------------------------------------------------------------------------------------------ */

const std::string AVL_TREE = "AVL";
const std::string HASH_MAP = "HASHMAP";
const std::string INSERT = "INSERT";
const std::string REMOVE = "REMOVE";
const std::string PUT = "PUT";
const std::string CONTAINS = "CONTAINS";
const std::string GET = "GET";
const std::string CLEAR = "CLEAR";
const std::string SIZE = "SIZE";
const std::string HEIGHT = "HEIGHT";
const std::string PRINT = "PRINT";
const std::string INORDER = "INORDER";
const std::string PREORDER = "PREORDER";
const std::string POSTORDER = "POSTORDER";
const std::string LEVELORDER = "LEVELORDER";
const std::string HELP = "HELP";
const std::string RETURN = "RETURN";
const std::string EXIT = "EXIT";

/* ----------------------------------------------------------------------------------------------------------------- */

/* PRINT ----------------------------------------------------------------------------------------------------------- */

class Print_AVL_Data : public Function<AVL_Node<Integer, String> *> {
	void function(AVL_Node<Integer, String> *t) override;
};

void Print_AVL_Data::function(AVL_Node<Integer, String> *t) {
	std::cout << "(" << t->get_key()
			.get() << ", " << t->get_value()
			          .get() << ")" << std::endl;
}

Print_AVL_Data print_avl_data;

/* ----------------------------------------------------------------------------------------------------------------- */

/* INTEGER_STRING_PAIR --------------------------------------------------------------------------------------------- */

class Integer_String_Pair {
public:
	Integer_String_Pair() = delete;
	
	Integer_String_Pair(Integer _integer, String _string);
	
	~Integer_String_Pair() = default;
	
	String string;
	Integer integer;
};

/* ----------------------------------------------------------------------------------------------------------------- */

/* BAD_PROJECT3_TEST_FILE------------------------------------------------------------------------------------------- */

class BadInput : public std::exception {
public:
	BadInput(std::string &msg);
	
	std::string get_msg();

private:
	std::string msg;
};

/* ----------------------------------------------------------------------------------------------------------------- */

/* FORWARD DECLARATIONS -------------------------------------------------------------------------------------------- */

void program_loop();

void avl_program_loop(AVL_Tree<Integer, String> *&avl_tree);

void hashmap_program_loop(HashMap<Integer, String> *&hashmap);

std::queue<Integer_String_Pair> parse_int_str_file(std::string &src);

Integer generate_integer_obj(std::string &str);

bool is_num(std::string &str, int &num);

bool file_exists(std::string &src);

void remove_whitespace(std::string &str);

void to_upper(std::string &str);

void avl_help();

void hashmap_help();

void leave_program();

/* ----------------------------------------------------------------------------------------------------------------- */

int main() {
	while (1) {
		program_loop();
	}
}

void program_loop() {
	while (1) {
		try {
			system("clear");
			std::string input;
			std::cout << "avl / hashmap: ";
			getline(std::cin, input);
			remove_whitespace(input);
			to_upper(input);
			if (input.compare(AVL_TREE) == 0) {
				AVL_Tree<Integer, String> *avl_tree = new AVL_Tree<Integer, String>();
				avl_program_loop(avl_tree);
				delete avl_tree;
			} else if (input.compare(HASH_MAP) == 0) {
				HashMap<Integer, String> *hashmap = new HashMap<Integer, String>();
				hashmap_program_loop(hashmap);
				delete hashmap;
			} else if (input.compare(RETURN) == 0) {
				std::cout << "Nothing to return to. This is the main hub of the program..." << std::endl;
			} else if (input.compare(EXIT) == 0) {
				leave_program();
			} else {
				std::cout << "Your input could not be read. Please try again..." << std::endl;
			}
		} catch (BadInput bi) {
			std::cout << bi.get_msg() << std::endl;
		}
	}
}

void avl_program_loop(AVL_Tree<Integer, String> *&avl_tree) {
	std::string src;
	std::cout << "Enter file path: ";
	std::getline(std::cin, src);
	std::queue<Integer_String_Pair> q = parse_int_str_file(src);
	while (!q.empty()) {
		Integer_String_Pair int_str_pair = q.front();
		avl_tree->insert(int_str_pair.integer, int_str_pair.string);
		q.pop();
	}
	avl_help();
	std::string input;
	while (1) {
		try {
			std::cout << "\nAVL_TREE ------------------------------------------------------------------" << std::endl;
			std::cout << "Command: ";
			getline(std::cin, input);
			remove_whitespace(input);
			to_upper(input);
			if (input.compare(EXIT) == 0) {
				leave_program();
			} else if (input.compare(RETURN) == 0) {
				std::cout << "Returning to main hub..." << std::endl;
				break;
			} else if (input.compare(INSERT) == 0) {
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				std::cout << "String Value: ";
				getline(std::cin, input);
				to_upper(input);
				String str(input);
				avl_tree->insert(num, str);
			} else if (input.compare(REMOVE) == 0) {
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				if (!avl_tree->remove(num)) {
					std::cout << "Key <" << num << "> not found!" << std::endl;
				}
			} else if (input.compare(GET) == 0) {
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				String str;
				if (avl_tree->get(num, str, true)) {
					std::cout << "Found value: " << str << std::endl;
				} else {
					std::cout << "Key <" << num << "> not found!" << std::endl;
				}
			} else if (input.compare(CONTAINS) == 0) {
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				if (avl_tree->contains(num, true)) {
					std::cout << "True" << std::endl;
				} else {
					std::cout << "False" << std::endl;
				}
			} else if (input.compare(PRINT) == 0) {
				std::cout << "Print type: ";
				std::getline(std::cin, input);
				remove_whitespace(input);
				to_upper(input);
				if (input.compare(PREORDER) == 0) {
					std::cout << "\nPerforming preorder function..." << std::endl;
					avl_tree->preorder_function(print_avl_data);
				} else if (input.compare(POSTORDER) == 0) {
					std::cout << "\nPerforming postorder function..." << std::endl;
					avl_tree->postorder_function(print_avl_data);
				} else if (input.compare(LEVELORDER) == 0) {
					std::cout << "\nPerforming levelorder function..." << std::endl;
					avl_tree->levelorder_function(print_avl_data);
				} else if (input.compare(INORDER) == 0) {
					std::cout << "\nPerforming inorder function..." << std::endl;
					avl_tree->inorder_function(print_avl_data);
				}
			} else if (input.compare(SIZE) == 0) {
				std::cout << "size: " << avl_tree->get_size() << std::endl;
			} else if (input.compare(HEIGHT) == 0) {
				std::cout << "height: " << avl_tree->get_height() << std::endl;
			} else if (input.compare(CLEAR) == 0) {
				delete avl_tree;
				avl_tree = new AVL_Tree<Integer, String>();
				std::cout << "\nSuccessfully cleared avl tree.\n" << std::endl;
			} else if (input.compare(HELP) == 0) {
				avl_help();
			} else {
				std::string err_msg = "\nCould not read input: " + input;
				throw BadInput(err_msg);
			}
		} catch (BadInput reenter_while_loop) {
			std::cout << reenter_while_loop.get_msg() << std::endl;
			std::cout << "Try your command again..." << std::endl;
		}
	}
}

void hashmap_program_loop(HashMap<Integer, String> *&hashmap) {
	std::string src;
	std::cout << "Enter file path: ";
	std::getline(std::cin, src);
	std::queue<Integer_String_Pair> q = parse_int_str_file(src);
	while (!q.empty()) {
		Integer_String_Pair int_str_pair = q.front();
		hashmap->put(int_str_pair.integer, int_str_pair.string);
		q.pop();
	}
	hashmap_help();
	std::string input;
	while (1) {
		try {
			std::cout << "\nHASH MAP ------------------------------------------------------------------" << std::endl;
			std::cout << "\nCommand: ";
			getline(std::cin, input);
			remove_whitespace(input);
			to_upper(input);
			if (input.compare(EXIT) == 0) {
				leave_program();
			} else if (input.compare(RETURN) == 0) {
				std::cout << "\nReturning to main hub..." << std::endl;
				break;
			} else if (input.compare(PUT) == 0) {
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				std::cout << "String Value: ";
				getline(std::cin, input);
				String str(input);
				hashmap->put(num, str);
			} else if (input.compare(REMOVE) == 0) {
				std::cout << "Integer Key: ";
				getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				hashmap->remove(num);
			} else if (input.compare(GET) == 0) {
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				String str;
				if (hashmap->get(num, str)) {
					std::cout << "Found value: " << str << std::endl;
				} else {
					std::cout << "Key <" << num << "> not found!" << std::endl;
				}
			} else if (input.compare(CONTAINS) == 0) {
				std::cout << "Integer Key: ";
				std::getline(std::cin, input);
				Integer num = generate_integer_obj(input);
				if (hashmap->contains(num)) {
					std::cout << "True" << std::endl;
				} else {
					std::cout << "False" << std::endl;
				}
			} else if (input.compare(PRINT) == 0) {
				hashmap->print();
			} else if (input.compare(SIZE) == 0) {
				std::cout << "size: " << hashmap->get_size() << std::endl;
			} else if (input.compare(CLEAR) == 0) {
				delete hashmap;
				hashmap = new HashMap<Integer, String>();
				std::cout << "Successfully cleared hashmap.\n" << std::endl;
			} else if (input.compare(HELP) == 0) {
				hashmap_help();
			} else {
				std::string err_msg = "Invalid input: " + input;
				throw BadInput(err_msg);
			}
		} catch (BadInput reenter_while_loop) {
			std::cout << reenter_while_loop.get_msg() << std::endl;
			std::cout << "Try your command again..." << std::endl;
		}
	}
}

Integer generate_integer_obj(std::string &str) {
	int num;
	remove_whitespace(str);
	if (!is_num(str, num)) {
		std::string err_msg = str + " cannot be converted to integer.";
		throw BadInput(err_msg);
	}
	Integer num_int(num);
	return num_int;
}

std::queue<Integer_String_Pair> parse_int_str_file(std::string &src) {
	if (!file_exists(src)) {
		std::string err_msg = "File does not exist. Try again.";
		throw BadInput(err_msg);
	}
	std::queue<Integer_String_Pair> int_str_pair_q;
	std::string line;
	std::ifstream rfile;
	rfile.open(src);
	if (rfile.is_open()) {
		while (std::getline(rfile, line) && line.length() != 0) {
			std::cout << std::endl;
			std::vector<std::string> tokens;
			std::stringstream checkl(line);
			std::string intermediate;
			while (std::getline(checkl, intermediate, ' ')) {
				std::cout << intermediate << " ";
				tokens.push_back(intermediate);
			}
			std::string str_tok1 = tokens.at(0);
			int num;
			if (!is_num(str_tok1, num)) {
				std::string err_msg = str_tok1 + " cannot be converted to int.";
				throw BadInput(err_msg);
			}
			Integer i(num);
			std::string str_tok2 = tokens.at(1);
			String str(str_tok2);
			Integer_String_Pair int_string_pair(i, str);
			int_str_pair_q.push(int_string_pair);
		}
		rfile.close();
	}
	std::cout << std::endl;
	return int_str_pair_q;
}

bool is_num(std::string &str, int &num) {
	for (int i = 0; i < str.size(); i++) {
		if (!isdigit(str[i]) && str[i] != ' ') {
			num = -1;
			return false;
		}
	}
	remove_whitespace(str);
	num = atoi(str.c_str());
	return true;
}

void remove_whitespace(std::string &str) {
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
}

void to_upper(std::string &str) {
	for (unsigned int l = 0; l < str.length(); l++) {
		str[l] = toupper(str[l]);
	}
}

bool file_exists(std::string &src) {
	std::ifstream f(src.c_str());
	return f.good();
}

void avl_help() {
	std::cout << "\nAVL VALID COMMANDS:" << std::endl;
	std::cout << "insert" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "\tprogram will ask for string value" << std::endl;
	std::cout << "remove" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "contains" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "get" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "print" << std::endl;
	std::cout << "\tprogram will ask for print type:" << std::endl;
	std::cout << "\t\tpreorder" << std::endl;
	std::cout << "\t\tpostorder" << std::endl;
	std::cout << "\t\tlevelorder" << std::endl;
	std::cout << "\t\tinorder" << std::endl;
	std::cout << "size" << std::endl;
	std::cout << "height" << std::endl;
	std::cout << "clear" << std::endl;
	std::cout << "return (return to main hub)" << std::endl;
	std::cout << "exit (exit program entirely)" << std::endl;
	std::cout << "help (will print these instructions)" << std::endl;
}

void hashmap_help() {
	std::cout << "\nHASHMAP VALID COMMANDS:" << std::endl;
	std::cout << "put" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "\tprogram will ask for string value" << std::endl;
	std::cout << "remove" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "get" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "contains" << std::endl;
	std::cout << "\tprogram will ask for integer key" << std::endl;
	std::cout << "size" << std::endl;
	std::cout << "clear" << std::endl;
	std::cout << "return (return to main hub)" << std::endl;
	std::cout << "exit (exit program entirely)" << std::endl;
	std::cout << "help (will print these instructions)" << std::endl;
}

Integer_String_Pair::Integer_String_Pair(Integer _integer, String _string) : integer(_integer), string(_string) {
}

BadInput::BadInput(std::string &msg) : msg(msg) {
}

std::string BadInput::get_msg() {
	return msg;
}

void leave_program() {
	system("clear");
	std::cout << "Hope you enjoyed using my Project 3 program! :)" << std::endl;
	exit(0);
}
