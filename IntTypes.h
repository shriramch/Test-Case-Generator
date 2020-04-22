# ifndef INTTYPES_H
# define INTTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A class that generates integer test cases
class Rint
{
	int n;
	fstream fout;
	default_random_engine generator;
public:
	Rint();
	void generate(int, int);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates pair test cases
class Rpair
{
	int a, b;
	fstream fout;
	default_random_engine generator;
public:
	Rpair();
	void generate(int, int);
	void setCase(string&, int, int, int, int, string&);
};

# endif