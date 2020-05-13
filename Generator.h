# ifndef GENERATOR_H
# define GENERATOR_H

# include "Invalid.h"
# include "IntTypes.h"
# include "FloatTypes.h"
# include "ArrayTypes.h"
# include "FarrayTypes.h"
# include "SarrayTypes.h"
# include "Perm.h"
# include "String.h"
# include "chStringTypes.h"
# include "spString.h"
# include "MatrixTypes.h"
# include "FmatrixTypes.h"
# include "IntervalTypes.h"
# include "TreeTypes.h"
# include "DenseGraph.h"
# include "GraphTypes.h"
# include "DigraphTypes.h"
# include "Coordinates.h"
# include "Polynomial.h"
# include "Tuple.h"

// A class that generates test cases
class Generate
{
	Invalid e1;
	set <string> types;
	vector <int> random;
	bool neg;
	string folder_name;
	int giveInt(string);
	float giveFloat(string);
	string giveString(string);
	void initialize();
	template <class type>
		void valid(type, type);
	template <class type>
		void valid(type, type, int);
	template <class type>
		void valid(int, int, int, type, type);
	void valid(int, char);
	void valid(string);
	void valid(int);
	void valid(float);
	void valid(pair <int, int>, int);
	void valid(int, int, int, int);
	void check(int, int);
public:
	Generate();
	void GenOutput(string, int);
	void GenOutput(string, string);
	void genfunc();
};

# endif