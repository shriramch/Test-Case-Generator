# ifndef STRING_H
# define STRING_H

# include "numOp.h"
# include "Timer.h"
# include "FileOp.h"
# include "Distribution.h"

// A class that generates string test cases
class Rstring
{
	int N;
	fstream fout;
	default_random_engine generator;
public:
	Rstring();
	void generate(int, Timer&);
	void setCase(string&, int, int, int, int, int, string&);
};

# endif