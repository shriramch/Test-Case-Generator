# include "spString.h"

// A constructor
Rlint :: Rlint()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random long integer
void Rlint :: generate(int n, Timer &t1)
{
	uniform_int_distribution <int> distribution(0, 9);
	int c = distribution(generator);
	fout << 1 + c % 9;
	t1.time(1);
	for(int i = 1; i < n; i++)
	{
		c = distribution(generator);
		fout << c;
		t1.time(1);
	}
	fout << '\n';
}

// A function that generates long integer test case files
void Rlint :: setCase(string &s, int T, int t, int n, int v, int sz, string &folder_name)
{
	cout << "Generating lint test files: " << '\n';
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
		for(int j = 0; j < N; j++)
		{
			if(v)
				fout << times[j] << '\n';
			generate(times[j], t1);
		}
		fout.close();
	}
	cout << "lint generation completed." << '\n';
}

// A constructor
Rrbseq :: Rrbseq()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random bracket sequence 
void Rrbseq :: generate(int n, Timer &t1)
{
	uniform_int_distribution <int> distribution(0, 1);
	int bal = 0;
	for(int i = 0; i < n; i++)
	{
		if(bal == 0)
		{
			fout << "(";
			bal++;
			t1.time(1);
		}
		else if(bal == n - i)
		{
			fout << ")";
			bal--;
			t1.time(1);
		}
		else
		{
			int g = distribution(generator);
			if(g)
			{
				fout << "(";
				bal++;
				t1.time(1);
			}
			else
			{
				fout << ")";
				bal--;
				t1.time(1);
			}
		}
	}
	fout << '\n';
}

// A function that generates random bracket sequence test case files
void Rrbseq :: setCase(string &s, int T, int t, int n, int v, int sz, string &folder_name)
{
	cout << "Generating rbseq test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
		{
			if(times[j] % 2)
			{
				times[j]--;
				if(times[j] == 0)
					times[j] += 2;
			}
			tcnt += times[j];
		}
		Timer t1(tcnt);
		for(int j = 0; j < N; j++)
		{
			if(v)
				fout << times[j] << '\n';
			generate(times[j], t1);
		}
		fout.close();
	}
	cout << "rbseq generation completed." << '\n';
}
