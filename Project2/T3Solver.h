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
	void print_levelorder();
	void print_preorder();
	void print_postorder();
private:
	void solve(std::queue<std::string> q);
	char whose_turn(std::string serialized_game_board);
	size_t count(std::string serialized_game_board, char character);
	NaryTree<std::string> * game_tree;
	static const char X = 'X';
	static const char O = 'O';
	static const char BLANK = '*';
	static Print print;
};




