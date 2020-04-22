# include "Timer.h"

// A default constructor
Timer :: Timer()
{
	count = total_count = 0;
}

// An argument constructor
Timer :: Timer(int cnt)
{
	total_count = cnt;
	count = 0;
}

// A class that increment the timer count and modify the progress bar display
void Timer :: time(int inc)
{
	count += inc;
	float frac = 100.0;
	frac *= count;
	frac /= total_count;
	cout << "[";
	for(int i = 1; i <= frac / 5 && i <= 20; i++)
		cout << "*";
	for(int i = frac / 5 + 1; i <= 20; i++)
		cout << ' ';
	cout <<"]	";
	cout << (int)frac << "% done.";
	if(count == total_count)
	{
		cout << '\n';
		return;
	}
	cout << '\r';
}