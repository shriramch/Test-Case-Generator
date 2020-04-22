# ifndef INTERVALTYPES_H
# define INTERVALTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"


// A class that generates interval test cases
class Rintervals
{
	int a, b;
	fstream fout;
	default_random_engine generator;
public:
	Rintervals();
	void generate(int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A function that generates unique intervals
class Ruintervals
{
	int N;
	set <int> g;
	fstream fout;
	default_random_engine generator;
public:
	Ruintervals();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates partition test cases
class Rpartition
{
	int N;
	set <int> g;
	fstream fout;
	default_random_engine generator;
public:
	Rpartition();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, string&);
};

# endif