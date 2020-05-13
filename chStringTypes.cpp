# include "chStringTypes.h"

// A constructor
Rchar_string :: Rchar_string()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a string made from given character set
void Rchar_string :: generate(int n, Timer &t1, string s)
{
	vector <int> chars;
	Distribution :: FillArray(chars, n, 0, (int)s.size() - 1, false, t1);
	for(int i = 0; i < n; i++)
	{
		fout << s[chars[i]];
		t1.time(1);
	}
	fout << '\n';
}

// A function that generates strings made from given character set test case files 
void Rchar_string :: setCase(string &s, int T, int t, int n, string S, int v, int sz, string &folder_name)
{
	cout << "Generating char_string test files: " << '\n';
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
			generate(times[j], t1, S);
		}
		fout.close();
	}
	cout << "char_string generation completed." << '\n';
}

// A constructor
R01string :: R01string()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random 01-string
void R01string :: generate(int n, Timer &t1)
{
	vector <int> chars;
	Distribution :: FillArray(chars, n, 0, 1, false, t1);
	for(int i = 0; i < n; i++)
	{
		fout << chars[i];
		t1.time(1);
	}
	fout << '\n';
}

// A function that generates 01-string test case files
void R01string :: setCase(string &s, int T, int t, int n, int v, int sz, string &folder_name)
{
	cout << "Generating 01string test files: " << '\n';
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
	cout << "01string generation completed." << '\n';
}

// A constructor
Rchar_pair :: Rchar_pair()
{
	N = 0;
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a pair of char_strings
void Rchar_pair :: generate(int n, Timer &t1, string S)
{
	vector <vector <int> > chars(2);
	Distribution :: FillArray(chars[0], n, 0, (int)S.size() - 1, false, t1);
	Distribution :: FillArray(chars[1], n, 0, (int)S.size() - 1, false, t1);	
	for(int j = 0; j < 2; j++)
	{
		for(int i = 0; i < n; i++)
		{
			fout << S[chars[j][i]];
			t1.time(1);
		}
		fout << '\n';
	}
}

// A function that generates pair of char_string test case files
void Rchar_pair :: setCase(string &s, int T, int t, int n, string S, int v, int sz, string &folder_name)
{
	cout << "Generating char_pair test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n / 2, sz);
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
			generate(times[j], t1, S);
		}
		fout.close();
	}
	cout << "char_pair generation completed." << '\n';
}

// A constructor
Rchar_array :: Rchar_array()
{
	generator.seed(system_clock :: now().time_since_epoch().count());
}

// A function that generates a random array of char_strings
void Rchar_array :: generate(Timer &t1, string s, int m, int n, int v)
{
	fout << m;
	if(v)
		fout << ' ' << n;
	fout << '\n';
	vector <vector <int> > chars(m);
	for(int i = 0; i < m; i++)
		Distribution :: FillArray(chars[i], n, 0, (int)s.size() - 1, false, t1);
	for(int j = 0; j < m; j++)
	{	
		for(int i = 0; i < n; i++)
		{
			fout << s[chars[j][i]];
			t1.time(1);
		}
		fout << '\n';
	}
}

// A function that generates array of char_string test case files
void Rchar_array :: setCase(string &s, int T, int t, int n, string S, int v, int sz, string &folder_name)
{
	cout << "Generating char_array test files: " << '\n';
	for(int i = 0; i < T; i++)
	{
		FileOp :: setFile(folder_name, s, i, fout);
		vector <int> times = numOp :: giveRints(t, n, sz);
		fout << times.size() << '\n';
		N.clear();
		M.clear();
		int tcnt = 0;
		for(int j = 0; j < (int)times.size(); j++)
		{
			uniform_int_distribution <int> distribution(1, floor(sqrt(times[j])));
			int m = distribution(generator);
			M.push_back(m);
			N.push_back(times[j] / m);
			tcnt += M[j] * N[j];
		}
		Timer t1(2 * tcnt);
		for(int j = 0; j < (int)times.size(); j++)
			generate(t1, S, M[j], N[j], v);
		fout.close();
	}
	cout << "char_array generation completed." << '\n';
}
