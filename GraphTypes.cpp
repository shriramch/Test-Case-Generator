# include "GraphTypes.h"

// A constructor
Rgraph :: Rgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random graph
void Rgraph :: generate(int n, Timer &t1, int e)
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
			int x = min(u, v);
			int y = max(u, v);
			if(m[make_pair(x, y)] == 0)
			{
				m[make_pair(x, y)] = 1;
				fout << u << ' ' << v << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generates graph test case files
void Rgraph :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating graph test files: " << '\n';
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
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 2 * times[j]));
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
	cout << "graph generation completed." << '\n';
}

// A constructor
Rwgraph :: Rwgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random weighted graph
void Rwgraph :: generate(int n, Timer &t1, int e, int l, int r)
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
			int x = min(u, v);
			int y = max(u, v);
			if(m[make_pair(x, y)] == 0)
			{
				m[make_pair(x, y)] = 1;
				int w = weights(generator);
				fout << u << ' ' << v << ' ' << w << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generated weighted graph test case files
void Rwgraph :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating wgraph test files: " << '\n';
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
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 2 * times[j]));
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
	cout << "wgraph generation completed." << '\n';
}

// A constructor
Rvwgraph :: Rvwgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random weighted graph
void Rvwgraph :: generate(int n, Timer &t1, int e, int l, int r)
{
	uniform_int_distribution <int> distribution(1, n);
	uniform_int_distribution <int> weights(l, r);
	m.clear();
	int gcount = 0;
	for(int i = 1; i < n + 1; i++)
	{
		t1.time(1);
		fout << weights(generator) << ' ';
	}
	fout << '\n';
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
				fout << u << ' ' << v << ' ' << '\n';
				t1.time(1);
				gcount++;
			}				
		}
	}
}

// A function that generated weighted graph test case files
void Rvwgraph :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating wgraph test files: " << '\n';
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
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 2 * times[j]));
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
	cout << "wgraph generation completed." << '\n';
}

// A constructor
Rconngraph :: Rconngraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random connected graph
void Rconngraph :: generate(int n, Timer &t1, int e)
{
	uniform_int_distribution <int> distribution(1, n);
	m.clear();
	edlist.clear();
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(int i = 2; i < n + 1; i++)
	{
		int p = 1 + rand() % (i - 1);
		edlist.push_back(make_pair(a[i], a[p]));
		m[make_pair(min(a[i], a[p]), max(a[i], a[p]))] = 1;
		t1.time(1);
	}
	int gcount = n - 1;
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
				edlist.push_back(make_pair(u, v));
				t1.time(1);
				gcount++;
			}				
		}
	}
	shuffle(edlist.begin(), edlist.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : edlist)
	{
		fout << i.first << ' ' << i.second << '\n';
		t1.time(1);
	}
}

// A function that generates connected graph test case files
void Rconngraph :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating conn_graph test files: " << '\n';
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
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 2 * times[j]));
			ec.push_back(edge);
			tcnt += ec[j];
		}
		Timer t1(2 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j]);
		}
		fout.close();
	}
	cout << "conn_graph generation completed." << '\n';
}

// A constructor
Rconnwgraph :: Rconnwgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A class that generates a connected weighted graph
void Rconnwgraph :: generate(int n, Timer &t1, int e, int l, int r)
{
	uniform_int_distribution <int> weights(l, r);
	uniform_int_distribution <int> distribution(1, n);
	m.clear();
	edlist.clear();
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(int i = 2; i < n + 1; i++)
	{
		int p = 1 + rand() % (i - 1);
		int w = weights(generator);
		edlist.push_back(make_tuple(a[i], a[p], w));
		m[make_pair(min(a[i], a[p]), max(a[i], a[p]))] = 1;
		t1.time(1);
	}
	int gcount = n - 1;
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
				int w = weights(generator);
				edlist.push_back(make_tuple(u, v, w));
				t1.time(1);
				gcount++;
			}				
		}
	}
	shuffle(edlist.begin(), edlist.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : edlist)
	{
		fout << get <0> (i) << ' ' << get <1> (i) << ' ' << get <2> (i) << '\n';
		t1.time(1);
	}
}

// A function that generates connected weighted graph test case files
void Rconnwgraph :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating conn_wgraph test files: " << '\n';
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
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 2 * times[j]));
			ec.push_back(edge);
			tcnt += ec[j];
		}
		Timer t1(2 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j], l, r);
		}
		fout.close();
	}
	cout << "conn_wgraph generation completed." << '\n';
}

// A constructor
Rconnvwgraph :: Rconnvwgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A class that generates a connected vertex weighted graph
void Rconnvwgraph :: generate(int n, Timer &t1, int e, int l, int r)
{
	uniform_int_distribution <int> weights(l, r);
	uniform_int_distribution <int> distribution(1, n);
	m.clear();
	edlist.clear();
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(int i = 1; i < n + 1; i++)
	{
		fout << weights(generator) << ' ';
		t1.time(1);
	}
	fout << '\n';
	for(int i = 2; i < n + 1; i++)
	{
		int p = 1 + rand() % (i - 1);
		edlist.push_back(make_pair(a[i], a[p]));
		m[make_pair(min(a[i], a[p]), max(a[i], a[p]))] = 1;
		t1.time(1);
	}
	int gcount = n - 1;
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
				edlist.push_back(make_pair(u, v));
				t1.time(1);
				gcount++;
			}				
		}
	}
	shuffle(edlist.begin(), edlist.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : edlist)
	{
		fout << i.first << ' ' << i.second << '\n';
		t1.time(1);
	}
}

// A function that generates connected vertex weighted graph test case files
void Rconnvwgraph :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	cout << "Generating conn_vwgraph test files: " << '\n';
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
			int edge = numOp :: giveRint(min((times[j] * times[j] - times[j]) / 2, 2 * times[j]));
			ec.push_back(edge);
			tcnt += (times[j] + 2 * ec[j]);
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ' << ec[j] << '\n';
			generate(times[j], t1, ec[j], l, r);
		}
		fout.close();
	}
	cout << "conn_vwgraph generation completed." << '\n';
}

// A constructor
Rdisgraph :: Rdisgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random disconnected graph
void Rdisgraph :: generate(int n, vector <pair <int, int> > &inter, Timer &t1, vector <int> &e)
{
	m.clear();
	edlist.clear();
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(int i = 0; i < (int)inter.size(); i++)
	{
		uniform_int_distribution <int> ed(inter[i].first, inter[i].second);
		int gcount = 0;
		while(gcount != e[i])
		{
			int u = ed(generator);
			int v = ed(generator);
			if(u != v)
			{
				int x = min(u, v);
				int y = max(u, v);
				if(m[make_pair(x, y)] == 0)
				{
					m[make_pair(x, y)] = 1;
					edlist.push_back(make_pair(u, v));
					t1.time(1);
					gcount++;
				}
			}
		}
	}
	shuffle(edlist.begin(), edlist.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	fout << n << ' ';
	int ted = 0;
	for(int i = 0; i < (int)e.size(); i++)
		ted += e[i];
	fout << ted << '\n';
	for(auto i : edlist)
	{
		t1.time(1);
		fout << a[i.first] << ' ' << a[i.second] << '\n';
	}
}

// A function that generates disconnected graph test case files
void Rdisgraph :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating disgraph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		vector <vector <pair <int, int> > > inter(N);
		vector <vector <int> > ec(N); 
		for(int j = 0; j < N; j++)
		{
			binomial_distribution <int> noc(times[j], 0.31);
			int nocc = noc(generator);
			set <int> bp;
			uniform_int_distribution <int> el(1, times[j]);
			bp.insert(times[j]);
			while((int)bp.size() < nocc)
			{
				int x = el(generator);
				bp.insert(x);
			}
			int l = 1, r;
			for(auto k : bp)
			{
				r = k;
				inter[j].push_back(make_pair(l, r));
				l = r + 1;
			}
			for(auto k : inter[j])
			{
				int v = k.second - k.first + 1;
				ec[j].push_back(numOp :: giveRint(min(2 * v, (v * v - v) / 2)));
				tcnt += *ec[j].rbegin();
			}
		}
		Timer t1(2 * tcnt);
		for(int j = 0 ; j < N; j++)
			generate(times[j], inter[j], t1, ec[j]);
		fout.close();
	}
	cout << "disgraph generation completed." << '\n';
}

// A constructor
Rdiswgraph :: Rdiswgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random edge-weighted disconnected graph
void Rdiswgraph :: generate(int n, vector <pair <int, int> > &inter, Timer &t1, vector <int> &e, int l, int r)
{
	uniform_int_distribution <int> weights(l, r);
	m.clear();
	edlist.clear();
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(int i = 0; i < (int)inter.size(); i++)
	{
		uniform_int_distribution <int> ed(inter[i].first, inter[i].second);
		int gcount = 0;
		while(gcount != e[i])
		{
			int u = ed(generator);
			int v = ed(generator);
			if(u != v)
			{
				int x = min(u, v);
				int y = max(u, v);
				if(m[make_pair(x, y)] == 0)
				{
					int w = weights(generator);
					m[make_pair(x, y)] = 1;
					edlist.push_back(make_tuple(u, v, w));
					t1.time(1);
					gcount++;
				}
			}
		}
	}
	shuffle(edlist.begin(), edlist.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	fout << n << ' ';
	int ted = 0;
	for(int i = 0; i < (int)e.size(); i++)
		ted += e[i];
	fout << ted << '\n';
	for(auto i : edlist)
	{
		t1.time(1);
		fout << a[get <0> (i)] << ' ' << a[get <1> (i)] << ' ' << get <2> (i) << '\n';
	}
}

// A function that generates disconnected edge-weighted graph test case files
void Rdiswgraph :: setCase(string &s, int T, int t, int n, int wl, int wr, int sz, string &folder_name)
{
	cout << "Generating diswgraph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		vector <vector <pair <int, int> > > inter(N);
		vector <vector <int> > ec(N); 
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			binomial_distribution <int> noc(times[j], 0.31);
			int nocc = noc(generator);
			set <int> bp;
			uniform_int_distribution <int> el(1, times[j]);
			bp.insert(times[j]);
			while((int)bp.size() < nocc)
			{
				int x = el(generator);
				bp.insert(x);
			}
			int l = 1, r;
			for(auto k : bp)
			{
				r = k;
				inter[j].push_back(make_pair(l, r));
				l = r + 1;
			}
			for(auto k : inter[j])
			{
				int v = k.second - k.first + 1;
				ec[j].push_back(numOp :: giveRint(min(2 * v, (v * v - v) / 2)));
				tcnt += *ec[j].rbegin();
			}
		}
		Timer t1(2 * tcnt);
		for(int j = 0 ; j < N; j++)
			generate(times[j], inter[j], t1, ec[j], wl, wr);
		fout.close();
	}
	cout << "diswgraph generation completed." << '\n';
}

// A constructor
Rdisvwgraph :: Rdisvwgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random vertex weighted disconnected graph
void Rdisvwgraph :: generate(int n, vector <pair <int, int> > &inter, Timer &t1, vector <int> &e, int l, int r)
{
	uniform_int_distribution <int> weights(l, r);
	for(int i = 1; i < n + 1; i++)
		fout << weights(generator) << ' ';
	cout << '\n';
	m.clear();
	edlist.clear();
	int a[n + 1];
	for(int i = 1; i < n + 1; i++)
		a[i] = i;
	shuffle(a + 1, a + n + 1, default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(int i = 0; i < (int)inter.size(); i++)
	{
		uniform_int_distribution <int> ed(inter[i].first, inter[i].second);
		int gcount = 0;
		while(gcount != e[i])
		{
			int u = ed(generator);
			int v = ed(generator);
			if(u != v)
			{
				int x = min(u, v);
				int y = max(u, v);
				if(m[make_pair(x, y)] == 0)
				{
					m[make_pair(x, y)] = 1;
					edlist.push_back(make_pair(u, v));
					t1.time(1);
					gcount++;
				}
			}
		}
	}
	shuffle(edlist.begin(), edlist.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	fout << n << ' ';
	int ted = 0;
	for(int i = 0; i < (int)e.size(); i++)
		ted += e[i];
	fout << ted << '\n';
	for(auto i : edlist)
	{
		t1.time(1);
		fout << a[i.first] << ' ' << a[i.second] << '\n';
	}
}

// A function that generates disconnected vertex weighted graph test case files
void Rdisvwgraph :: setCase(string &s, int T, int t, int n, int wl, int wr, int sz, string &folder_name)
{
	cout << "Generating disvwgraph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		vector <vector <pair <int, int> > > inter(N);
		vector <vector <int> > ec(N); 
		for(int j = 0; j < N; j++)
		{
			if(times[j] == 1)
				times[j]++;
			binomial_distribution <int> noc(times[j], 0.31);
			int nocc = noc(generator);
			set <int> bp;
			uniform_int_distribution <int> el(1, times[j]);
			bp.insert(times[j]);
			while((int)bp.size() < nocc)
			{
				int x = el(generator);
				bp.insert(x);
			}
			int l = 1, r;
			for(auto k : bp)
			{
				r = k;
				inter[j].push_back(make_pair(l, r));
				l = r + 1;
			}
			for(auto k : inter[j])
			{
				int v = k.second - k.first + 1;
				ec[j].push_back(numOp :: giveRint(min(2 * v, (v * v - v) / 2)));
				tcnt += *ec[j].rbegin();
			}
		}
		Timer t1(2 * tcnt);
		for(int j = 0 ; j < N; j++)
			generate(times[j], inter[j], t1, ec[j], wl, wr);
		fout.close();
	}
	cout << "disvwgraph generation completed." << '\n';
}
