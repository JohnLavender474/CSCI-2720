#include "T3Solver.h"

using namespace std;

int main()
{
	T3Solver * t3Solver = new T3Solver("*OX*XOOX*");
	t3Solver->solve(true);
	t3Solver->print_levelorder();
	t3Solver->print_preorder();
	t3Solver->print_postorder();
	t3Solver->print_linked_inversion("preorder");
	delete t3Solver;
	return 0;
}
