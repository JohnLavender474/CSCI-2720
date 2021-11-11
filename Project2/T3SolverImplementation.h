#pragma once

#include "NaryTree.h"

class Print
		: public Apply<NaryNode<std::string> *>
{
	void apply(NaryNode<std::string> *t) override;
};

class InvalidSerializedGameBoard
		: public std::exception
{
public:
	const std::string exception() const throw()
	{
		std::string err_msg_ln1 = "Invalid serialized game board string!\n";
		std::string err_msg_ln2 = "Must be exactly 9 chars.\n";
		std::string err_msg_ln3 = "Must contain only *'s, X's, and O's.\n";
		std::string err_msg_ln4 = "Num of O's must be equal to or one less than num of X's.\n";
		std::string err_msg_ln5 = "Input game board must NOT already have a winner.\n";
		std::string err_msg_ln6 = "For example, this exception is thrown if the following\n";
		std::string err_msg_ln7 = "is entered: '*O*XXX*O*'.\n";
		return err_msg_ln1 + err_msg_ln2 + err_msg_ln3 + err_msg_ln4 + err_msg_ln5 + err_msg_ln6 + err_msg_ln7;
	}
};

class T3SolverImplementation
{
public:
	T3SolverImplementation() = delete;
	
	T3SolverImplementation(std::string serialized_game_board);
	
	~T3SolverImplementation();
	
	void print_levelorder();
	
	void print_preorder();
	
	void print_postorder();
	
	void print_linked_inversion(std::string order);
	
	void print_random_branch();
	
	void solve(bool print_loading_status);
	
	void results();
	
	void print_game_board(std::string serialized_game_board);
	
	void play_against_computer(char player);
	
	static bool is_winner(std::string game_board, char character);
	
	static char whose_turn(std::string game_board);
	
	static int count(std::string game_board, char character);
	
	static const char X = 'X';
	static const char O = 'O';
	static const char BLANK = '*';
	static const int PLAYER_VAL = -1;
	static const int BLANK_VAL = 0;
	static const int COMPUTER_VAL = 1;
private:
	std::string root_game_board;
	NaryTree<std::string> *game_tree;
	int x_num_wins;
	int o_num_wins;
	int num_draws;
	Print print;
	int size;
	
	int minimax(std::string serialize_game_board, int depth);
	
	int ai_get_best_move(std::string serialized_game_board);
	
	char player;
	char computer;
};




