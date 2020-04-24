# ifndef CHSTRINGTYPES_H
# define CHSTRINGTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates strings made from given character set test cases
class Rchar_string
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	Rchar_string();
	void generate(int, Timer&, string);
	void setCase(string&, int, int, int, string, int, int, string&);
};

// A class that generates 01-string test cases
class R01string
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	R01string();
	void generate(int, Timer&);
	void setCase(string&, int, int, int, int, int, string&);
};

// A class that generates pair of char_string test cases
class Rchar_pair
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	Rchar_pair();
	void generate(int, Timer&, string);
	void setCase(string&, int, int, int, string, int, int, string&);
};

// A class that generates array of char_string test cases
class Rchar_array
{
	vector <int> N, M;
	fstream fout;
	default_random_engine generator;
public:
	Rchar_array();
	void generate(Timer&, string, int, int, int);
	void setCase(string&, int, int, int, string, int, int, string&);
};


# endif
