#include <thread>

#include "T3SolverImplementation.h"

void program_loop(T3SolverImplementation *& t3SolverImplementation);
void printWelcome();
bool is_valid_serialized_game_board(std::string game_board);
std::string get_serialized_game_board();
void traversal(T3SolverImplementation *& t3SolverImplementation);
bool is_valid_traversal_input(std::string & traversal_input);
void play(T3SolverImplementation *& t3SolverImplementation);
void exit();

static const std::string _traversal = "traversal";
static const std::string _play = "play";
static const std::string _exit = "exit";
static const std::string _restart = "restart";
static const std::string _results = "results";
static const std::string _preorder = "preorder";
static const std::string _postorder = "postorder";
static const std::string _levelorder = "levelorder";
static const std::string _random_branch = "random branch";
static const std::string _linked_pre_order = "linked inversion preorder";
static const std::string _linked_post_order = "linked inversion postorder";

int main()
{
	T3SolverImplementation * t3SolverImplementation;
	program_loop(t3SolverImplementation);
	delete t3SolverImplementation;
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
			std::string input = "";
			while (1)
			{
				std::cout << "\nEnter 'traversal' or 'play': ";
				getline(std::cin, input);
				if (input.compare(_traversal) != 0 && input.compare(_play) != 0)
				{
					std::cout << "Invalid input. Please try again." << std::endl;
					continue;
				}
				else
				{
					break;
				}
			}
			if (input.compare(_traversal) == 0)
			{
				traversal(t3SolverImplementation);
			}
			else
			{
				play(t3SolverImplementation);
			}
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
	int x = 250;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tEnter a tic-tac-toe board and see all the possibilities!" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tWhen prompted, enter a valid serialized tic-tac-toe game board." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tThe serialization must contain exactly 9 chars consisting of only" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tX's, O's, and *'s. (X's and O's must be capitalized.)\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tYou may keep trying new game boards and traversals for as long as you like." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tEnter 'preorder', 'postorder', 'levelorder', " <<
				 "'linked inversion preorder', or 'linked inversion postorder'.\n" << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo view the results of your input, enter 'results'." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo view a random branch beginning from the root, enter 'random branch'." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo go back to the beginning prompt, enter 'restart'." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo play against the computer using the board you've entered, enter 'play'." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << "\tTo exit the program, enter 'exit'." << std::endl;
	std::this_thread::sleep_for(std::chrono::milliseconds(x));
	std::cout << std::endl;
}

bool is_valid_serialized_game_board(std::string game_board)
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
		std::cout << "\nEnter a valid serialized game board: ";
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
	while (1)
	{
		std::cout << "\nValid inputs: " << std::endl;
		std::cout << "\tpreorder\n\tpostorder\n\tlevelorder\n\tlinked inversion preorder" <<
					 "\n\tlinked inversion postorder\n\trandom branch\n\tresults\n\trestart\n\texit" << std::endl;
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
			else if (input.compare(_random_branch) == 0)
			{
				t3SolverImplementation->print_random_branch();
			}
		}
		else
		{
			std::cout << "Invalid input. Please try again." << std::endl;
		}
	}
}

bool is_valid_traversal_input(std::string & traversal_input)
{
	return traversal_input.compare(_preorder) == 0
	|| traversal_input.compare(_postorder) == 0
	|| traversal_input.compare(_levelorder) == 0
	|| traversal_input.compare(_linked_pre_order) == 0
	|| traversal_input.compare(_linked_post_order) == 0
	|| traversal_input.compare(_random_branch) == 0;
}

void play(T3SolverImplementation *& t3SolverImplementation)
{
	system("clear");
	std::string input = "";
	while (1)
	{
		std::cout << "Will you play as 'X' or 'O'? ";
		getline(std::cin, input);
		if (input.at(0) != 'X' && input.at(0) != 'O')
		{
			std::cout << "Invalid input. Try again." << std::endl;
			continue;
		}
		else
		{
			t3SolverImplementation->play_against_computer(input.at(0));
			break;
		}
	}
}

void exit()
{
	system("clear");
	std::cout << "Thank you for trying out T3Solver!" << std::endl;
	exit(0);
}