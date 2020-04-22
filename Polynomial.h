# ifndef POLYNOMIAL_H
# define POLYNOMIAL_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A class that generates polynomial test cases
class Rpolynomial
{
	int N, d;
	fstream fout;
	map <int, int> m;
	default_random_engine generator;
public:
	Rpolynomial();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, int, string&);
};

// A class that generates floating point polynomials
class Rfpolynomial
{
	int N, d;
	fstream fout;
	map <int, float> m;
	default_random_engine generator;
public:
	Rfpolynomial();
	void generate(int, Timer&, float, float);
	void setCase(string&, int, int, int, float, float, int, int, string&);
};

# endif