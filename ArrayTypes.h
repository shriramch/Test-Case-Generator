# ifndef ARRAYTYPES_H
# define ARRAYTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates array test cases
class Rarray
{
	int N;
	int g;
	fstream fout;
	vector <int> dist;
public:
	Rarray();
	void generate(int, int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

// A class that generates distinct element arrays
class Rdarray
{
	int N;
	set <int> g;
	fstream fout;
	default_random_engine generator;
public:
	Rdarray();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates distinct arrays containing a given key element test cases
class Rkey_darray
{
	int N;
	set <int> g;
	fstream fout;
	default_random_engine generator;
public:
	Rkey_darray();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, int, string&);
};

// A class that generates distinct arrays with numbers divisbile by a key test cases
class Rdiv_array
{
	int N;
	set <int> g;
	fstream fout;
	default_random_engine generator;
public:
	Rdiv_array();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, int, string&);
};

# endif
