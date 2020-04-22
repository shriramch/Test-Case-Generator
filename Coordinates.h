# ifndef COORDINATES_H
# define COORDINATES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates coordinate test cases
class Rcoordinates
{
	int N;
	int g, h;
	fstream fout;
	vector <int> dist;
	default_random_engine generator;
public:
	Rcoordinates();
	void generate(int, int, Timer&, int, int, int, int);
	void setCase(string&, int, int, int, int, int, int, int, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

// A class that generates unique coordinates
class Rucoordinates
{
	int N;
	set <int> g, h;
	fstream fout;
	default_random_engine generator;
public:
	Rucoordinates();
	void generate(int, Timer&, int, int, int, int);
	void setCase(string&, int, int, int, int, int, int, int, int, string&);
};

# endif