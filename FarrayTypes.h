# ifndef FARRAYTYPES_H
# define FARRAYTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that sets floating point array test cases
class Rfarray
{
	int N;
	float g;
	fstream fout;
	vector <int> dist;
public:
	Rfarray();
	void generate(int, int, Timer&, float, float);
	void setCase(string&, int, int, int, float, float, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

// A class that generates sorted floating point array test cases 
class Rsfarray
{
	int N;
	float rn;
	vector <float> g;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	Rsfarray();
	void generate(int, int, Timer&, float, float);
	void setCase(string&, int, int, int, float, float, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

# endif
