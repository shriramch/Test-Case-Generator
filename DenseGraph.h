# ifndef DENSEGRAPH_H
# define DENSEGRAPH_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A function that generates dense graph test cases
class Rdensegraph
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	Rdensegraph();
	void generate(int, Timer&, int, float);
	void setCase(string&, int, int, int, float, int, int, string&);
};

// A class that generates dense digraph test cases
class Rdensedgraph
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	Rdensedgraph();
	void generate(int, Timer&, int, float);
	void setCase(string&, int, int, int, float, int, int, string&);
};

# endif