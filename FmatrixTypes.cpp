# include "FmatrixTypes.h"

// A constructor
Rfmatrix :: Rfmatrix()
{
	g = 0.0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random floating point matrix based on distribution
void Rfmatrix :: generate(int n, int m, int d, Timer &t1, float l, float r)
{
	FileOp :: fixOutprecision(fout);
	if(d == 0)
	{
		uniform_real_distribution <float> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < m; j++)
			{
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 3)
	{
		uniform_real_distribution <float> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 4)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		float sd = sqrt((mean - l) * (r - mean));
		normal_distribution <float> distribution(mean, sd);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + fmod(r - l + 1 + g, (r - l + 1)) << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 5)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		float cnt = sqrt((mean - l) * (r - mean));
		gamma_distribution <float> distribution(mean, cnt);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + fmod(r - l + 1 + g, (r - l + 1))<< ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 6)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		exponential_distribution <float> distribution(1.0 / mean);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + fmod(r - l + 1 + g, (r - l + 1)) << ' ';
				t1.time(1);
			}
			fout << '\n';
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
				g = distribution(generator);
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
}

// A function that generates a floating point matrix test case files
void Rfmatrix :: setCase(string &s, int T, int t, int m1, int m2, int n, float l, float r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating fmatrix test files: " << '\n';
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
	cout << "fmatrix generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rfmatrix :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (float)1.5, neg);
	return dist;
}

// A constructor
Rsqfmatrix :: Rsqfmatrix()
{
	g = 0.0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random floating point square matrix based on distribution
void Rsqfmatrix :: generate(int n, int m, int d, Timer &t1, float l, float r)
{
	FileOp :: fixOutprecision(fout);
	if(d == 0)
	{
		uniform_real_distribution <float> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0 ; j < m; j++)
			{
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 3)
	{
		uniform_real_distribution <float> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 4)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		float sd = sqrt((mean - l) * (r - mean));
		normal_distribution <float> distribution(mean, sd);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + fmod(r - l + 1 + g, (r - l + 1)) << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 5)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		float cnt = sqrt((mean - l) * (r - mean));
		gamma_distribution <float> distribution(mean, cnt);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + fmod(r - l + 1 + g, (r - l + 1))<< ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
	else if(d == 6)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		exponential_distribution <float> distribution(1.0 / mean);
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				g = distribution(generator);
				fout << l + fmod(r - l + 1 + g, (r - l + 1)) << ' ';
				t1.time(1);
			}
			fout << '\n';
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
				g = distribution(generator);
				fout << g << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	}
}

// A function that generates floating point square matrix test case files
void Rsqfmatrix :: setCase(string &s, int T, int t, int n, float l, float r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating fmatrix test files: " << '\n';
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
	cout << "fmatrix generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rsqfmatrix :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (float)1.5, neg);
	return dist;
}
