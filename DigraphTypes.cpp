# include "DigraphTypes.h"

// A constructor
Rdgraph :: Rdgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random digraph
void Rdgraph :: generate(int n, Timer &t1, int e)
{
	uniform_int_distribution <int> distribution(1, n);
	m.clear();
	int gcount = 0;
	while(gcount != e)
	{
		int u = distribution(generator);
		int v = distribution(generator);
		if(u != v)
		{
			if(m[make_pair(u, v)] == 0)
			{
				m[make_pair(u, v)] = 1;
				fout << u << ' ' << v << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generates digraph test case files
void Rdgraph :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating dgraph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		ec.clear();
		int tcnt = 0;
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]), 2 * times[j]));
			ec.push_back(edge);
			tcnt += ec[j];
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j]);
		}
		fout.close();
	}
	cout << "dgraph generation completed." << '\n';
}

// A constructor
Rdwgraph :: Rdwgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random weighted digraph
void Rdwgraph :: generate(int n, Timer &t1, int e, int l, int r)
{
	uniform_int_distribution <int> distribution(1, n);
	uniform_int_distribution <int> weights(l, r);
	m.clear();
	int gcount = 0;
	while(gcount != e)
	{
		int u = distribution(generator);
		int v = distribution(generator);
		if(u != v)
		{
			if(m[make_pair(u, v)] == 0)
			{
				m[make_pair(u, v)] = 1;
				int w = weights(generator);
				fout << u << ' ' << v << ' ' << w << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generates random weighted digraph test case files
void Rdwgraph :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating dwgraph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		ec.clear();
		int tcnt = 0;
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]), 2 * times[j]));
			ec.push_back(edge);
			tcnt += ec[j];
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j], l, r);
		}
		fout.close();
	}
	cout << "dwgraph generation completed." << '\n';
}

// A constructor
Rdvwgraph :: Rdvwgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random vertex weighted digraph
void Rdvwgraph :: generate(int n, Timer &t1, int e, int l, int r)
{
	uniform_int_distribution <int> distribution(1, n);
	uniform_int_distribution <int> weights(l, r);
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		fout << weights(generator) << ' ';
	}
	fout << '\n';
	m.clear();
	int gcount = 0;
	while(gcount != e)
	{
		int u = distribution(generator);
		int v = distribution(generator);
		if(u != v)
		{
			if(m[make_pair(u, v)] == 0)
			{
				m[make_pair(u, v)] = 1;
				fout << u << ' ' << v << ' ' << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generates vertex weighted digraph test case files
void Rdvwgraph :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating dwgraph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		ec.clear();
		int tcnt = 0;
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]), 2 * times[j]));
			ec.push_back(edge);
			tcnt += (times[j] + ec[j]);
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j], l, r);
		}
		fout.close();
	}
	cout << "dwgraph generation completed." << '\n';
}

// A constructor
Rdag :: Rdag()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random dag
void Rdag :: generate(int n, Timer &t1, int e)
{
	uniform_int_distribution <int> distribution(1, n);
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	m.clear();
	int gcount = 0;
	while(gcount != e)
	{
		int u = distribution(generator);
		int v = distribution(generator);
		if(u != v)
		{
			int x = min(u, v);
			int y = max(u, v);
			if(m[make_pair(x, y)] == 0)
			{
				m[make_pair(x, y)] = 1;
				fout << a[x] << ' ' << a[y] << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generates dag test case files
void Rdag :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating dag test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		ec.clear();
		int tcnt = 0;
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 3 * times[j]) / 2);
			ec.push_back(edge);
			tcnt += ec[j];
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j]);
		}
		fout.close();
	}
	cout << "dag generation completed." << '\n';
}

// A constructor
Rwdag :: Rwdag()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that genrerates a random weighted dag
void Rwdag :: generate(int n, Timer &t1, int e, int l, int r)
{
	uniform_int_distribution <int> weights(l, r);
	uniform_int_distribution <int> distribution(1, n);
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	m.clear();
	int gcount = 0;
	while(gcount != e)
	{
		int u = distribution(generator);
		int v = distribution(generator);
		if(u != v)
		{
			int x = min(u, v);
			int y = max(u, v);
			if(m[make_pair(x, y)] == 0)
			{
				m[make_pair(x, y)] = 1;
				fout << a[x] << ' ' << a[y] << ' ';
				int w = weights(generator);
				fout << w << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generates weighted dag test case files
void Rwdag :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating wdag test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		ec.clear();
		int tcnt = 0;
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 3 * times[j]) / 2);
			ec.push_back(edge);
			tcnt += ec[j];
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j], l, r);
		}
		fout.close();
	}
	cout << "wdag generation completed." << '\n';
}

// A constructor
Rvwdag :: Rvwdag()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random vertex weighted dag
void Rvwdag :: generate(int n, Timer &t1, int e, int l, int r)
{
	uniform_int_distribution <int> weights(l, r);
	for(int i = 0; i < n; i++)
	{
		fout << weights(generator) << ' ';
		t1.time(1);
	}
	fout << '\n';
	uniform_int_distribution <int> distribution(1, n);
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	m.clear();
	int gcount = 0;
	while(gcount != e)
	{
		int u = distribution(generator);
		int v = distribution(generator);
		if(u != v)
		{
			int x = min(u, v);
			int y = max(u, v);
			if(m[make_pair(x, y)] == 0)
			{
				m[make_pair(x, y)] = 1;
				fout << a[x] << ' ' << a[y] << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generates vertex weighted dag test case files
void Rvwdag :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating vwdag test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		ec.clear();
		int tcnt = 0;
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 3 * times[j]) / 2);
			ec.push_back(edge);
			tcnt += (times[j] + ec[j]);
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j], l, r);
		}
		fout.close();
	}
	cout << "vwdag generation completed." << '\n';
}
