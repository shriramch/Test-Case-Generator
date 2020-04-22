# ifndef DIGRAPHTYPES_H
# define DIGRAPHTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates digraph test cases
class Rdgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rdgraph();
	void generate(int, Timer&, int);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates directed weighted digraph test cases
class Rdwgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rdwgraph();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates vertex weighted digraph test cases
class Rdvwgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rdvwgraph();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates dag test cases
class Rdag
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rdag();
	void generate(int, Timer&, int);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates weighted dag test cases
class Rwdag
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rwdag();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates vertex weighted dag test cases
class Rvwdag
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rvwdag();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

# endif