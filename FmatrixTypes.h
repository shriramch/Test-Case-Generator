# ifndef FMATRIXTYPES_H
# define FMATRIXTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A function that generates floating point matrix test case files
class Rfmatrix
{
	vector <int> N, M;
	float g;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	Rfmatrix();
	void generate(int, int, int, Timer&, float, float);
	void setCase(string&, int, int, int, int, int, float, float, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

// A class that generates floating point square matrix test cases
class Rsqfmatrix
{
	vector <int> N;
	float g;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	Rsqfmatrix();
	void generate(int, int, int, Timer&, float, float);
	void setCase(string&, int, int, int, float, float, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

# endif