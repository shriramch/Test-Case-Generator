# ifndef INVALID_H
# define INVALID_H

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

// An exception class
class Invalid
{
	int eno;
public:
	void setCaseError(int);
	int retError();
};

# endif
