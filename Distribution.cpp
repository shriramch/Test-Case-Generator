# include "Distribution.h"

// A constructor
Distribution :: Distribution()
{
	gen.seed(system_clock :: now().time_since_epoch().count());
}

// An overloaded function that fill a distribution vector of given size
void Distribution :: setCaseDis(int n, int d, vector <int> &dist, int t1, bool neg)
{
	if(neg == true)
	{
		if(d == -1)
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = indist(gen);
		}
		else
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = d;
		}
	}
	else
	{
		if(d == -1)
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = idist(gen);
		}
		else
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = d;
		}
	}
}


// An overloaded function that fill a distribution vector of given size
void Distribution :: setCaseDis(int n, int d, vector <int> &dist, float t1, bool neg)
{
	if(neg == true)
	{
		if(d == -1)
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = fndist(gen);
		}
		else
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = d;
		}
	}
	else
	{
		if(d == -1)
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = fdist(gen);
		}
		else
		{
			dist.resize(n);
			for(int i = 0; i < n; i++)
				dist[i] = d;
		}
	}
}
