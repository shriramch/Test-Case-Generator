# include "lSumInt.h"

// A constructor
Rlsumint :: Rlsumint()
{
	n = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a uniformly random integer
void Rlsumint :: generate(int l, int r)
{
	uniform_int_distribution <int> distribution(l, r);
	n = distribution(generator);
}

// A function that generates bounded sum integer list test case files
void Rlsumint :: setCase(string &s, int T, int t, int N, int l, int r, string &folder_name)
{
	cout << "Generating lsumint test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> out;
		int left = N;
		while((int)out.size() < t)
		{
			generate(l, min(left, r));
			left -= n;
			out.push_back(n);
			if(left < l)
				break;
		}
		int T = out.size();
		Timer t1(T);
		fout << T << '\n';
		for(int i = 0; i < T; i++)
		{
			t1.time(1);
			fout << out[i] << '\n';
		}
		fout.close();
	}
	cout << "lsumint generation completed." << '\n';
}
