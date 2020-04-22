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

# define int long long
# define float long double

using namespace std;
using namespace std :: chrono;

// A class that fixes user defined distributions
class Distribution
{
	default_random_engine gen;
	discrete_distribution <int> idist {7, 1, 1, 21, 0, 0, 0, 35, 35, 21};
	discrete_distribution <int> fdist {7, 1, 1, 21, 35, 21, 35, 0, 0, 21};
	discrete_distribution <int> indist {7, 1, 1, 28, 0, 0, 0, 0, 42, 28};
	discrete_distribution <int> fndist {7, 1, 1, 35, 49, 0, 0, 0, 0, 35};
public:
	Distribution();
	void setCaseDis(int, int, vector <int>&, int, bool);	
	void setCaseDis(int, int, vector <int>&, float, bool);
};

# endif
