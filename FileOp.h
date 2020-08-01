# ifndef FILEOP_H
# define FILEOP_H

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
# include "numOp.h"

# define int long long
# define float long double

using namespace std;
using namespace std :: chrono;

// A class that defines a few file setting operations
class FileOp
{
public:
	static void setFile(string &, string &, int, fstream &);
	static void fixOutprecision(fstream &);
	static int printT(int);
};

# endif
