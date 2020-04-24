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

void Distribution :: FillArray(vector <int> &values, int n, int l, int r, bool neg, Timer &t1)
{
	discrete_distribution <int> idist {13, 1, 1, 42, 0, 0, 0, 35, 35, 21};
	discrete_distribution <int> indist {13, 1, 1, 49, 0, 0, 0, 0, 0, 49};
	default_random_engine gen(system_clock :: now().time_since_epoch().count());
	if(neg == false)
	{
		int d;
		if(r - l < 4)
			d = 3;
		else d = idist(gen);
		if(d == 0)
		{
			uniform_int_distribution <int> distribution(l, r);
			int g = distribution(gen);
			for(int i = 0; i < n; i++)
			{
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 1)
		{
			int g = l;
			for(int i = 0; i < n; i++)
			{
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 2)
		{
			int g = r;
			for(int i = 0; i < n; i++)
			{
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 3)
		{
			uniform_int_distribution <int> distribution(l, r);
			for(int i = 0; i < n; i++)
			{
				int g = distribution(gen);
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 7)
		{
			int p = rand() % 101;
			binomial_distribution <int> distribution((l + r) / 2, p / 100.0);
			for(int i = 0; i < n; i++)
			{
				int g = distribution(gen);
				values.push_back(l + g % (r - l + 1));
				t1.time(1);
			}
		}
		else if(d == 8)
		{
			uniform_real_distribution <float> d1(l, r);
			int mean = d1(gen);
			poisson_distribution <int> distribution(mean);
			for(int i = 0; i < n; i++)
			{
				int g = distribution(gen);
				values.push_back(l + g % (r - l + 1));
				t1.time(1);
			}
		}
		else if(d == 9)
		{
			uniform_real_distribution <float> d1(l, r);
			float mid = d1(gen);
			array <float, 3> intervals {l * 1.0, mid, r * 1.0};
  			array <float, 3> weights {10.0, 1.0, 10.0};
			piecewise_linear_distribution <float> distribution(intervals.begin(), intervals.end(), weights.begin());
			for(int i = 0; i < n; i++)
			{
				int g = l + ((int)(distribution(gen))) % (r - l + 1);
				values.push_back(g);
				t1.time(1);
			}
		}
	}
	else
	{
		int d = indist(gen);
		if(d == 0)
		{
			uniform_int_distribution <int> distribution(l, r);
			int g = distribution(gen);
			for(int i = 0; i < n; i++)
			{
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 1)
		{
			int g = l;
			for(int i = 0; i < n; i++)
			{
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 2)
		{
			int g = r;
			for(int i = 0; i < n; i++)
			{
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 3)
		{
			uniform_int_distribution <int> distribution(l, r);
			for(int i = 0; i < n; i++)
			{
				int g = distribution(gen);
				values.push_back(g);
				t1.time(1);
			}
		}
		else if(d == 9)
		{
			uniform_real_distribution <float> d1(l, r);
			float mid = d1(gen);
			array <float, 3> intervals {l * 1.0, mid, r * 1.0};
  			array <float, 3> weights {10.0, 1.0, 10.0};
			piecewise_linear_distribution <float> distribution(intervals.begin(), intervals.end(), weights.begin());
			for(int i = 0; i < n; i++)
			{
				int g = l + ((int)(distribution(gen))) % (r - l + 1);
				values.push_back(g);
				t1.time(1);
			}
		}
	}
}