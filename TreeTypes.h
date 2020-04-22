# ifndef TREETYPES_H
# define TREETYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A class that generates tree test cases
class Rtree
{
	int N;
	vector <pair <int, int> > g;
	fstream fout;
	default_random_engine generator;
public:
	Rtree();
	void generate(int, Timer&);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates rooted tree test cases
class Rrtree
{
	int N;
	vector <pair <int, int> > g;
	fstream fout;
	default_random_engine generator;
public:
	Rrtree();
	void generate(int, Timer&);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates weighted tree test cases
class Rwtree
{
	int N;
	vector <tuple <int, int, int> > g;
	fstream fout;
	default_random_engine generator;
public:
	Rwtree();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates vertex weighted tree test cases
class Rvwtree
{
	int N;
	vector <pair <int, int> > g;
	fstream fout;
	default_random_engine generator;
public:
	Rvwtree();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates rooted weighted tree test cases
class Rrwtree
{
	int N;
	vector <tuple <int, int, int> > g;
	fstream fout;
	default_random_engine generator;
public:
	Rrwtree();
	void generate(int, Timer&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};


# endif