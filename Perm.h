# ifndef PERM_H
# define PERM_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A class that generates permutation test cases
class Rperm
{
	int N;
	vector <int> g;
	fstream fout;
	default_random_engine generator;
public:
	Rperm();
	void generate(int, Timer&);
	void setCase(string&, int, int, int, int, string&);
};

# endif
