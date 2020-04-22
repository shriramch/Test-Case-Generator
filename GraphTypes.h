# ifndef GRAPHTYPES_H
# define GRAPHTYPES_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"

// A function that generates a random graph
class Rgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rgraph();
	void generate(int, Timer&, int);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates weighted graph test cases
class Rwgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rwgraph();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates vertex weighted graph test cases
class Rvwgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	fstream fout;
	default_random_engine generator;
public:
	Rvwgraph();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates connected graph test cases
class Rconngraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	vector <pair <int, int> > edlist;
	fstream fout;
	default_random_engine generator;
public:
	Rconngraph();
	void generate(int, Timer&, int);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates connected weighted graph test cases
class Rconnwgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	vector <tuple <int, int, int> > edlist;
	fstream fout;
	default_random_engine generator;
public:
	Rconnwgraph();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates connected vertex weighted graph test cases
class Rconnvwgraph
{
	int N;
	vector <int> ec;
	map <pair <int, int>, int> m;
	vector <pair <int, int> > edlist;
	fstream fout;
	default_random_engine generator;
public:
	Rconnvwgraph();
	void generate(int, Timer&, int, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates disconnected graph test cases
class Rdisgraph
{
	int N;
	map <pair <int, int>, int> m;
	vector <pair <int, int> > edlist;
	fstream fout;
	default_random_engine generator;
public:
	Rdisgraph();
	void generate(int, vector <pair <int, int> >&, Timer&, vector <int>&);
	void setCase(string&, int, int, int, int, string&);
};

// A class that generates edge-weighted disconnected graph test cases
class Rdiswgraph
{
	int N;
	map <pair <int, int>, int> m;
	vector <tuple <int, int, int> > edlist;
	fstream fout;
	default_random_engine generator;
public:
	Rdiswgraph();
	void generate(int, vector <pair <int, int> >&, Timer&, vector <int>&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

// A class that generates vertex weighted disconnected graph test cases
class Rdisvwgraph
{
	int N;
	map <pair <int, int>, int> m;
	vector <pair <int, int> > edlist;
	fstream fout;
	default_random_engine generator;
public:
	Rdisvwgraph();
	void generate(int, vector <pair <int, int> >&, Timer&, vector <int>&, int, int);
	void setCase(string&, int, int, int, int, int, int, string&);
};

# endif