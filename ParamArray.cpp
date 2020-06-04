# include "ParamArray.h"

// A constructor
Rparamarray :: Rparamarray()
{
	N = g = 0;
}

// A class that generates a distribution based random parameeter set + array
void Rparamarray :: generate(int n, int d, Timer &t1, int l, int r, vector <int> &pl, vector <int> &pr)
{
	default_random_engine generator(system_clock :: now().time_since_epoch().count());
	fout << n << ' ';
	for(int i = 0; i < (int)pl.size(); i++)
	{
		if(pl[i] <= pr[i])
		{
			uniform_int_distribution <int> d1(pl[i], pr[i]);
			fout << d1(generator) << " \n"[i == (int)pl.size() - 1];
		}
		else
		{
			uniform_int_distribution <int> d1(1, n);
			fout << d1(generator) << " \n"[i == (int)pl.size() - 1];
		}
	}
	if(d == 0)
	{
		uniform_int_distribution <int> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 7)
	{
		int p = rand() % 101;
		binomial_distribution <int> distribution((l + r) / 2, p / 100.0);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			fout << l + g % (r - l + 1) << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 8)
	{

		uniform_real_distribution <float> d1(l, r);
		poisson_distribution <int> distribution(d);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			fout << l + g % (r - l + 1) << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 9)
	{
		uniform_real_distribution <float> d1(l, r);
		float mid = d1(generator);
		array <float, 3> intervals {l * 1.0, mid, r * 1.0};
  		array <float, 3> weights {10.0, 1.0, 10.0};
		piecewise_linear_distribution <float> distribution(intervals.begin(), intervals.end(), weights.begin());
		for(int i = 0; i < n; i++)
		{
			g = l + ((int)(distribution(generator))) % (r - l + 1);
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
}

// A function that generates paramater set + array test case files
void Rparamarray :: setCase(string &s, int T, int t, int n, vector <int> &pl, vector <int> &pr, int l, int r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating paramarray test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(tcnt);
		vector <int> dist = setCaseDist(N, d, neg);
		for(int j = 0; j < N; j++)
			generate(times[j], dist[j], t1, l, r, pl, pr);
		fout.close();
	}
	cout << "paramarray generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rparamarray :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}

// A constructor
Rptuple :: Rptuple()
{
	N = g = 0;
}

// A class that generates a distribution based random parameeter set + tuple array
void Rptuple :: generate(vector <int> &v, int n, int d, int l, int r, Timer &t1)
{
	if(l > r)
	{
		l = 1;
		r = n;
	}
	default_random_engine generator(system_clock :: now().time_since_epoch().count());
	if(d == 0)
	{
		uniform_int_distribution <int> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			v.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			v.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			v.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			g = l + g % (r - l + 1);
			v.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 7)
	{
		int p = rand() % 101;
		binomial_distribution <int> distribution((l + r) / 2, p / 100.0);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			g = l + g % (r - l + 1);
			v.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 8)
	{

		uniform_real_distribution <float> d1(l, r);
		poisson_distribution <int> distribution(d);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			g = l + g % (r - l + 1);
			v.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 9)
	{
		uniform_real_distribution <float> d1(l, r);
		float mid = d1(generator);
		array <float, 3> intervals {l * 1.0, mid, r * 1.0};
  		array <float, 3> weights {10.0, 1.0, 10.0};
		piecewise_linear_distribution <float> distribution(intervals.begin(), intervals.end(), weights.begin());
		for(int i = 0; i < n; i++)
		{
			g = l + ((int)(distribution(generator))) % (r - l + 1);
			v.push_back(g);
			t1.time(1);
		}
	}
}

// A function that generates paramater set + tuple array test case files
void Rptuple :: setCase(string &s, int T, int t, int n, vector <int> &pl, vector <int> &pr, vector <int> &l, vector <int> &r, int d, int sz, string &folder_name)
{
	default_random_engine generator(system_clock :: now().time_since_epoch().count());
	cout << "Generating ptuple test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += 2 * (int)l.size() * times[j];
		tcnt += (int)pl.size();
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ';
			for(int k = 0; k < (int)pl.size(); k++)
			{
				if(pl[k] <= pr[k])
				{
					uniform_int_distribution <int> d1(pl[k], pr[k]);
					fout << d1(generator) << " \n"[k == (int)pl.size() - 1];
				}
				else
				{
					uniform_int_distribution <int> d1(1, times[j]);
					fout << d1(generator) << " \n"[k == (int)pl.size() - 1];
				}
				t1.time(1);
			}
			vector <vector <int> > out((int)l.size());
			for(int k = 0; k < (int)l.size(); k++)
			{
				int dist = setCaseDist(1, d, (bool)(l[k] <= 0))[0];
				generate(out[k], times[j], dist, l[k], r[k], t1);
			}
			for(int x = 0; x < times[j]; x++)
				for(int k = 0; k < (int)l.size(); k++)
				{
					fout << out[k][x] << " \n"[k == (int)l.size() - 1];
					t1.time(1);
				}
		}
		fout.close();
	}
	cout << "ptuple generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rptuple :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}