# ifndef SPSTRING_H
# define SPSTRING_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A function that generates long integer test cases
class Rlint
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	Rlint();
	void generate(int, Timer&);
	void setCase(string&, int, int, int, int, int, string&);
};

// A class that generates bracket sequence test cases
class Rrbseq
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	Rrbseq();
	void generate(int, Timer&);
	void setCase(string&, int, int, int, int, int, string&);
};

# endif