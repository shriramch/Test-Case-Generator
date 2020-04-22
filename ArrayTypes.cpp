# include "ArrayTypes.h"

// A constructor
Rarray :: Rarray()
{
	N = g = 0;
}

// A class that generates a distribution based random array
void Rarray :: generate(int n, int d, Timer &t1, int l, int r)
{
	default_random_engine generator(system_clock :: now().time_since_epoch().count());
	if(d == 0)
	{
		uniform_int_distribution <int> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			fout << g << ' ';
			t1.time(1);
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			fout << g << ' ';
			t1.time(1);
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			fout << g << ' ';
			t1.time(1);
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			fout << g << ' ';
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
			fout << l + g % (r - l + 1) << ' ';
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
			fout << l + g % (r - l + 1) << ' ';
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
			fout << g << ' ';
			t1.time(1);
		}
	}
	fout << '\n';
}

// A function that generates array test case files
void Rarray :: setCase(string &s, int T, int t, int n, int l, int r, int d, bool neg, int sz, string &folder_name)
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
		{
			fout << times[j] << '\n';
			generate(times[j], dist[j], t1, l, r);
		}
		fout.close();
	}
	cout << "array generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rarray :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}

// A constructor
Rdarray :: Rdarray()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random array of distinct elements
void Rdarray :: generate(int n, Timer &t1, int l, int r)
{
	g.clear();
	uniform_int_distribution <int> distribution(l, r);
	while((int)g.size() < n)
	{
		int t = g.size();
		int rn = distribution(generator);
		g.insert(rn);
		if((int)g.size() > t)
		{
			t1.time(1);
			fout << rn << ' ';
		}
	}
	fout << '\n';
}

// A function that generates dinstinct element array test case arrays
void Rdarray :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating darray test files: " << '\n';
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
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "darray generation completed." << '\n';
}

// A constructor
Rkey_darray :: Rkey_darray()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a distinct array with given key element
void Rkey_darray :: generate(int n, Timer &t1, int l, int r, int k)
{
	g.clear();
	g.insert(k);
	t1.time(1);
	uniform_int_distribution <int> distribution(l, r);
	while((int)g.size() < n)
	{
		int t = g.size();
		int rn = distribution(generator);
		g.insert(rn);
		if((int)g.size() > t)
			t1.time(1);
	}
	vector <int> gg;
	for(auto i : g)
		gg.push_back(i);
	shuffle(gg.begin(), gg.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : gg)
		fout << i << ' ';
	fout << '\n';
}

// A function that generates a distinct array with given key element test case files
void Rkey_darray :: setCase(string &s, int T, int t, int n, int l, int r, int k, int sz, string &folder_name)
{
	cout << "Generating key_darray test files: " << '\n';
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
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r, k);
		}
		fout.close();
	}
	cout << "key_darray generation completed." << '\n';
}

// A constructor
Rdiv_array :: Rdiv_array()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates distinct arrays with numbers divisbile by a key
void Rdiv_array :: generate(int n, Timer &t1, int l, int r, int fact)
{
	g.clear();
	uniform_int_distribution <int> distribution(l, r);
	while((int)g.size() < n)
	{
		int t = g.size();
		int rn = distribution(generator);
		g.insert(rn);
		if((int)g.size() > t)
		{
			t1.time(1);
			fout << rn * fact << ' ';
		}
	}
	fout << '\n';
}

// A class that generates distinct arrays with numbers divisbile by a key test case files
void Rdiv_array :: setCase(string &s, int T, int t, int n, int l, int r, int fact, int sz, string &folder_name)
{
	cout << "Generating div_array test files: " << '\n';
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
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, ceil(l * 1.0/ fact), floor(r *1.0 / fact), fact);
		}
		fout.close();
	}
	cout << "div_array generation completed." << '\n';
}
