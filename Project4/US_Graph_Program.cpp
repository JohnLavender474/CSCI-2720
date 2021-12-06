#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Graph.h"
#include "US_States.h"

bool shortest_path(std::string &err_msg);

bool contiguity_list(std::string &err_msg);

bool contiguity_count(std::string &err_msg);

bool matches_contiguity_count(std::string &err_msg);

bool shortest_path_tree(std::string &err_msg);

bool highest_contiguity(std::string &err_msg);

void load_states();

bool convert_to_int_command(std::string &input, int &i, std::string &err_msg);

bool state_prompt(std::string &state);

bool is_valid_state(std::string &state);

void to_upper(std::string &str);

bool is_num(std::string &str, int &num);

void remove_whitespace(std::string &str);

void print_help();

void print_welcome();

void exit_program();

Graph<std::string> us_states_graph;

const int EXIT = 0;
const int HELP = 1;
const int CLEAR = 2;
const int CONT_LIST = 3;
const int CONT_COUNT = 4;
const int MATCHES_CONT_COUNT = 5;
const int HIGHEST_CONT_COUNT = 6;
const int SHORTEST_PATH = 7;
const int SHORTEST_PATH_TREE = 8;

int main()
{
	load_states();
	print_welcome();
	print_help();
	while (true)
	{
		std::cout << std::endl;
		std::string input;
		std::cout << "Command: ";
		getline(std::cin, input);
		std::cout << std::endl;
		int i;
		std::string err_msg;
		bool success = convert_to_int_command(input, i, err_msg);
		if (success)
		{
			switch (i)
			{
				case EXIT:
					exit_program();
					break;
				case HELP:
					print_help();
					break;
				case CLEAR:
					system("clear");
					break;
				case CONT_LIST:
					success = contiguity_list(err_msg);
					break;
				case CONT_COUNT:
					success = contiguity_count(err_msg);
					break;
				case MATCHES_CONT_COUNT:
					success = matches_contiguity_count(err_msg);
					break;
				case HIGHEST_CONT_COUNT:
					success = highest_contiguity(err_msg);
					break;
				case SHORTEST_PATH:
					success = shortest_path(err_msg);
					break;
				case SHORTEST_PATH_TREE:
					success = shortest_path_tree(err_msg);
					break;
			}
		}
		if (!success)
		{
			std::cout <<  "error!" << std::endl;
			std::cout << err_msg << std::endl;
		}
	}
}

bool shortest_path(std::string &err_msg)
{
	std::cout << "prompt for entering start state..." << std::endl;
	std::string start_state;
	if (state_prompt(start_state))
	{
		if (start_state == HI || start_state == AK)
		{
			std::cout << "no viable paths for Hawaii or Alaska" << std::endl;
			return true;
		}
		std::cout << "prompt for entering end state..." << std::endl;
		std::string end_state;
		if (state_prompt(end_state))
		{
			if (start_state == HI || start_state == AK)
			{
				std::cout << "no viable paths for Hawaii or Alaska" << std::endl;
				return true;
			}
			std::vector<std::string> path = us_states_graph.shortest_path(start_state, end_state);
			if (!path.empty())
			{
				for (auto it = path.rbegin();
				it != path.rend();)
				{
					std::cout << '\t' << *it;
					if (++it != path.rend())
					{
						std::cout << " -->";
					}
					std::cout << std::endl;
				}
			}
			else
			{
				std::cout << "no viable path found" << std::endl;
			}
			return true;
		}
		else
		{
			err_msg = "not a valid state: " + end_state;
			return false;
		}
	}
	else
	{
		err_msg = "not a valid state: " + start_state;
		return false;
	}
}

bool shortest_path_tree(std::string &err_msg)
{
	std::string state;
	if (state_prompt(state))
	{
		if (state == HI || state == AK)
		{
			std::cout << "no viable path tree for Hawaii or Alaska" << std::endl;
			return true;
		}
		std::vector<std::vector<std::string>> path_tree = us_states_graph.shortest_path_tree(state);
		int index = 1;
		for (const std::vector<std::string> &vec : path_tree)
		{
			std::cout << "PATH " << index << std::endl;
			++index;
			if (!vec.empty())
			{
				for (auto it = vec.rbegin();
				it != vec.rend();)
				{
					std::cout << '\t' << *it;
					if (++it != vec.rend())
					{
						std::cout << " -->";
					}
					std::cout << std::endl;
				}
			}
			else
			{
				std::cout << "no viable path found" << std::endl;
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

bool contiguity_list(std::string &err_msg)
{
	std::string state;
	if (state_prompt(state))
	{
		std::vector<std::string> cont_states;
		if (us_states_graph.edges(state, cont_states))
		{
			std::cout << "\nCONTIGUOUS STATES:" << std::endl;
			for (const std::string &s : cont_states)
			{
				std::cout << '\t' << s << std::endl;
			}
			return true;
		}
		else
		{
			err_msg = "us_states_graph does not contain vertex info: " + state + " (this is not a user error)";
			return false;
		}
	}
	else
	{
		err_msg = "invalid state input";
		return false;
	}
}

bool contiguity_count(std::string &err_msg)
{
	std::string state;
	if (state_prompt(state))
	{
		int cont_count = us_states_graph.edge_count(state);
		std::cout << "\nNUMBER OF STATES CONTIGUOUS TO " << state << ": "<< cont_count << std::endl;
		return true;
	}
	else
	{
		err_msg = "not a valid state: " + state;
		return false;
	}
}

bool matches_contiguity_count(std::string &err_msg)
{
	std::cout << "enter int: ";
	std::string count;
	getline(std::cin, count);
	std::cout << std::endl;
	int c;
	if (is_num(count, c))
	{
		std::map<std::string, std::vector<std::string>> matches;
		us_states_graph.for_each([&matches, &c](const std::string &v, const std::vector<std::string> &edges)
		{
			if (c == edges.size())
			{
				std::cout << "VERTEX: " << v << std::endl;
				for (int i = 0; i < edges.size(); i++)
				{
					std::cout << "\tEDGE " << i + 1 << ": " << edges.at(i) << std::endl;
				}
			}
		});
		return true;
	}
	else
	{
		err_msg = "is not an integer: " + std::to_string(c);
		return false;
	}
}

bool highest_contiguity(std::string &err_msg)
{
	std::string state;
	std::vector<std::string> cont_vec;
	if (us_states_graph.highest_edge_count(state, cont_vec))
	{
		std::cout << "\nSTATE WITH HIGHEST CONTIGUITY: " << state << std::endl;
		for (const std::string &s : cont_vec)
		{
			std::cout << '\t' << s << std::endl;
		}
		return true;
	}
	err_msg = "us_states_graph failed to properly load (this is not a user error)";
	return false;
}

bool state_prompt(std::string &state)
{
	std::cout << "enter state (abbreviation): ";
	std::getline(std::cin, state);
	std::cout << std::endl;
	return is_valid_state(state);
}

bool is_valid_state(std::string &state)
{
	to_upper(state);
	remove_whitespace(state);
	return us_state_adjacencies.count(state);
}

bool convert_to_int_command(std::string &input, int &i, std::string &err_msg)
{
	remove_whitespace(input);
	if (input.length() != 1)
	{
		err_msg = "command input must be a single int";
		return false;
	}
	char c = input[0];
	if (!std::isdigit(c))
	{
		err_msg = "command input must be a single int";
		return false;
	}
	i = c - '0';
	if (i > 8)
	{
		err_msg = "command input int must be between 0 and 6";
		return false;
	}
	return true;
}

bool is_num(std::string &str, int &num)
{
	for (int i = 0;
	i < str.size();
	i++)
	{
		if (!isdigit(str[i]) && str[i] != ' ')
		{
			num = -1;
			return false;
		}
	}
	remove_whitespace(str);
	num = atoi(str.c_str());
	return true;
}

void to_upper(std::string &str)
{
	for (int i = 0; i < str.length(); i++)
	{
		str[i] = toupper(str[i]);
	}
}

void remove_whitespace(std::string &str)
{
	std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
	str.erase(end_pos, str.end());
}

void print_help()
{
	std::cout << "\nStates must be entered using their respective abbreviations." << std::endl;
	std::cout << "Case-insensitive, e.g. GA, fL, aL, Ny, wa, etc." << std::endl;
	std::cout << "When prompted for a command, enter the number that coresponds" << std::endl;
	std::cout << "to the command that you are interested in performing.\n" << std::endl;
	std::cout << "\nAvailable commands:" << std::endl;
	std::cout << '\t' << EXIT << ". exit this program" << std::endl;
	std::cout << '\t' << HELP << ". print help (prints this list of commands" << std::endl;
	std::cout << '\t' << CLEAR << ". clear the screen" << std::endl;
	std::cout << '\t' << CONT_LIST << ". find the list of contiguous states of a state" << std::endl;
	std::cout << '\t' << CONT_COUNT << ". find the contiguity count of a state" << std::endl;
	std::cout << '\t' << MATCHES_CONT_COUNT << ". find the states that have a continuity count "
											   "equal to your input" << std::endl;
	std::cout << '\t' << HIGHEST_CONT_COUNT << ". find the state with the highest contiguity count" << std::endl;
	std::cout << '\t' << SHORTEST_PATH << ". find the shortest path from one state to another" << std::endl;
	std::cout << '\t' << SHORTEST_PATH_TREE << ". print the shortest path tree of a particular state\n" << std::endl;
}

void print_welcome()
{
	std::cout << "\nWELCOME TO MY UNITED STATES GRAPH PROGRAM!" << std::endl;
	std::cout << "This program uses an undirected, unweighted graph to represent" << std::endl;
	std::cout << "state adjacencies in the United States. Enjoy!\n" << std::endl;
}

void exit_program()
{
	
	system("clear");
	std::cout << "Thank you for using my program. :)" << std::endl;
	exit(0);
}

void load_states()
{
	for (auto it = us_state_adjacencies.begin();
	it != us_state_adjacencies.end();
	++it)
	{
		us_states_graph.add_vertex(it->first);
	}
	for (auto it = us_state_adjacencies.begin();
	it != us_state_adjacencies.end();
	++it)
	{
		for (const std::string &cont : it->second)
		{
			us_states_graph.put_edge(it->first, cont);
		}
	}
}
