#include "T3Solver.h"

int main()
{
	T3Solver * t3Solver = new T3Solver("*O**X*OX*");
	t3Solver->solve(true);
	t3Solver->print_levelorder();
	t3Solver->print_preorder();
	t3Solver->print_postorder();
	delete t3Solver;
	return 0;
}
