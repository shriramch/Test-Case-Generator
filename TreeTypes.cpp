# include "TreeTypes.h"

// A constructor
Rtree :: Rtree()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random tree
void Rtree :: generate(int n, Timer &t1)
{
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		a[i] = i;
	}
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	g.clear();
	for(int i = 2; i < n + 1; i++)
	{
		int u = a[i];
		uniform_int_distribution <int> d1(1, i - 1);
		int v = a[d1(generator)];
		int x = rand() % 2;
		if(x)
			g.push_back(make_pair(u, v));
		else g.push_back(make_pair(v, u));
		t1.time(1);
	}
	t1.time(1);
	shuffle(g.begin(), g.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : g)
	{
		fout << i.first << ' ' << i.second << '\n';
		t1.time(1);
	}
	t1.time(1);
}

// A function that generates tree test case files
void Rtree :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating tree test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(3 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1);
		}
		fout.close();
	}
	cout << "tree generation completed." << '\n';
}

// A constructor
Rrtree :: Rrtree()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random rooted tree
void Rrtree :: generate(int n, Timer &t1)
{
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		a[i] = i;
	}
	shuffle(a + 2, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	g.clear();
	for(int i = 2; i < n + 1; i++)
	{
		int u = a[i];
		uniform_int_distribution <int> d1(1, i - 1);
		int v = a[d1(generator)];
		int x = rand() % 2;
		if(x)
			g.push_back(make_pair(u, v));
		else g.push_back(make_pair(v, u));
		t1.time(1);
	}
	t1.time(1);
	shuffle(g.begin(), g.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : g)
	{
		fout << i.first << ' ' << i.second << '\n';
		t1.time(1);
	}
	t1.time(1);
}

// A function that generates rooted tree test case files
void Rrtree :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating rtree test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(3 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1);
		}
		fout.close();
	}
	cout << "rtree generation completed." << '\n';
}

// A constructor
Rwtree :: Rwtree()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random weighted tree
void Rwtree :: generate(int n, Timer &t1, int l, int r)
{
	int a[n + 1];
	uniform_int_distribution <int> distribution(l, r);
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		a[i] = i;
	}
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	g.clear();
	for(int i = 2; i < n + 1; i++)
	{
		int u = a[i];
		uniform_int_distribution <int> d1(1, i - 1);
		int v = a[d1(generator)];
		int x = rand() % 2;
		int w = distribution(generator);
		if(x)
			g.push_back(make_tuple(u, v, w));
		else g.push_back(make_tuple(v, u, w));
		t1.time(1);
	}
	t1.time(1);
	shuffle(g.begin(), g.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : g)
	{
		fout << get <0> (i) << ' ' << get <1> (i) << ' ' << get <2> (i) << '\n';
		t1.time(1);
	}
	t1.time(1);
}

// A function that generates weighted tree test case files
void Rwtree :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating wtree test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(3 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "wtree generation completed." << '\n';
}

// A constructor
Rvwtree :: Rvwtree()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random vertex weighted tree
void Rvwtree :: generate(int n, Timer &t1, int l, int r)
{
	int a[n + 1];
	uniform_int_distribution <int> distribution(l, r);
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		a[i] = i;
	}
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		fout << distribution(generator) << ' ';
	}
	fout << '\n';
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	g.clear();
	for(int i = 2; i < n + 1; i++)
	{
		int u = a[i];
		uniform_int_distribution <int> d1(1, i - 1);
		int v = a[d1(generator)];
		int x = rand() % 2;
		if(x)
			g.push_back(make_pair(u, v));
		else g.push_back(make_pair(v, u));
		t1.time(1);
	}
	t1.time(1);
	shuffle(g.begin(), g.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : g)
	{
		fout << i.first << ' ' << i.second << '\n';
		t1.time(1);
	}
	t1.time(1);
}

// A function that generates vertex weighted tree test case files
void Rvwtree :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating vwtree test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(4 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "vwtree generation completed." << '\n';
}

// A constructor
Rrwtree :: Rrwtree()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random rooted weighted tree
void Rrwtree :: generate(int n, Timer &t1, int l, int r)
{
	int a[n + 1];
	uniform_int_distribution <int> distribution(l, r);
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		a[i] = i;
	}
	shuffle(a + 2, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	g.clear();
	for(int i = 2; i < n + 1; i++)
	{
		int u = a[i];
		uniform_int_distribution <int> d1(1, i - 1);
		int v = a[d1(generator)];
		int x = rand() % 2;
		int w = distribution(generator);
		if(x)
			g.push_back(make_tuple(u, v, w));
		else g.push_back(make_tuple(v, u, w));
		t1.time(1);
	}
	t1.time(1);
	shuffle(g.begin(), g.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : g)
	{
		fout << get <0> (i) << ' ' << get <1> (i) << ' ' << get <2> (i) << '\n';
		t1.time(1);
	}
	t1.time(1);
}

// A function that generates rooted weighted tree test case files
void Rrwtree :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating wrtree test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(3 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "wrtree generation completed." << '\n';
}
