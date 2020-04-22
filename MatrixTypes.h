# ifndef MATRIXTYPES_H
# define MATRIXTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates matrices
class Rmatrix
{
	vector <int> N, M;
	int g;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	Rmatrix();
	void generate(int, int, int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, int, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

// A class that generates square matrix test cases
class Rsqmatrix
{
	vector <int> N;
	int g;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	Rsqmatrix();
	void generate(int, int, int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};


# endif