# include "Tuple.h"

// A constructor
Rtuple :: Rtuple()
{
	g = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random tuple
void Rtuple :: generate(int nc, vector <int> &l, vector <int> &r, Timer &t1)
{
	for(int i = 0; i < nc; i++)
	{
		uniform_int_distribution <int> disti(l[i], r[i]);
		g = disti(generator);
		fout << g << " \n"[i == nc - 1];
		t1.time(1);
	}
}

// A function that generates tuple test case files
void Rtuple :: setCase(string &s, int T, int t, int nc, vector <int> &l, vector <int> &r, string &folder_name)
{
	int pt = FileOp :: printT(t);
	cout << "Generating tuple test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		int times = numOp :: giveRint(t);
		if(pt)
			fout << times << '\n';
		int tcnt = nc * times;
		Timer t1(tcnt);
		for(int j = 0; j < times; j++)
			generate(nc, l, r, t1);
		fout.close();
	}
	cout << "tuple generation completed." << '\n';
}

// A constructor
RtupleArray :: RtupleArray()
{
	g = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random tuple field based on distribution
void RtupleArray :: generate(vector <int> &res, int n, int d, Timer &t1, int l, int r)
{
	if(d == 0)
	{
		uniform_int_distribution <int> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			res.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			res.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			res.push_back(g);
			t1.time(1);
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			res.push_back(g);
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
			res.push_back(l + g % (r - l + 1));
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
			res.push_back(l + g % (r - l + 1));
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
			res.push_back(g);
			t1.time(1);
		}
	}
}

// A function that generates random tuple test case files
void RtupleArray :: setCase(string &s, int T, int t, int nc, int n, vector <int> &l, vector <int> &r, int d, int sz, string &folder_name)
{
	int pt = FileOp :: printT(t);
	cout << "Generating tuple_array test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		if(pt)
			fout << times.size() << '\n';
		int tcnt = 0;
		vector <vector <int> > res(nc);
		for(int j = 0; j < (int)times.size(); j++)
			tcnt += nc * times[j];
		Timer t1(2 * tcnt);
		for(int j = 0; j < (int)times.size(); j++)
		{
			fout << times[j] << '\n';
			for(int k = 0; k < nc; k++)
			{
				int dist = setCaseDist(1, d, (l[k] <= 0));
				generate(res[k], times[j], dist, t1, l[k], r[k]);
			}
			for(int k = 0; k < n; k++)
				for(int x = 0; x < nc; x++)
				{
					fout << res[x][k] << " \n"[x == nc - 1];
					t1.time(1);
				}
		}
		fout.close();
	}
	cout << "tuple_array generation completed." << '\n';
}

// A function that sets distribution for all test cases
int RtupleArray :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist[0];
}
