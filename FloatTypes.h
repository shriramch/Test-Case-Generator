# ifndef FLOATTYPES_H
# define FLOATTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A class that generates floating point test cases
class Rfloat
{
	float n;
	fstream fout;
	default_random_engine generator;
public:
	Rfloat();
	void generate(float, float);
	void setCase(string&, int, int, float, float, string&);
};

// A class that generates floating point pair test cases
class Rfpair
{
	float a, b;
	fstream fout;
	default_random_engine generator;
public:
	Rfpair();
	void generate(float, float);
	void setCase(string&, int, int, float, float, string&);
};

# endif