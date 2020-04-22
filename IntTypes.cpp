# include "IntTypes.h"

// A constructor
Rint :: Rint()
{
	n = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a uniformly random integer
void Rint :: generate(int l, int r)
{
	uniform_int_distribution <int> distribution(l, r);
	n = distribution(generator);
}

// A function that generates integer test case files
void Rint :: setCase(string &s, int T, int t, int l, int r, string &folder_name)
{
	cout << "Generating int test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		int times = numOp :: giveRint(t);
		fout << times << '\n';
		Timer t1(times);
		for(int j = 0; j < times; j++)
		{
			generate(l, r);
			fout << n << '\n';
			t1.time(1);
		}
		fout.close();
	}
	cout << "int generation completed." << '\n';
}

// A constructor
Rpair :: Rpair()
{
	a = b = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a pair of uniformly random integers
void Rpair :: generate(int l, int r)
{
	uniform_int_distribution <int> distribution(l, r);
	a = distribution(generator);
	b = distribution(generator);
}

// A function that generates pair test case files
void Rpair :: setCase(string &s, int T, int t, int l, int r, string &folder_name)
{
	cout << "Generating pair test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		int times = numOp :: giveRint(t);
		fout << times << '\n';
		Timer t1(2 * times);
		for(int j = 0; j < times; j++)
		{
			generate(l, r);
			fout << a << ' ' << b << '\n';
			t1.time(2);
		}
		fout.close();
	}
	cout << "pair generation completed." << '\n';
}
