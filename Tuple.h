# ifndef TUPLE_H
# define TUPLE_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates tuples
class Rtuple
{
	int g;
	fstream fout;
	default_random_engine generator;
public:
	Rtuple();
	void generate(int, vector <int> &, vector <int> &, Timer &);
	void setCase(string &, int, int, int, vector <int> &, vector <int> &, string &);
};

// A class that generates tuple array test cases
class RtupleArray
{
	int g;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	RtupleArray();
	void generate(vector <int> &, int, int, Timer&, int, int);
	void setCase(string&, int, int, int, int, vector <int> &, vector <int> &, int, int, string&);
	int setCaseDist(int, int, bool);
};

# endif