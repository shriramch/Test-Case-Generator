# include "Perm.h"

// A constructor
Rperm :: Rperm()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random permutation
void Rperm :: generate(int n, Timer &t1)
{
	g.clear();
	for(int i = 1; i < n + 1; i++)
	{
		g.push_back(i);
		t1.time(1);
	}
}

// A function that generates permutation test case files
void Rperm :: setCase(string &s, int T, int t, int n, int sz, string &folder_name)
{
	cout << "Generating perm test files: " << '\n';
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
			generate(times[j], t1);
			shuffle(g.begin(), g.end(), default_random_engine(system_clock  :: now().time_since_epoch().count()));
			for(auto k : g)
			{
				fout << k << ' ';
				t1.time(1);
			}
			fout << '\n';
		}
		fout.close();
	}
	cout << "perm generation completed." << '\n';
}
