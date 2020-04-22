# ifndef DISTRIBUTION_H
# define DISTRIBUTION_H

# include <algorithm>
# include <array>
# include <chrono>
# include <cmath>
# include <cstdio>
# include <cstdlib>
# include <cstring>
# include <fstream>
# include <iostream>
# include <iterator>
# include <map>
# include <random>
# include <set>
# include <sstream>
# include <string>
# include <sys/stat.h> 
# include <sys/types.h> 
# include <thread>
# include <vector>
# include "Timer.h"

# define int long long
# define float long double

using namespace std;
using namespace std :: chrono;

// A class that fixes user defined distributions
class Distribution
{
	default_random_engine gen;
	discrete_distribution <int> idist {19, 2, 2, 42, 0, 0, 0, 35, 35, 21};
	discrete_distribution <int> fdist {19, 2, 2, 42, 35, 21, 35, 0, 0, 21};
	discrete_distribution <int> indist {19, 2, 2, 49, 0, 0, 0, 0, 0, 49};
	discrete_distribution <int> fndist {19, 2, 2, 49, 49, 0, 0, 0, 0, 35};
public:
	Distribution();
	void setCaseDis(int, int, vector <int>&, int, bool);	
	void setCaseDis(int, int, vector <int>&, float, bool);
	static void FillArray(vector <int> &, int, int, int, bool, Timer &);
};

# endif
