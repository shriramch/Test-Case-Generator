# include "FarrayTypes.h"

// A constructor
Rfarray :: Rfarray()
{
	N = 0;
	g = 0.0;
}

// A function that generates a random floating point array based on distribution 
void Rfarray :: generate(int n, int d, Timer &t1, float l, float r)
{
	FileOp :: fixOutprecision(fout);
	default_random_engine generator(system_clock :: now().time_since_epoch().count());
	if(d == 0)
	{
		uniform_real_distribution <float> distribution(l, r);
		g = distribution(generator);
		for(int i = 0; i < n; i++)
		{
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 1)
	{
		g = l;
		for(int i = 0; i < n; i++)
		{
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 2)
	{
		g = r;
		for(int i = 0; i < n; i++)
		{
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 3)
	{
		uniform_real_distribution <float> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			fout << g << " \n"[i == n - 1];
			t1.time(1);
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
			g = distribution(generator);
			fout << l + fmod(g, (r - l + 1)) << " \n"[i == n - 1];
			t1.time(1);
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
			g = distribution(generator);
			fout << l + fmod(g, (r - l + 1))<< " \n"[i == n - 1];
			t1.time(1);
		}
	}
	else if(d == 6)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		exponential_distribution <float> distribution(1.0 / mean);
		for(int i = 0; i < n; i++)
		{
			g = distribution(generator);
			fout << l + fmod(g, (r - l + 1)) << " \n"[i == n - 1];
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
			g = distribution(generator);
			fout << g << " \n"[i == n - 1];
			t1.time(1);
		}
	}
}

// A function that generates floating point array test case files
void Rfarray :: setCase(string &s, int T, int t, int n, float l, float r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating farray test files: " << '\n';
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
	cout << "farray generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rfarray :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (float)1.5, neg);
	return dist;
}

// A constructor
Rsfarray :: Rsfarray()
{
	N = 0;
	rn = 0.0;
	default_random_engine generator(system_clock :: now().time_since_epoch().count());	
}

// A function that generates a sorted floating point array
void Rsfarray :: generate(int n, int d, Timer &t1, float l, float r)
{
	FileOp :: fixOutprecision(fout);
	g.clear();
	if(d == 0)
	{
		uniform_real_distribution <float> distribution(l, r);
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
		uniform_real_distribution <float> distribution(l, r);
		for(int i = 0; i < n; i++)
		{
			rn = distribution(generator);
			g.push_back(rn);
			t1.time(1);
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
			rn = distribution(generator);
			g.push_back(l + fmod(rn, (r - l + 1)));
			t1.time(1);
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
			rn = distribution(generator);
			g.push_back(l + fmod(rn, (r - l + 1)));
			t1.time(1);
		}
	}
	else if(d == 6)
	{
		uniform_real_distribution <float> d1(l, r);
		float mean = d1(generator);
		exponential_distribution <float> distribution(1.0 / mean);
		for(int i = 0; i < n; i++)
		{
			rn = distribution(generator);
			g.push_back(l + fmod(rn, r - l + 1));
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
			rn = distribution(generator);
			g.push_back(rn);
			t1.time(1);
		}
	}
}

// A function that generates sorted floating point array test case files 
void Rsfarray :: setCase(string &s, int T, int t, int n, float l, float r, int d, bool neg, int sz, string &folder_name)
{
	cout << "Generating sfarray test files: " << '\n';
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
			for(int k = 0; k < (int)g.size(); k++)
			{
				fout << g[k] << " \n"[i == n - 1];
				t1.time(1);
			}
		}
		fout.close();
	}
	cout << "sfarray generation completed." << '\n';
}

// A function that sets distribution for all test cases
vector <int> Rsfarray :: setCaseDist(int n, int d, bool neg)
{
	Distribution d1;
	vector <int> dist;
	d1.setCaseDis(n, d, dist, (float)1.5, neg);
	return dist;
}
