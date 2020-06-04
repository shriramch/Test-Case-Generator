# ifndef PARAMARRAY_H
# define PARAMARRAY_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates parameter set + array test cases
class Rparamarray
{
	int N;
	int g;
	fstream fout;
	vector <int> dist;
public:
	Rparamarray();
	void generate(int, int, Timer&, int, int, vector <int> &, vector <int> &);
	void setCase(string&, int, int, int, vector <int> &, vector <int> &, int, int, int, bool, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

class Rptuple
{
	int N;
	int g;
	fstream fout;
	vector <int> dist;
public:
	Rptuple();
	void generate(vector <int> &, int, int, int, int, Timer &);
	void setCase(string&, int, int, int, vector <int> &, vector <int> &, vector <int> &, vector <int> &, int, int, string&);
	vector <int> setCaseDist(int, int, bool);
};

# endif
