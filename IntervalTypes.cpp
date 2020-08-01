# include "IntervalTypes.h"

// A constructor
Rintervals :: Rintervals()
{
	a = b = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random interval
void Rintervals :: generate(int l, int r)
{
	uniform_int_distribution <int> d1(l, r - 1);
	a = d1(generator);
	uniform_int_distribution <int> d2(a, r);
	b = d2(generator);
}

// A function that generates interval test case files
void Rintervals :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	int pt = FileOp :: printT(t);
	cout << "Generating interval test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		if(pt)
			fout << times.size() << '\n';
		int tcnt = 0;
		for(int j = 0; j < (int)times.size(); j++)
			tcnt += times[j];
		Timer t1(2 * tcnt);
		for(int j = 0; j < (int)times.size(); j++)
		{
			fout << times[j] << '\n';
			for(int k = 0; k < times[j]; k++)
			{
				generate(l, r);
				fout << a << ' ' << b << '\n';
				t1.time(2);
			}
		}
		fout.close();
	}
	cout << "interval generation completed." << '\n';
}

// A constructor
Ruintervals :: Ruintervals()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random unique interval set
void Ruintervals :: generate(int n, Timer &t1, int l, int r)
{
	g.clear();
	uniform_int_distribution <int> d1(l, r);
	while((int)g.size() < 2 * n)
	{
		int t = g.size();
		int rn = d1(generator);
		g.insert(rn);
		if((int)g.size() > t)
			t1.time(1);
	}
	vector <int> gg;
	for(auto i : g)
	{
		gg.push_back(i);
		t1.time(1);
	}
	shuffle(gg.begin(), gg.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(int i = 0; i < (int)gg.size(); i += 2)
	{
		int x = gg[i], y = gg[i + 1];
		fout << min(x, y) << ' ' << max(x, y) << '\n';
		t1.time(2);
	}
}

// A function that generates unique interval test case files
void Ruintervals :: setCase(string &s, int T, int t, int n, int l, int r, int sz, string &folder_name)
{
	int pt = FileOp :: printT(t);
	cout << "Generating uintervals test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		if(pt)
			fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(6 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "uintervals generation completed." << '\n';
}

// A constructor
Rpartition :: Rpartition()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random partition
void Rpartition :: generate(int n, Timer &t1, int l, int r)
{
	g.clear();
	uniform_int_distribution <int> d1(l, r - 1);
	while((int)g.size() < n - 1)
	{
		int t = g.size();
		int rn = d1(generator);
		g.insert(rn);
		if((int)g.size() > t)
			t1.time(2);
	}
	vector <int> gg;
	gg.push_back(l);
	t1.time(4);
	for(auto i : g)
	{
		gg.push_back(i);
		gg.push_back(i + 1);
		t1.time(2);
	}
	gg.push_back(r);
	vector <pair <int, int> > ggg;
	for(int i = 0; i < (int)gg.size(); i += 2)
	{
		int x = gg[i], y = gg[i + 1];
		ggg.push_back(make_pair(x, y));
		t1.time(2);
	}
	shuffle(ggg.begin(), ggg.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
	for(auto i : ggg)
	{
		t1.time(1);
		fout << i.first << ' ' << i.second << '\n';
	}
}

// A function that generates partition test case files
void Rpartition :: setCase(string &s, int T, int t, int l, int r, int sz, string &folder_name)
{
	int pt = FileOp :: printT(t);
	cout << "Generating partition test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, (r - l) / 11, sz);
		N = times.size();
		if(pt)
			fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j];
		Timer t1(7 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "partition generation completed." << '\n';
}
