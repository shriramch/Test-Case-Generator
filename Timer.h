# ifndef TIMER_H
# define TIMER_H

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

// A class that time test case generation and produce progress display
class Timer
{
	int count;
	int total_count;
public:
	Timer();
	Timer(int);
	void time(int);
};

# endif
