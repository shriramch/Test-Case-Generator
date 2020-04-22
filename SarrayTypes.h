# ifndef SARRAYTYPES_H
# define SARRAYTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates sorted array test cases
class Rsarray
{
	int N, rn;
	vector <int> g;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	Rsarray();
	void generate(int, int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

// A class that generates sorted array of distinct elements test cases
class Rsdarray
{
	int N;
	set <int> g;
	fstream fout;
	default_random_engine generator;
public:
	Rsdarray();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

# endif
