#include "T3Solver.h"

/* ========================================================================================================== */
/* CONSTRUCTOR */
/* ========================================================================================================== */
T3Solver::T3Solver(std::string root_game_board) try :
		game_tree(new NaryTree<std::string>)
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
	this->root_game_board = root_game_board;
}
catch (InvalidSerializedGameBoard & e)
{
	std::cout << e.exception() << std::endl;
}

T3Solver::~T3Solver()
{
	delete game_tree;
}

/* ========================================================================================================== */
/* PRINT APPLY */
/* ========================================================================================================== */
void Print::apply(NaryNode<std::string> * t)
{
	std::cout << "  " << t->get_data();
	if (T3Solver::is_winner(t->get_data(), T3Solver::X))
	{
		std::cout << "  <--- X wins!";
	}
	else if (T3Solver::is_winner(t->get_data(), T3Solver::O))
	{
		std::cout << "  <--- O wins!";
	} else if (T3Solver::count(t->get_data(), T3Solver::BLANK) == 0)
	{
		std::cout << "  <--- draw!";
	}
	std::cout << std::endl;
}

/* ========================================================================================================== */
/* SOLVE */
/* ========================================================================================================== */
void T3Solver::solve(bool print_loading_status)
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
		for (size_t n = 0; n < next_game_board.size(); n++)
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

bool T3Solver::is_winner(std::string game_board, char character)
{
	for (size_t i = 0; i < game_board.size(); i += 3)
	{
		if (game_board.at(i) == character &&
		    game_board.at(i + 1) == character &&
		    game_board.at(i + 2) == character)
		{
			return true;
		}
	}
	for (size_t i = 0; i < 3; i += 1)
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
char T3Solver::whose_turn(std::string game_board)
{
	return count(game_board, BLANK) % 2 == 0 ? O : X;
}

/* ========================================================================================================== */
/* WHO WON */
/* ========================================================================================================== */
void T3Solver::results()
{
	if (x_num_wins == 0 && o_num_wins == 0 && num_draws == 0)
	{
		throw std::invalid_argument("you must call solve() before calling results()");
	}
	std::cout << std::endl;
	std::cout << "num wins for X: " << x_num_wins << std::endl;
	std::cout << "num wins for O: " << o_num_wins << std::endl;
	std::cout << "num draws: " << num_draws << std::endl;
}

/* ========================================================================================================== */
/* COUNT */
/* ========================================================================================================== */
size_t T3Solver::count(std::string game_board, char character)
{
	return std::count(game_board.begin(), game_board.end(), character);
}

/* ========================================================================================================== */
/* PRINT LEVEL ORDER */
/* ========================================================================================================== */
void T3Solver::print_levelorder()
{
	std::cout << std::endl;
	std::cout << "_____LEVEL ORDER_____" << std::endl;
	this->game_tree->levelorder_apply(print);
	std::cout << "_____________________" << std::endl;
}

/* ========================================================================================================== */
/* PRINT PRE ORDER */
/* ========================================================================================================== */
void T3Solver::print_preorder()
{
	std::cout << std::endl;
	std::cout << "_____PRE ORDER_____" << std::endl;
	this->game_tree->preorder_apply(print);
	std::cout << "___________________" << std::endl;
}

/* ========================================================================================================== */
/* PRINT POST ORDER */
/* ========================================================================================================== */
void T3Solver::print_postorder()
{
	std::cout << std::endl;
	std::cout << "_____POST ORDER_____" << std::endl;
	this->game_tree->postorder_apply(print);
	std::cout << "___________________" << std::endl;
}






