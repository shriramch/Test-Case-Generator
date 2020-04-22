# include "Coordinates.h"

// A constructor
Rcoordinates :: Rcoordinates()
{
	N = g = h = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random set of coordinates by given distribution
void Rcoordinates :: generate(int n, int d, Timer &t1, int l1, int r1, int l2, int r2)
{
	if(d == 0)
	{
		uniform_int_distribution <int> d1(l1, r1);
		uniform_int_distribution <int> d2(l2, r2);
		g = d1(generator);
		h = d2(generator);
		for(int i = 0; i < n; i++)
		{
			fout << g << ' ' << h << '\n';
			t1.time(1);
		}
	}
	else if(d == 1)
	{
		g = l1;
		h = l2;
		for(int i = 0; i < n; i++)
		{
			fout << g << ' ' << h << '\n';
			t1.time(1);
		}
	}
	else if(d == 2)
	{
		g = r1;
		h = r2;
		for(int i = 0; i < n; i++)
		{
			fout << g << ' ' << h << '\n';
			t1.time(1);
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> d1(l1, r1);
		uniform_int_distribution <int> d2(l2, r2);
		for(int i = 0; i < n; i++)
		{
			g = d1(generator);
			h = d2(generator);
			fout << g << ' ' << h << '\n';
			t1.time(1);
		}
	}
	else if(d == 7)
	{
		int p = rand() % 101;
		binomial_distribution <int> d1((l1 + r1) / 2, p / 100.0);
		binomial_distribution <int> d2((l2 + r2) / 2, p / 100.0);
		for(int i = 0; i < n; i++)
		{
			g = d1(generator);
			h = d2(generator);
			fout << l1 + g % (r1 - l1 + 1) << ' ' << l2 + h % (r2 - l2 + 1) << '\n';
			t1.time(1);
		}
	}
	else if(d == 8)
	{

		uniform_real_distribution <float> d1(l1, r1);
		uniform_real_distribution <float> d2(l2, r2);
		int mean1 = d1(generator);
		int mean2 = d2(generator);
		poisson_distribution <int> dist1(mean1);
		poisson_distribution <int> dist2(mean2);
		for(int i = 0; i < n; i++)
		{
			g = dist1(generator);
			h = dist2(generator);
			fout << l1 + g % (r1 - l1 + 1) << ' ' << l2 + g % (r2 - l2 + 1) << '\n';
			t1.time(1);
		}
	}
	else if(d == 9)
	{
		uniform_real_distribution <float> d1(l1, r1);
		float mid = d1(generator);
		array <float, 3> intervals1 {l1 * 1.0, mid, r1 * 1.0};
  		array <float, 3> weights1 {10.0, 1.0, 10.0};
		piecewise_linear_distribution <float> distribution1(intervals1.begin(), intervals1.end(), weights1.begin());
		uniform_real_distribution <float> d2(l2, r2);
		mid = d2(generator);
		array <float, 3> intervals2 {l2 * 1.0, mid, r2 * 1.0};
  		array <float, 3> weights2 {10.0, 1.0, 10.0};
		piecewise_linear_distribution <float> distribution2(intervals2.begin(), intervals2.end(), weights2.begin());
		for(int i = 0; i < n; i++)
		{
			g = l1 + ((int)(distribution1(generator))) % (r1 - l1 + 1);
			g = l2 + ((int)(distribution2(generator))) % (r2 - l2 + 1);
			fout << g << ' ' << h << '\n';
			t1.time(1);
		}
	}
	fout << '\n';
}

// A function that generates coordinate test case files
void Rcoordinates :: setCase(string &s, int T, int t, int n, int l1, int r1, int l2, int r2, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating coordinate test files: " << '\n';
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
			generate(times[j], dist[j], t1, l1, r1, l2, r2);
		}
		fout.close();
	}
	cout << "coordinate generation completed." << '\n';
}

// A function that sets distribution for all test case files
vector <int> Rcoordinates :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}

// A constructor
Rucoordinates :: Rucoordinates()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random set of unique coordinates
void Rucoordinates :: generate(int n, Timer &t1, int l1, int r1, int l2, int r2)
{
	g.clear();
	h.clear();
	uniform_int_distribution <int> distribution1(l1, r1);
	uniform_int_distribution <int> distribution2(l2, r2);
	while((int)g.size() < n)
	{
		int t = g.size();
		int rn = distribution1(generator);
		g.insert(rn);
		if((int)g.size() > t)
		{
			t1.time(1);
			fout << rn << ' ';
			t = h.size();
			while((int)h.size() == t)
			{
				rn = distribution2(generator);
				h.insert(rn);
			}
			t1.time(1);
			fout << rn << '\n';
		}
	}
	fout << '\n';
}

// A function that generates unique coordinate test case files
void Rucoordinates :: setCase(string &s, int T, int t, int n, int l1, int r1, int l2, int r2, int sz, string &folder_name)
{
	cout << "Generating ucoordinates test files: " << '\n';
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
			generate(times[j], t1, l1, r1, l2, r2);
		}
		fout.close();
	}
	cout << "ucoordinates generation completed." << '\n';
}
