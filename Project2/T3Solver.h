#pragma once

#include "NaryTree.h"

class Print : public Apply<NaryNode<std::string> *>
{
	void apply(NaryNode<std::string> * t) override;
};

class InvalidSerializedGameBoard : public std::exception
{
public:
	const char * exception() const throw ()
	{
		return "Invalid serialized game board string! Must be exactly 9 chars. Must contain only *, X, and O.";
	}
};

class T3Solver
{
public:
	T3Solver() = delete;
	T3Solver(std::string serialized_game_board);
	~T3Solver();
	void print_levelorder();
	void print_preorder();
	void print_postorder();
	void print_linked_inversion(std::string order);
	void solve(bool print_loading_status);
	void results();
	static bool is_winner(std::string game_board, char character);
	static char whose_turn(std::string game_board);
	static int count(std::string game_board, char character);
	static const char X = 'X';
	static const char O = 'O';
	static const char BLANK = '*';
private:
	std::string root_game_board;
	NaryTree<std::string> * game_tree;
	int x_num_wins;
	int o_num_wins;
	int num_draws;
	Print print;
	int size;
};




