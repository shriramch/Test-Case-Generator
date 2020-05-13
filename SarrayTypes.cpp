# include "SarrayTypes.h"

// A constructor
Rsarray :: Rsarray()
{
	N = rn = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random sorted array of given distribution
void Rsarray :: generate(int n, int d, Timer &t1, int l, int r)
{
	g.clear();
	if(d == 0)
	{
		uniform_int_distribution <int> distribution(l, r);
		rn = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			g.push_back(rn);
			t1.time(1);
		}
	}
	else if(d == 1)
	{
		rn = l;
		for(int i = 0; i < n; i++)
		{
			g.push_back(rn);
			t1.time(1);
		}
	}
	else if(d == 2)
	{
		rn = r;
		for(int i = 0; i < n; i++)
		{
			g.push_back(rn);
			t1.time(1);
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			rn = distribution(generator);
			g.push_back(rn);
			t1.time(1);
		}
	}
	else if(d == 7)
	{
		int p = rand() % 101;
		binomial_distribution <int> distribution((l + r) / 2, p / 100.0);
		for(int i = 0; i < n; i++)
		{
			rn = distribution(generator);
			g.push_back(l + rn % (r - l + 1));
			t1.time(1);
		}
	}
	else if(d == 8)
	{

		uniform_real_distribution <float> d1(l, r);
		poisson_distribution <int> distribution(d);
		for(int i = 0; i < n; i++)
		{
			rn = distribution(generator);
			g.push_back(l + rn % (r - l + 1));
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
			rn = l + ((int)(distribution(generator))) % (r - l + 1);
			g.push_back(rn);
			t1.time(1);
		}
	}
}

// A function that generates sorted array test case files
void Rsarray :: setCase(string &s, int T, int t, int n, int l, int r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating sarray test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(2 * tcnt);
		vector <int> dist = setCaseDist(N, d, neg);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], dist[j], t1, l, r);
			sort(g.begin(), g.end());
			for(int k = 0; k < times[j]; k++)
			{
				fout << g[k] << " \n"[i == times[j] - 1];
				t1.time(1);
			}
		}
		fout.close();
	}
	cout << "sarray generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rsarray :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}

// A constructor
Rsdarray :: Rsdarray()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random sorted array of distinct elements
void Rsdarray :: generate(int n, Timer &t1, int l, int r)
{
	g.clear();
	uniform_int_distribution <int> distribution(l, r);
	while((int)g.size() < n)
	{
		int t = g.size();
		int rn = distribution(generator);
		g.insert(rn);
		if((int)g.size() > t)
			t1.time(1);
	}
}

// A function that generates sorted distinct elements test case files
void Rsdarray :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating sdarray test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(2 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r);
			for(auto k : g)
			{
				fout << k << " \n"[i == times[j] - 1];
				t1.time(1);
			}
		}
		fout.close();
	}
	cout << "sdarray generation completed." << '\n';
}
