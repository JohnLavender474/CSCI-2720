#include "T3SolverImplementation.h"

/* ========================================================================================================== */
/* CONSTRUCTOR */
/* ========================================================================================================== */
T3SolverImplementation::T3SolverImplementation(std::string root_game_board) try :
		game_tree(new NaryTree<std::string>), size(0)
{
	if (root_game_board.size() != 9)
	{
		throw InvalidSerializedGameBoard();
	}
	for (char & c : root_game_board)
	{
		if (c != 'X' && c != 'O' && c != '*')
		{
			throw InvalidSerializedGameBoard();
		}
	}
	if (this->count(root_game_board, O) > this->count(root_game_board, X) ||
			this->count(root_game_board, O) < this->count(root_game_board, X) - 1)
	{
		throw InvalidSerializedGameBoard();
	}
	if (this->is_winner(root_game_board, X) || this->is_winner(root_game_board, O))
	{
		throw InvalidSerializedGameBoard();
	}
	this->root_game_board = root_game_board;
}
catch (InvalidSerializedGameBoard & e)
{
	std::cout << e.exception() << std::endl;
}

T3SolverImplementation::~T3SolverImplementation()
{
	delete game_tree;
}

/* ========================================================================================================== */
/* PRINT APPLY */
/* ========================================================================================================== */
void Print::apply(NaryNode<std::string> * t)
{
	std::cout << "  " << t->get_data();
	if (T3SolverImplementation::is_winner(t->get_data(), T3SolverImplementation::X))
	{
		std::cout << "  <--- X wins!";
	}
	else if (T3SolverImplementation::is_winner(t->get_data(), T3SolverImplementation::O))
	{
		std::cout << "  <--- O wins!";
	} else if (T3SolverImplementation::count(t->get_data(), T3SolverImplementation::BLANK) == 0)
	{
		std::cout << "  <--- draw!";
	}
	std::cout << std::endl;
}

/* ========================================================================================================== */
/* SOLVE */
/* ========================================================================================================== */
void T3SolverImplementation::solve(bool print_loading_status)
{
	this->game_tree->insert(
			this->root_game_board,
			this->count(root_game_board, BLANK));
	std::queue<std::string> q;
	q.push(this->root_game_board);
	while (!q.empty())
	{
		std::string next_game_board = q.front();
		q.pop();
		if (count(next_game_board, BLANK) == 0)
		{
			this->num_draws++;
			continue;
		}
		char character = this->whose_turn(next_game_board);
		for (int n = 0; n < next_game_board.size(); n++)
		{
			if (next_game_board.at(n) == BLANK)
			{
				std::string next_game_board_cpy = next_game_board;
				next_game_board_cpy.at(n) = character;
				if (this->is_winner(next_game_board_cpy, character))
				{
					character == this->X ? this->x_num_wins++ : this->o_num_wins++;
					game_tree->insert(
							next_game_board_cpy,0);
				}
				else
				{
					q.push(next_game_board_cpy);
					game_tree->insert(
							next_game_board_cpy,
							count(next_game_board_cpy, BLANK));
				}
				size++;
				if (print_loading_status)
				{
					system("clear");
					std::cout << "loading tic-tac-toe nodes..." << std::endl;
					std::cout << "nodes loaded so far: " << this->size << std::endl;
				}
			}
		}
	}
}

bool T3SolverImplementation::is_winner(std::string game_board, char character)
{
	for (int i = 0; i < game_board.size(); i += 3)
	{
		if (game_board.at(i) == character &&
		    game_board.at(i + 1) == character &&
		    game_board.at(i + 2) == character)
		{
			return true;
		}
	}
	for (int i = 0; i < 3; i += 1)
	{
		if (game_board.at(i) == character &&
		    game_board.at(i + 3) == character &&
		    game_board.at(i + 6) == character)
		{
			return true;
		}
	}
	if (game_board.at(0) == character &&
	    game_board.at(4) == character &&
	    game_board.at(8) == character)
	{
		return true;
	}
	return game_board.at(2) == character &&
	       game_board.at(4) == character &&
	       game_board.at(6) == character;
}

/* ========================================================================================================== */
/* WHOSE TURN */
/* ========================================================================================================== */
char T3SolverImplementation::whose_turn(std::string game_board)
{
	return count(game_board, BLANK) % 2 == 0 ? O : X;
}

/* ========================================================================================================== */
/* WHO WON */
/* ========================================================================================================== */
void T3SolverImplementation::results()
{
	if (x_num_wins == 0 && o_num_wins == 0 && num_draws == 0)
	{
		throw std::invalid_argument("you must call solve() before calling results()");
	}
	std::cout << std::endl;
	std::cout << "size: " << game_tree->get_size() << std::endl;
	std::cout << "num wins for X: " << this->x_num_wins << std::endl;
	std::cout << "num wins for O: " << this->o_num_wins << std::endl;
	std::cout << "num draws: " << this->num_draws << std::endl;
}

/* ========================================================================================================== */
/* COUNT */
/* ========================================================================================================== */
int T3SolverImplementation::count(std::string game_board, char character)
{
	return std::count(game_board.begin(), game_board.end(), character);
}

/* ========================================================================================================== */
/* PRINT LEVEL ORDER */
/* ========================================================================================================== */
void T3SolverImplementation::print_levelorder()
{
	std::cout << std::endl;
	std::cout << "_____LEVEL ORDER_____" << std::endl;
	this->game_tree->levelorder_apply(print);
	std::cout << "\nsize: " << this->game_tree->get_size() << std::endl;
	std::cout << "_____________________" << std::endl;
}

/* ========================================================================================================== */
/* PRINT PRE ORDER */
/* ========================================================================================================== */
void T3SolverImplementation::print_preorder()
{
	std::cout << std::endl;
	std::cout << "_____PRE ORDER_____" << std::endl;
	this->game_tree->preorder_apply(print);
	std::cout << "\nsize: " << this->game_tree->get_size() << std::endl;
	std::cout << "___________________" << std::endl;
}

/* ========================================================================================================== */
/* PRINT POST ORDER */
/* ========================================================================================================== */
void T3SolverImplementation::print_postorder()
{
	std::cout << std::endl;
	std::cout << "_____POST ORDER_____" << std::endl;
	this->game_tree->postorder_apply(print);
	std::cout << "\nsize: " << this->game_tree->get_size() << std::endl;
	std::cout << "___________________" << std::endl;
}

/* ========================================================================================================== */
/* PRINT LINKED-INVERSION */
/* ========================================================================================================== */
void T3SolverImplementation::print_linked_inversion(std::string order)
{
	std::cout << std::endl;
	std::cout << "_____LINKED INVERSION: " << order << "_____" << std::endl;
	this->game_tree->linked_inversion_apply(print, order);
	std::cout << "\nsize: " << this->game_tree->get_size() << std::endl;
	std::cout << "___________________" << std::endl;
}

void T3SolverImplementation::print_random_branch()
{
	std::cout << std::endl;
	std::cout << "_____RANDOM BRANCH_____" << std::endl;
	this->game_tree->random_branch_apply(print);
	std::cout << "_______________________" << std::endl;
}

int T3SolverImplementation::minimax(std::string serialized_game_board, int depth)
{
	if (is_winner(serialized_game_board, player))
	{
		return PLAYER_VAL;
	}
	else if (is_winner(serialized_game_board, computer))
	{
		return COMPUTER_VAL;
	}
	else if (depth == 0)
	{
		return BLANK_VAL;
	}
	else if (this->count(serialized_game_board, BLANK) == 0)
	{
		return BLANK_VAL;
	}
	bool maximizing = this->whose_turn(serialized_game_board) == this->computer;
	int best_score = maximizing ? INT_MIN : INT_MAX;
	for (int i = 0; i < 9; i++)
	{
		if (serialized_game_board.at(i) == BLANK)
		{
			serialized_game_board.at(i) = maximizing ? this->computer : this->player;
			int score = this->minimax(serialized_game_board, depth - 1);
			serialized_game_board.at(i) = BLANK;
			best_score = maximizing ? std::max(best_score, score) : std::min(best_score, score);
		}
	}
	return best_score;
}

int T3SolverImplementation::ai_get_best_move(std::string serialized_game_board)
{
	int move;
	int best_score = INT_MIN;
	for (int i = 0; i < 9; i++)
	{
		if (serialized_game_board.at(i) == BLANK)
		{
			serialized_game_board.at(i) = this->computer;
			int score = this->minimax(serialized_game_board, 9);
			serialized_game_board.at(i) = BLANK;
			if (score > best_score)
			{
				best_score = score;
				move = i;
			}
		}
	}
	return move;
}

void T3SolverImplementation::play_against_computer(char _player)
{
	if (_player == X)
	{
		this->player = X;
		this->computer = O;
	}
	else
	{
		this->player = O;
		this->computer = X;
	}
	std::string serialized_game_board = this->root_game_board;
	std::cout << "\nSTARTING BOARD:" << std::endl;
	while (1)
	{
		this->print_game_board(serialized_game_board);
		if (this->is_winner(serialized_game_board, this->player))
		{
			std::cout << "\nPLAYER HAS WON!" << std::endl;
			break;
		}
		else if (this->is_winner(serialized_game_board, this->computer))
		{
			std::cout << "\nCOMPUTER HAS WON!" << std::endl;
			break;
		}
		else if (this->count(serialized_game_board, BLANK) == 0)
		{
			std::cout << "\nDRAW!" << std::endl;
			break;
		}
		if (this->whose_turn(serialized_game_board) == this->computer)
		{
			int move = this->ai_get_best_move(serialized_game_board);
			if (move < 0 || move > 8)
			{
				return;
			}
			serialized_game_board.at(move) = computer;
			std::cout << "COMPUTER HAS MADE A MOVE:" << std::endl;
		}
		else
		{
			std::string input = "";
			bool invalid_input = true;
			while (invalid_input)
			{
				std::cout << "Row: ";
				getline(std::cin, input);
				if (input.size() != 1)
				{
					std::cout << "Invalid input. Try again." << std::endl;
					continue;
				}
				if (!std::isdigit(input.at(0)))
				{
					std::cout << "Invalid input. Try again." << std::endl;
					continue;
				}
				int row = input.at(0) - '0';
				row--;
				if (row > 2 || row < 0)
				{
					std::cout << "Invalid input. Try again." << std::endl;
					continue;
				}
				std::cout << "Column: ";
				getline(std::cin, input);
				if (input.size() != 1)
				{
					std::cout << "Invalid input. Try again." << std::endl;
					continue;
				}
				if (!std::isdigit(input.at(0)))
				{
					std::cout << "Invalid input. Try again." << std::endl;
					continue;
				}
				int column = input.at(0) - '0';
				column--;
				if (column > 2 || column < 0)
				{
					std::cout << "Invalid input. Try again." << std::endl;
					continue;
				}
				int move = (3 * row) + column;
				if (serialized_game_board.at(move) != BLANK)
				{
					std::cout << "That position is already taken! Try again." << std::endl;
					continue;
				}
				serialized_game_board.at(move) = this->player;
				invalid_input = false;
				std::cout << "YOU'VE MADE YOUR MOVE:" << std::endl;
			}
		}
	}
}

void T3SolverImplementation::print_game_board(std::string serialized_game_board)
{
	std::cout << "\n    1 2 3" << std::endl;
	std::cout << "\n1   ";
	for (int i = 0; i < 3; i++)
	{
		std::cout << serialized_game_board.at(i) << " ";
	}
	std::cout << "\n2   ";
	for (int i = 3; i < 6; i++)
	{
		std::cout << serialized_game_board.at(i) << " ";
	}
	std::cout << "\n3   ";
	for (int i = 6; i < 9; i++)
	{
		std::cout << serialized_game_board.at(i) << " ";
	}
	std::cout << "\n" << std::endl;
}








