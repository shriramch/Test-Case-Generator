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
		uniform_int_distribution <int> d1(pl[i], pr[i]);
		fout << d1(generator) << " \n"[i == (int)pl.size() - 1];
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
	cout << "Generating array test files: " << '\n';
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
	cout << "array generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rparamarray :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}