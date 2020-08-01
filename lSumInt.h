# ifndef LSUMINT_H
# define LSUMINT_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A class that generates Bounded sum list of integers test cases
class Rlsumint
{
	int n;
	fstream fout;
	default_random_engine generator;
public:
	Rlsumint();
	void generate(int, int);
	void setCase(string&, int, int, int, int, int, string&);
};

# endif