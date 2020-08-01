# include "FloatTypes.h"

// A constructor
Rfloat :: Rfloat()
{
	n = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a uniformly random floating point number
void Rfloat :: generate(float l, float r)
{
	uniform_real_distribution <float> distribution(l, r);
	n = distribution(generator);
}

// A function that generates floating point test case files
void Rfloat :: setCase(string &s, int T, int t, float l, float r, string &folder_name)
{
	int pt = FileOp :: printT(t);
	FileOp :: fixOutprecision(fout);
	cout << "Generating float test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		int times = numOp :: giveRint(t);
		if(pt)
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
	cout << "float generation completed." << '\n';
}

// A constructor
Rfpair :: Rfpair()
{
	a = b = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a uniformly random floating point pair
void Rfpair :: generate(float l, float r)
{
	uniform_real_distribution <float> distribution(l, r);
	a = distribution(generator);
	b = distribution(generator);
}

// A function that generates floating point pair test case files
void Rfpair :: setCase(string &s, int T, int t, float l, float r, string &folder_name)
{
	int pt = FileOp :: printT(t);
	FileOp :: fixOutprecision(fout);
	cout << "Generating fpair test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		int times = numOp :: giveRint(t);
		if(pt)
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
	cout << "fpair generation completed." << '\n';
}
