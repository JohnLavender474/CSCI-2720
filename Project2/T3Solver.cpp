#include <thread>

#include "T3SolverImplementation.h"

void program_loop(T3SolverImplementation *& t3SolverImplementation);
void printWelcome();
bool is_valid_serialized_game_board(std::string & game_board);
std::string get_serialized_game_board();
void traversal(T3SolverImplementation *& t3Solver);
bool is_valid_traversal_input(std::string & traversal_input);
void exit();

static const std::string _exit = "exit";
static const std::string _restart = "restart";
static const std::string _results = "results";
static const std::string _preorder = "preorder";
static const std::string _postorder = "postorder";
static const std::string _levelorder = "levelorder";
static const std::string _linked_pre_order = "linked preorder";
static const std::string _linked_post_order = "linked postorder";

int main()
{
	T3SolverImplementation * t3SolverImplementation;
	program_loop(t3SolverImplementation);
	return 0;
}

void program_loop(T3SolverImplementation *& t3SolverImplementation)
{
	printWelcome();
	while (1)
	{
		try
		{
			std::string serialized_game_board = get_serialized_game_board();
			if (serialized_game_board.compare(_restart) == 0)
			{
				continue;
			}
			t3SolverImplementation = new T3SolverImplementation(serialized_game_board);
			t3SolverImplementation->solve(true);
			traversal(t3SolverImplementation);
		}
		catch (InvalidSerializedGameBoard isgb)
		{
			continue;
		}
	}
}

void printWelcome()
{
	system("clear");
	std::cout << "\n\tWELCOME TO T3_SOLVER!\n" << std::endl;
	int x = 400;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tThis program will show you ALL the possibilties of any tic-tac-toe game!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tAll of the possibilities will be stored within a traversable game tree." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tThe game tree may be traversed via preorder, postorder, and levelorder.\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tIf a speedier traversal is desired, then consider trying out" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tthe LINKED INVERSION traversal option!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tPreorder and postorder traversals are supported by the linked inversion option.\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tWhen prompted, enter a valid serialized tic-tac-toe game board." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tThe serialization must contain exactly 9 chars consisting of only" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tX's, O's, and *'s. (X's and O's must be capitalized.)" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tAfter that, you will be prompted to specify which traversal you'd like" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tto have performed on the game board.\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tYou may keep trying new game boards and traversals for as long as you like." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tEnter 'preorder', 'postorder', or 'levelorder' when prompted for traversal," << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tor enter 'linked preorder' or 'linked postorder' for linked inversion traversal.\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo view the results of your input, enter 'results'." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo go back to the beginning prompt, simply enter 'restart' into any prompt.\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo exit the program, enter 'exit' into any prompt." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << std::endl;
}

bool is_valid_serialized_game_board(std::string & game_board)
{
	if (game_board.size() != 9)
	{
		return false;
	}
	for (char & character : game_board)
	{
		if (character != 'X' && character != 'O' && character != '*')
		{
			return false;
		}
	}
	return true;
}

std::string get_serialized_game_board()
{
	std::string input = "";
	do
	{
		std::cout << "Enter a valid serialized game board: ";
		getline(std::cin, input);
		if (input.compare(_exit) == 0)
		{
			exit();
		}
		if (input.compare(_restart) == 0)
		{
			return _restart;
		}
		if (!is_valid_serialized_game_board(input) &&
		    input.compare(_exit) != 0 &&
		    input.compare(_restart) != 0)
		{
			std::cout << "That is not a valid input. Please try again." << std::endl;
		}
	} while (!(is_valid_serialized_game_board(input)));
	system("clear");
	return input;
}

void traversal(T3SolverImplementation *& t3SolverImplementation)
{
	std::string input = "";
	do
	{
		std::cout << std::endl;
		std::cout << "Enter traversal type: ";
		getline(std::cin, input);
		if (input.compare(_exit) == 0)
		{
			exit();
		}
		else if (input.compare(_restart) == 0)
		{
			return;
		}
		else if (input.compare(_results) == 0)
		{
			t3SolverImplementation->results();
		}
		else if (is_valid_traversal_input(input))
		{
			if (input.compare(_preorder) == 0)
			{
				t3SolverImplementation->print_preorder();
			}
			else if (input.compare(_postorder) == 0)
			{
				t3SolverImplementation->print_postorder();
			}
			else if (input.compare(_levelorder) == 0)
			{
				t3SolverImplementation->print_levelorder();
			}
			else if (input.compare(_linked_pre_order) == 0)
			{
				t3SolverImplementation->print_linked_inversion("preorder");
			}
			else if (input.compare(_linked_post_order) == 0)
			{
				t3SolverImplementation->print_linked_inversion("postorder");
			}
		}
		else
		{
			std::cout << "Invalid input. Please try again." << std::endl;
		}
	} while (true);
}

bool is_valid_traversal_input(std::string & traversal_input)
{
	return traversal_input.compare(_preorder) == 0
	|| traversal_input.compare(_postorder) == 0
	|| traversal_input.compare(_levelorder) == 0
	|| traversal_input.compare(_linked_pre_order) == 0
	|| traversal_input.compare(_linked_post_order) == 0;
}

void exit()
{
	system("clear");
	std::cout << "Thank you for trying out T3Solver!" << std::endl;
	exit(0);
}