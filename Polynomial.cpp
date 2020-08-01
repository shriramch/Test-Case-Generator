# include "Polynomial.h"

// A constructor
Rpolynomial :: Rpolynomial()
{
	N = d = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random polynomial
void Rpolynomial :: generate(int n, Timer &t1, int l, int r)
{
	double f = (float)(rand() % 12);
	m.clear();
	discrete_distribution <int> d1{f, 24.0};
	uniform_int_distribution <int> distribution(l, r);
	for(int i = 0; i < n + 1; i++)
	{
		int x = d1(generator);
		if(x)
		{
			int coeff = distribution(generator);
			m[i] = coeff;
		}
		t1.time(1);
	}
	fout << m.size() << '\n';
	for(int i = 0; i < n + 1; i++)
	{
		if(m.find(i) != m.end())
		{
			fout << i << ' ' << m[i];
			if(d)
				fout << '\n';
			else
				fout << " \n"[i == n];
		}
		t1.time(1);
	}
}

// A function that generates polynomial test case files
void Rpolynomial :: setCase(string &s, int T, int t, int n, int l, int r, int sz, int D, string &folder_name)
{
	d = D;
	int pt = FileOp :: printT(t);
	cout << "Generating polynomial test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		if(pt)
			fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += (times[j] + 1);
		Timer t1(2 *tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "polynomial generation completed." << '\n';
}

// A constructor
Rfpolynomial :: Rfpolynomial()
{
	N = d = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random floating point polynomial
void Rfpolynomial :: generate(int n, Timer &t1, float l, float r)
{
	double f = (float)(rand() % 12);
	m.clear();
	discrete_distribution <int> d1{f, 24.0};
	uniform_real_distribution <float> distribution(l, r);
	for(int i = 0; i < n + 1; i++)
	{
		int x = d1(generator);
		if(x)
		{
			float coeff = distribution(generator);
			m[i] = coeff;
		}
		t1.time(1);
	}
	fout << m.size() << '\n';
	for(int i = 0; i < n + 1; i++)
	{
		if(m.find(i) != m.end())
		{
			fout << i << ' ' << m[i];
			if(d)
				fout << '\n';
			else
				fout << " \n"[i == n];
		}
		t1.time(1);
	}
}

// A function that generates floating point polynomial test case files
void Rfpolynomial :: setCase(string &s, int T, int t, int n, float l, float r, int sz, int D, string &folder_name)
{
	d = D;
	int pt = FileOp :: printT(t);
	FileOp :: fixOutprecision(fout);
	cout << "Generating fpolynomial test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		N = times.size();
		if(pt)
			fout << N << '\n';
		int tcnt = 0;
		for(int j = 0; j < N; j++)
			tcnt += (times[j] + 1);
		Timer t1(2 *tcnt);
		for(int j = 0; j < N; j++)
		{
			fout << times[j] << ' ';
			generate(times[j], t1, l, r);
		}
		fout.close();
	}
	cout << "fpolynomial generation completed." << '\n';
}
