# ifndef NUMOP_H
# define NUMOP_H

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

// A class that does number operations
class numOp {
public:
	static pair <int, bool> ctnum(string);
	static pair <float, bool> ctf(string);
	static string nts(int);
	static int giveRint(int);
	static vector <int> giveRints(int, int, int);
};

# endif