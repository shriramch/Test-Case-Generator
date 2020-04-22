# include "DenseGraph.h"

// A constructor
Rdensegraph :: Rdensegraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}
//////
// A function that generates a random dense graph
void Rdensegraph :: generate(int n, Timer &t1, int d, float ro)
{
	bool a[n][n];
	if(ro == -1)
	{
		array <float, 3> intervals {0.0, 0.7, 1.0};
		array <float, 3> weights {0.2, 10.0, 0.2};
		piecewise_linear_distribution <float> roset(intervals.begin(), intervals.end(), weights.begin());
		ro = roset(generator);
	}
	discrete_distribution <int> edge {(double)(1 - ro), (double)(ro)};
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			a[i][j] = a[j][i] = edge(generator);
			t1.time(2);
		}
	for(int i = 0; i < n; i++)
	{
		a[i][i] = 0;
		t1.time(1);
	}
	if(d)
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				fout << a[i][j] << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	else
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				fout << a[i][j];
				t1.time(1);
			}
			fout << '\n';
		}
	
}

// A function that generates random dense graph test case files
void Rdensegraph :: setCase(string &s, int T, int t, int n, float ro, int d, int sz, string &folder_name)
{
	cout << "Generating dense_graph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j] * times[j];
		Timer t1(2 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, d, ro);
		}
		fout.close();
	}
	cout << "dense_graph generation completed." << '\n';
}

// A constructor
Rdensedgraph :: Rdensedgraph()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random dense digraph
void Rdensedgraph :: generate(int n, Timer &t1, int d, float ro)
{
	bool a[n][n];
	if(ro == -1)
	{
		array <float, 3> intervals {0.0, 0.7, 1.0};
		array <float, 3> weights {0.2, 10.0, 0.2};
		piecewise_linear_distribution <float> roset(intervals.begin(), intervals.end(), weights.begin());
		ro = roset(generator);
	}
	discrete_distribution <int> edge {(double)(1 - ro), (double)(ro)};
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
		{
			a[i][j] = edge(generator);
			t1.time(1);
		}
	for(int i = 1; i < n; i++)
		for(int j = 0; j < i; j++)
		{
			a[i][j] = rand() % 2;
			t1.time(1);
		}
	for(int i = 0; i < n; i++)
	{
		a[i][i] = 0;
		t1.time(1);
	}
	if(d)
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				fout << a[i][j] << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
	else
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				fout << a[i][j];
				t1.time(1);
			}
			fout << '\n';
		}	
}

// A function that generates random dense digraph test case files
void Rdensedgraph :: setCase(string &s, int T, int t, int n, float ro, int d, int sz, string &folder_name)
{
	cout << "Generating dense_dgraph test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += times[j] * times[j];
		Timer t1(2 * tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << '\n';
			generate(times[j], t1, d, ro);
		}
		fout.close();
	}
	cout << "dense_dgraph generation completed." << '\n';
}
