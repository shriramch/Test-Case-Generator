# include "MatrixTypes.h"

// A constructor
Rmatrix :: Rmatrix()
{
	g = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random matrix based on distribution
void Rmatrix :: generate(int n, int m, int d, Timer &t1, int l, int r)
{
	if(d == 0)
	{
		uniform_int_distribution <int> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << " \n"[j == m - 1];
				t1.time(1);	
			}
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
	else if(d == 7)
	{
		int p = rand() % 101;
		binomial_distribution <int> distribution((l + r) / 2, p / 100.0);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + g % (r - l + 1) << " \n"[j == m - 1];
				t1.time(1);	
			}
		}
	}
	else if(d == 8)
	{

		uniform_real_distribution <float> d1(l, r);
		poisson_distribution <int> distribution(d);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + g % (r - l + 1) << " \n"[j == m - 1];
				t1.time(1);
			}
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
			for(int j = 0; j < m; j++)
			{
				g = l + ((int)(distribution(generator))) % (r - l + 1);
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
}

// A function that generates random matrix test case files
void Rmatrix :: setCase(string &s, int T, int t, int m1, int m2, int n, int l, int r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating matrix test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		fout << times.size() << '\n';
		int tcnt = 0;
		N.clear();
		M.clear();
		for(int j = 0; j < (int)times.size(); j++)
		{
			int c = rand() % 2;
			if(c == 0)
			{
				float mmax = min(sqrt(times[j]), 1.0 * times[j] / m1);
				array <float, 2> intervals {1.0 * m2, mmax};
				array <float, 2> weights {0.1, 11.0};
				piecewise_linear_distribution <float> uid(intervals.begin(), intervals.end(), weights.begin());
				int mm = m2 + fmod(uid(generator), mmax - m2 + 1);
				M.push_back(mm);
				N.push_back(times[j]/mm);
			}
			else
			{
				float mmax = min(sqrt(times[j]), 1.0 * times[j] / m2);
				array <float, 2> intervals {1.0 * m1, mmax};
				array <float, 2> weights {0.1, 11.0};
				piecewise_linear_distribution <float> uid(intervals.begin(), intervals.end(), weights.begin());
				int nn = m1 + fmod(uid(generator), mmax - m1 + 1);
				N.push_back(nn);
				M.push_back(times[j]/nn);
			}
			tcnt += N[j] * M[j];
		}
		Timer t1(tcnt);
		vector <int> dist = setCaseDist(times.size(), d, neg);
		for(int j = 0; j < (int)times.size(); j++)
		{
			fout << N[j] << ' ' << M[j] << '\n';
			generate(N[j], M[j], dist[j], t1, l, r);
		}
		fout.close();
	}
	cout << "matrix generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rmatrix :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}

// A constructor
Rsqmatrix :: Rsqmatrix()
{
	g = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// a function that generates a random square matrix based on distribution
void Rsqmatrix :: generate(int n, int m, int d, Timer &t1, int l, int r)
{
	if(d == 0)
	{
		uniform_int_distribution <int> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << " \n"[j == m - 1];
				t1.time(1);	
			}
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
	else if(d == 3)
	{
		uniform_int_distribution <int> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
	else if(d == 7)
	{
		int p = rand() % 101;
		binomial_distribution <int> distribution((l + r) / 2, p / 100.0);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + g % (r - l + 1) << " \n"[j == m - 1];
				t1.time(1);	
			}
		}
	}
	else if(d == 8)
	{

		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		poisson_distribution <int> distribution(mean);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + g % (r - l + 1) << " \n"[j == m - 1];
				t1.time(1);
			}
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
			for(int j = 0; j < m; j++)
			{
				g = l + ((int)(distribution(generator))) % (r - l + 1);
				fout << g << " \n"[j == m - 1];
				t1.time(1);
			}
		}
	}
}

// A function that generates square matrix test case files
void Rsqmatrix :: setCase(string &s, int T, int t, int n, int l, int r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating sqmatrix test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		fout << times.size() << '\n';
		int tcnt = 0;
		N.clear();
		for(int j = 0; j < (int)times.size(); j++)
		{
			N.push_back((int)(sqrt(times[j])));
			tcnt += N[j] * N[j];
		}
		Timer t1(tcnt);
		vector <int> dist = setCaseDist(times.size(), d, neg);
		for(int j = 0; j < (int)times.size(); j++)
		{
			fout << N[j] << '\n';
			generate(N[j], N[j], dist[j], t1, l, r);
		}
		fout.close();
	}
	cout << "sqmatrix generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rsqmatrix :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (int)1, neg);
	return dist;
}
