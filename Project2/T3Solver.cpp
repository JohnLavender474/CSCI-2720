#include "T3Solver.h"

/* ========================================================================================================== */
/* CONSTRUCTOR */
/* ========================================================================================================== */
T3Solver::T3Solver(std::string serialized_game_board) try :
		game_tree(new NaryTree<std::string>)
{
	if (serialized_game_board.size() != 9)
	{
		throw InvalidSerializedGameBoard();
	}
	for (char & c : serialized_game_board)
	{
		if (c != 'X' && c != 'O' && c != '*')
		{
			throw InvalidSerializedGameBoard();
		}
	}
	std::queue<std::string> q;
	q.push(serialized_game_board);
	this->solve(q);
}
catch (InvalidSerializedGameBoard & e)
{
	std::cout << e.exception() << std::endl;
}

/* ========================================================================================================== */
/* PRINT APPLY */
/* ========================================================================================================== */
void Print::apply(NaryNode<std::string> * t)
{
	std::cout << t->get_data() << std::endl;
}

/* ========================================================================================================== */
/* SOLVE */
/* ========================================================================================================== */
void T3Solver::solve(std::queue<std::string> q)
{
	while (!q.empty())
	{
		std::string serialized_game_board = q.front();
		q.pop();
		if (count(serialized_game_board, BLANK) == 0)
		{
			continue;
		}
		char player = this->whose_turn(serialized_game_board);
		for (size_t n = 0; n < serialized_game_board.size(); n++)
		{
			if (serialized_game_board.at(n) == BLANK)
			{
				std::string serialized_game_board_cpy = serialized_game_board;
				serialized_game_board_cpy.at(n) = player;
				game_tree->insert(
						serialized_game_board_cpy,
						count(serialized_game_board_cpy, BLANK));
				q.push(serialized_game_board_cpy);
			}
		}
	}
}

/* ========================================================================================================== */
/* WHOSE TURN */
/* ========================================================================================================== */
char T3Solver::whose_turn(std::string serialized_game_board)
{
	return this->count(serialized_game_board, BLANK) % 2 == 0 ? O : X;
}

/* ========================================================================================================== */
/* COUNT */
/* ========================================================================================================== */
size_t T3Solver::count(std::string serialized_game_board, char character)
{
	return std::count(serialized_game_board.begin(), serialized_game_board.end(), character);
}

/* ========================================================================================================== */
/* PRINT LEVEL ORDER */
/* ========================================================================================================== */
void T3Solver::print_levelorder()
{
	this->game_tree->levelorder_apply(print);
}

/* ========================================================================================================== */
/* PRINT PRE ORDER */
/* ========================================================================================================== */
void T3Solver::print_preorder()
{
	this->game_tree->preorder_apply(print);
}

/* ========================================================================================================== */
/* PRINT POST ORDER */
/* ========================================================================================================== */
void T3Solver::print_postorder()
{
	this->game_tree->postorder_apply(print);
}


