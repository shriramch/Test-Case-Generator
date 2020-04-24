# include "String.h"

// A constructor
Rstring :: Rstring()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random string
void Rstring :: generate(int n, Timer &t1)
{
	vector <int> chars;
	Distribution :: FillArray(chars, n, 97, 122, false, t1);
	for(int i = 0; i < n; i++)
	{;
		fout << (char)chars[i];
		t1.time(1);
	}
	fout << '\n';
}

// A function generates string test case files
void Rstring :: setCase(string &s, int T, int t, int n, int v, int sz, string &folder_name)
{
	cout << "Generating string test files: " << '\n';
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
			if(v)
				fout << times[j] << '\n';
			generate(times[j], t1);
		}
		fout.close();
	}
	cout << "string generation completed." << '\n';
}
