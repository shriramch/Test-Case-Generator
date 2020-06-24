# include "Generator.h"

// A utility function to input a valid integer
int Generate :: giveInt(string x)
{
	cout << x;
	string ss;
	getline(cin, ss);
	if(ss == "---")
	{
		e1.setCaseError(-1);
		throw e1;
	}
	pair <int, bool> x1 = numOp :: ctnum(ss);
	if(!x1.second)
	{
		e1.setCaseError(1);
		throw e1;
	}
	return x1.first;
}

// A utility function to input range
int Generate :: giveInt(string x, int val)
{
	cout << x;
	string ss;
	getline(cin, ss);
	if(ss == "---")
	{
		e1.setCaseError(-1);
		throw e1;
	}
	if(ss == "b")
		return val;
	if(ss == "e")
		return val;
	pair <int, bool> x1 = numOp :: ctnum(ss);
	if(!x1.second)
	{
		e1.setCaseError(1);
		throw e1;
	}
	return x1.first;
}

// A utility function to input a valid floating point number
float Generate :: giveFloat(string x)
{
	cout << x;
	string ss;
	getline(cin, ss);
	if(ss == "---")
	{
		e1.setCaseError(-1);
		throw e1;
	}
	pair <float, bool> x1 = numOp :: ctf(ss);
	if(!x1.second)
	{
		e1.setCaseError(1);
		throw e1;
	}
	return x1.first;
}

// A utility function to input a valid string
string Generate :: giveString(string x)
{
	cout << x;
	string ss;
	getline(cin, ss);
	if(ss == "---")
	{
		e1.setCaseError(-1);
		throw e1;
	}
	return ss;
}

// A utility function to initialise data set
void Generate :: initialize()
{
	types.insert("int");
	types.insert("float");
	types.insert("pair");
	types.insert("fpair");
	types.insert("array");
	types.insert("farray");
	types.insert("darray");
	types.insert("key_darray");
	types.insert("sarray");
	types.insert("sfarray");
	types.insert("sdarray");
	types.insert("div_array");
	types.insert("perm");
	types.insert("string");
	types.insert("char_string");
	types.insert("01string");
	types.insert("char_pair");
	types.insert("char_array");
	types.insert("lint");
	types.insert("rbseq");
	types.insert("matrix");
	types.insert("fmatrix");
	types.insert("sqmatrix");
	types.insert("sqfmatrix");
	types.insert("intervals");
	types.insert("uintervals");
	types.insert("partition");
	types.insert("tree");
	types.insert("rtree");
	types.insert("wtree");
	types.insert("vwtree");
	types.insert("wrtree");
	types.insert("dense_graph");
	types.insert("dense_dgraph");
	types.insert("graph");
	types.insert("wgraph");
	types.insert("vwgraph");
	types.insert("conn_graph");
	types.insert("conn_wgraph");
	types.insert("conn_vwgraph");
	types.insert("disgraph");
	types.insert("diswgraph");
	types.insert("disvwgraph");
	types.insert("dgraph");
	types.insert("dwgraph");
	types.insert("dvwgraph");
	types.insert("dag");
	types.insert("wdag");
	types.insert("vwdag");
	types.insert("coordinates");
	types.insert("ucoordinates");
	types.insert("polynomial");
	types.insert("fpolynomial");
	types.insert("tuple");
	types.insert("tuple_array");
	types.insert("paramarray");
	types.insert("ptuple");
	types.insert("1");
	types.insert("2");
	types.insert("3");
	types.insert("4");
	types.insert("5");
	types.insert("6");
	types.insert("7");
	types.insert("8");
	types.insert("9");
	types.insert("10");
	types.insert("11");
	types.insert("12");
	types.insert("13");
	types.insert("14");
	types.insert("15");
	types.insert("16");
	types.insert("17");
	types.insert("18");
	types.insert("19");
	types.insert("20");
	types.insert("21");
	types.insert("22");
	types.insert("23");
	types.insert("24");
	types.insert("25");
	types.insert("26");
	types.insert("27");
	types.insert("28");
	types.insert("29");
	types.insert("30");
	types.insert("31");
	types.insert("32");
	types.insert("33");
	types.insert("34");
	types.insert("35");
	types.insert("36");
	types.insert("37");
	types.insert("38");
	types.insert("39");
	types.insert("40");
	types.insert("41");
	types.insert("42");
	types.insert("43");
	types.insert("44");
	types.insert("45");
	types.insert("46");
	types.insert("47");
	types.insert("48");
	types.insert("49");
	types.insert("50");
	types.insert("51");
	types.insert("52");
	types.insert("53");
	types.insert("101");
	types.insert("102");
	types.insert("103");
	types.insert("104");
}

// A utility function to check validity of input
template <class type>
	void Generate :: valid(type l, type r)
	{
		if(!(l == 1 && r == -1))
		{
			if(l > r)
			{
				e1.setCaseError(11);
				throw e1;
			}
			if(l <= 0)
				neg = true;
			else
				neg = false;
		}
	}

// A utility function to check validity of input
template <class type>
	void Generate :: valid(type l, type r, int n)
	{
		if(n <= 0)
		{
			e1.setCaseError(1001);
			throw e1;
		}
		if(l > r)
		{
			e1.setCaseError(11);
			throw e1;
		}
		int len = r - l + 1;
		if((int)len < 3 * n)
		{
			e1.setCaseError(11);
			throw e1;
		}
		if(l <= 0)
			neg = true;
		else
			neg = false;
	}

// A utility function to check validity of input
template <class type>
	void Generate :: valid(int m1, int m2, int n, type l, type r)
	{
		if(n <= 0 || m1 <= 0 || m2 <= 0)
		{
			e1.setCaseError(1001);
			throw e1;
		}
		if(m1 * m2 > n)
		{
			e1.setCaseError(11);
			throw e1;
		}
		valid(l, r);
	}

// A utility function to check validity of input
void Generate :: valid(int d, char r)
{
	if(!neg)
	{
		if(r == 'i')
		{
			if(!(d == -1 || d == 0 || d == 1 || d == 2 || d == 3 || d == 7 || d == 8 || d == 9))
			{
				e1.setCaseError(21);
				throw e1;
			}
		}
		else
		{
			if(!(d == -1 || d == 0 || d == 1 || d == 2 || d == 3 || d == 4 || d == 5 || d == 6 || d == 9))
			{
				e1.setCaseError(21);
				throw e1;
			}
		}
	}
	else
	{
		if(r == 'i')
		{
			if(!(d == -1 || d == 0 || d == 1 || d == 2 || d == 3 || d == 8 || d == 9))
			{
				e1.setCaseError(21);
				throw e1;
			}
		}
		else
		{
			if(!(d == -1 || d == 0 || d == 1 || d == 2 || d == 3 || d == 4 || d == 9))
			{
				e1.setCaseError(21);
				throw e1;
			}
		}
	}
}

// A utility function to check validity of input
void Generate :: valid(string s)
{
	int n = s.size();
	for(int i = 0; i < n; i++)
		if(s[i] < 33)
		{
			e1.setCaseError(101);
			throw e1;
		}
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(s[i] == s[j])
			{
				e1.setCaseError(101);
				throw e1;
			}
}

// A utility function to check validity of input
void Generate :: valid(int n)
{
	if(!(n == 0 || n == 1))
	{
		e1.setCaseError(1);
		throw e1;
	}
}

// A utility function to check validity of input
void Generate :: valid(float s)
{
	if(s != -1 && (s > 1 || s < 0))
	{
		e1.setCaseError(201);
		throw e1;
	}
}

// A utility function to check validity of input
void Generate :: valid(pair <int, int> lr, int k)
{
	if (k < lr.first || k > lr.second)
	{
		e1.setCaseError(101);
		throw e1;
	}
}

// A utility function to check validity of input
void Generate :: valid(int n, int l, int r, int fact)
{
	if(n <= 0 || fact <= 0)
	{
	 	e1.setCaseError(1001);
		throw e1;
	}
	if(l > r)
	{
		e1.setCaseError(11);
		throw e1;
	}
	int len = r - l + 1;
	if((int)len < 3 * fact * n)
	{
		e1.setCaseError(11);
		throw e1;
	}
	if(l <= 0)
		neg = true;
	else
		neg = false;
}

// A constructor
Generate :: Generate()
{
	e1.setCaseError(-1);
	initialize();
}

// A function to facilitate output generation
void Generate :: GenOutput(string fname, int T)
{
	string tt = numOp :: nts(T);
	GenOutput(fname, tt);
}

// A function to facilitate output generation
void Generate :: GenOutput(string fname, string tt)
{
	pair <int, bool> x = numOp :: ctnum(tt);
	if(x.second == false)
	{
		e1.setCaseError(1);
		throw e1;
	}
	int T = x.first;
	cout << "Please make sure that the code does not generate compile time and runtime errors. " << '\n';
	bool loop = false;
	fstream f1;
	do
	{
		cout << "C++ Solution code file name (make sure file name is a single word): ";
		string s;
		getline(cin, s);
		if(s == "---")
		{
			e1.setCaseError(2001);
			throw e1;
		}
		if(s.size() < 4 || s.substr(s.size() - 4, 4) != ".cpp")
			s += ".cpp";
		f1.open(s, ios :: in);
		if(!f1)
		{
			cout << "Error: file name not found. Please enter correct file name, or \"---\" to quit." << '\n' << '\n';
			loop = true;
		}
	}while(loop == true);
	string ocpp = fname + "_op_gen.cpp";
	fstream f2(ocpp, ios :: out);
	bool main_came = false, inside_main = false;
	while(!f1.eof())
	{
		string command;
		getline(f1, command, '\n');
		stringstream line(command),newline;
		string ch;
		while(line >> ch)
		{
			if(inside_main)
			{
				f2 << "freopen(argv[1], \"r\", stdin);" << '\n';
				f2 << "freopen(argv[2], \"w\", stdout);" << '\n';
				inside_main = false;
				main_came = false;
			}
			if(ch == "main()")
			{
				newline << " main(int argc, char *argv[])";
				main_came = true;
			}
			else
				newline << ' ' << ch;
			if(main_came && ch == "{")
				inside_main = true;
		}
		string nch = newline.str();
		f2 << nch << '\n';
	}
	f1.close();
	f2.close();
	string ifile = fname;
	string ofile = fname + "_op";
	string ofolder = "./" + ifolder_name + "/" + "output";
	const char *comm1 = ofolder.c_str();
	mkdir(comm1, 0777);
	cout << "Generating output files." << '\n';
	for(int i = 0; i < T; i++)
	{
		string t2 = numOp :: nts(i);
		string fnn = "./" + folder_name + "/" + ifile;
		string onn = ofolder + "/" + ofile;
		fnn += t2;
		onn += t2;
		fnn += ".txt";
		onn += ".txt";
		cout << "	Generating file " << onn << ": " << '\n';
		string str = "g++ ";
		str = str + ocpp + " -o t_file_" + numOp :: nts(i);
		const char *command1 = str.c_str();
		system(command1);
		str.clear();
		str = "./t_file_" + numOp :: nts(i) + ' ' + fnn + ' ' + onn;
		const char *command2 = str.c_str();
		system(command2);
		cout << " File " << onn << " Generated. " << '\n';
		str = "t_file_" + numOp :: nts(i);
		const char *command3 = str.c_str();
		remove(command3);
	}
	const char *command = ocpp.c_str();
	remove(command);
}

// A UI function to control generation of test cases
void Generate :: genfunc()
{
	cout << "Please refer to the manual for the keywords. At any point, enter \"---\" to quit generation." << '\n';
	string ptype = giveString("	Preset type : ");
	if(types.find(ptype) == types.end())
	{
		e1.setCaseError(3);
		throw e1;
	}
	string fname = giveString("	Test file name prefix: ");
	folder_name = "testfiles_" + fname;
	ifolder_name = folder_name;
	folder_name += "/input";
	const char *comm1 = ifolder_name.c_str();
	mkdir(comm1, 0777);
	comm1 = folder_name.c_str();
	mkdir(comm1, 0777);
	int T = giveInt("	Number of test files: ");
	int t = giveInt("	Maximum number of tests per file: ");
	int sz = giveInt("	Test case size (0 for randomized, 1 for large size): ");
	valid(sz);
	if(ptype == "int" || ptype == "1")
	{
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rint R;
		valid(l, r);
		R.setCase(fname, T, t, l, r, folder_name);
	}
	else if(ptype == "float" || ptype == "2")
	{
		float l = giveFloat("	Lower limit: ");
		float r = giveFloat("	Upper limit: ");
		valid(l, r);
		Rfloat R;
		R.setCase(fname, T, t, l, r, folder_name);
	}
	else if(ptype == "pair" || ptype == "3")
	{
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		int d = giveInt("	Fixed order? (1 for n2 <= n1, 0 otherwise): ");
		valid(l, r);
		valid(d);
		Rpair R;
		R.setCase(fname, T, t, l, r, folder_name, d);
	}
	else if(ptype == "fpair" || ptype == "4")
	{
		float l = giveFloat("	Lower limit: ");
		float r = giveFloat("	Upper limit: ");
		valid(l, r);
		Rfpair R;
		R.setCase(fname, T, t, l, r, folder_name);
	}
	else if(ptype == "array" || ptype == "5")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		valid(l, r);
		valid(d, 'i');
		Rarray R;
		R.setCase(fname, T, t, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "farray" || ptype == "6")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		float l = giveFloat("	Lower limit: ");
		float r = giveFloat("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		valid(l, r);
		valid(d, 'f');
		Rfarray R;
		R.setCase(fname, T, t, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "darray" || ptype == "7")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		valid(l, r, n);
		Rdarray R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "key_darray" || ptype == "8")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		int k = giveInt("	Key: ");
		valid(l, r, n);
		valid(make_pair(l, r), k);
		Rkey_darray R;
		R.setCase(fname, T, t, n, l, r, k, sz, folder_name);
	}
	else if(ptype == "sarray" || ptype == "9")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		valid(l, r);
		valid(d, 'i');
		Rsarray R;
		R.setCase(fname, T, t, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "sfarray" || ptype == "10")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		float l = giveFloat("	Lower limit: ");
		float r = giveFloat("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		valid(l, r);
		valid(d, 'f');
		Rsfarray R;
		R.setCase(fname, T, t, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "sdarray" || ptype == "11")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		valid(l, r, n);
		Rsdarray R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "div_array" || ptype == "12")
	{
		int n = giveInt("	Length of array (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		int fact = giveInt("	Common factor: ");
		valid(n, l, r, fact);
		Rdiv_array R;
		R.setCase(fname, T, t, n, l, r, fact, sz, folder_name);
	}
	else if(ptype == "perm" || ptype == "13")
	{
		int n = giveInt("	Length of permutation (over all test cases): ");
		Rperm R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "string" || ptype == "14")
	{
		int n = giveInt("	Length of string (over all test cases): ");
		int v = giveInt("	Display string length? (enter 0 (no) or 1 (yes)): ");
		valid(v);
		Rstring R;
		R.setCase(fname, T, t, n, v, sz, folder_name);
	}
	else if(ptype == "char_string" || ptype == "15")
	{
		int n = giveInt("	Length of string (over all test cases): ");
		string s = giveString("	Character set: ");
		int v = giveInt("	Display string length? (enter 0 (no) or 1 (yes)): ");
		Rchar_string R;
		valid(s);
		valid(v);
		R.setCase(fname, T, t, n, s, v, sz, folder_name);
	}
	else if(ptype == "01string" || ptype == "16")
	{
		int n = giveInt("	Length of string (over all test cases): ");
		int v = giveInt("	Display string length? (enter 0 (no) or 1 (yes)): ");
		R01string R;
		valid(v);
		R.setCase(fname, T, t, n, v, sz, folder_name);
	}
	else if(ptype == "char_pair" || ptype == "17")
	{
		int n = giveInt("	Length of string (over all test cases): ");
		string s = giveString("	Character set: ");
		int v = giveInt("	Display string length? (enter 0 (no) or 1 (yes)): ");
		Rchar_pair R;
		valid(s);
		valid(v);
		R.setCase(fname, T, t, n, s, v, sz, folder_name);
	}
	else if(ptype == "char_array" || ptype == "18")
	{
		int n = giveInt("	Length of string (over all test cases): ");
		string s = giveString("	Character set: ");
		int v = giveInt("	Display string length? (enter 0 (no) or 1 (yes)): ");
		Rchar_array R;
		valid(s);
		valid(v);
		R.setCase(fname, T, t, n, s, v, sz, folder_name);
	}
	else if(ptype == "lint" || ptype == "19")
	{
		int n = giveInt("	Length of integer (over all test cases): ");
		int v = giveInt("	Display integer length? (enter 0 (no) or 1 (yes)): ");
		Rlint R;
		valid(v);
		R.setCase(fname, T, t, n, v, sz, folder_name);
	}
	else if(ptype == "rbseq" || ptype == "20")
	{
		int n = giveInt("	Length of sequence (over all test cases): ");
		int v = giveInt("	Display sequence length? (enter 0 (no) or 1 (yes)): ");
		valid(v);
		Rrbseq R;
		R.setCase(fname, T, t, n, v, sz, folder_name);
	}
	else if(ptype == "matrix" || ptype == "21")
	{
		int m1 = giveInt("	Minimum number of rows: ");
		int m2 = giveInt("	Minimum number of columns: ");
		int n = giveInt("	Number of entries over (all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		Rmatrix R;
		valid(m1, m2, n, l, r);
		valid(d, 'i');
		R.setCase(fname, T, t, m1, m2, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "fmatrix" || ptype == "22")
	{
		int m1 = giveInt("	Minimum number of rows: ");
		int m2 = giveInt("	Minimum number of columns: ");
		int n = giveInt("	Number of entries over (all test cases): ");
		float l = giveFloat("	Lower limit: ");
		float r = giveFloat("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		Rfmatrix R;
		valid(m1, m2, n, l, r);
		valid(d, 'f');
		R.setCase(fname, T, t, m1, m2, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "sqmatrix" || ptype == "23")
	{
		int n = giveInt("	Number of entries over (all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		Rsqmatrix R;
		valid(l, r);
		valid(d, 'i');
		R.setCase(fname, T, t, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "sqfmatrix" || ptype == "24")
	{
		int n = giveInt("	Number of entries over (all test cases): ");
		float l = giveFloat("	Lower limit: ");
		float r = giveFloat("	Upper limit: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		Rsqfmatrix R;
		valid(l, r);
		valid(d, 'f');
		R.setCase(fname, T, t, n, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "intervals" || ptype == "25")
	{
		int n = giveInt("	Number of intervals (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		valid(l, r);
		Rintervals R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "uintervals" || ptype == "26")
	{
		int n = giveInt("	Number of intervals (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		valid(l, r, n);
		Ruintervals R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "partition" || ptype == "27")
	{
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		valid(l, r);
		Rpartition R;
		R.setCase(fname, T, t, l, r, sz, folder_name);
	}
	else if(ptype == "tree" || ptype == "28")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		Rtree R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "rtree" || ptype == "29")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		Rtree R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "wtree" || ptype == "30")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Upper limit of weight: ");
		int r = giveInt("	Upper limit of weight: ");
		valid(l, r);
		Rwtree R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "vwtree" || ptype == "31")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Upper limit of weight: ");
		int r = giveInt("	Upper limit of weight: ");
		valid(l, r);
		Rvwtree R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "wrtree" || ptype == "32")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Upper limit of weight: ");
		int r = giveInt("	Upper limit of weight: ");
		valid(l, r);
		Rrwtree R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "dense_graph" || ptype == "33")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		if(n > 2500)
		{
			e1.setCaseError(1);
			throw e1;
		}
		float ro = giveFloat("	Density: ");
		int d = giveInt("	String or matrix output (enter 0 or 1): ");
		valid(d);
		valid(ro);
		Rdensegraph R;
		R.setCase(fname, T, t, n, ro, d, sz, folder_name);
	}
	else if(ptype == "dense_dgraph" || ptype == "34")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		if(n > 2500)
		{
			e1.setCaseError(1);
			throw e1;
		}
		float ro = giveFloat("	Density: ");
		int d = giveInt("	String or matrix output (enter 0 or 1): ");
		valid(d);
		valid(ro);
		Rdensedgraph R;
		R.setCase(fname, T, t, n, ro, d, sz, folder_name);
	}
	else if(ptype == "graph" || ptype == "35")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		Rgraph R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "wgraph" || ptype == "36")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rwgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "conn_graph" || ptype == "37")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		Rconngraph R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "conn_wgraph" || ptype == "38")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rconnwgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "conn_vwgraph" || ptype == "39")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rconnvwgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "disgraph" || ptype == "40")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		Rdisgraph R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "diswgraph" || ptype == "41")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rdiswgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "disvwgraph" || ptype == "41")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rdisvwgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "vwgraph" || ptype == "43")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rvwgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "dgraph" || ptype == "44")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		Rdgraph R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "dwgraph" || ptype == "45")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rdwgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "dvwgraph" || ptype == "46")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rdvwgraph R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "dag" || ptype == "47")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		Rdag R;
		R.setCase(fname, T, t, n, sz, folder_name);
	}
	else if(ptype == "wdag" || ptype == "48")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rwdag R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "vwdag" || ptype == "49")
	{
		int n = giveInt("	Number of vertices (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		Rvwdag R;
		R.setCase(fname, T, t, n, l, r, sz, folder_name);
	}
	else if(ptype == "coordinates" || ptype == "50")
	{
		int n = giveInt("	Number of points (over all test cases): ");
		int x1 = giveInt("	Left limit of x coordinate: ");
		int x2 = giveInt("	Right limit of x coordinate: ");
		valid(x1, x2);
		int y1 = giveInt("	Left limit of y coordinate: ");
		int y2 = giveInt("	Right limit of y coordinate: ");
		int d = giveInt("	Distribution key (-1 for randomized) : ");
		valid(y1, y2);
		valid(d, 'i');
		Rcoordinates R;
		R.setCase(fname, T, t, n, x1, x2, y1, y2, d, neg, sz, folder_name);
	}
	else if(ptype == "ucoordinates" || ptype == "51")
	{
		int n = giveInt("	Number of points (over all test cases): ");
		int x1 = giveInt("	Left limit of x coordinate: ");
		int x2 = giveInt("	Right limit of x coordinate: ");
		valid(x1, x2, n);
		int y1 = giveInt("	Left limit of y coordinate: ");
		int y2 = giveInt("	Right limit of y coordinate: ");
		valid(y1, y2, n);
		Rucoordinates R;
		R.setCase(fname, T, t, n, x1, x2, y1, y2, sz, folder_name);
	}
	else if(ptype == "polynomial" || ptype == "52")
	{
		int n = giveInt("	Sum of degrees (over all test cases): ");
		int l = giveInt("	Coefficient lower limit: ");
		int r = giveInt("	Coefficient upper limit: ");
		int d = giveInt("	Output format (0 for single line, 1 for multiline): ");
		valid(l, r);
		valid(d, 'i');
		Rpolynomial R;
		R.setCase(fname, T, t, n, l, r, sz, d, folder_name);
	}
	else if(ptype == "fpolynomial" || ptype == "53")
	{
		int n = giveInt("	Sum of degrees (over all test cases): ");
		float l = giveFloat("	Coefficient lower limit: ");
		float r = giveFloat("	Coefficient upper limit: ");
		int d = giveInt("	Output format (0 for single line, 1 for multiline): ");
		valid(l, r);
		valid(d, 'i');
		Rfpolynomial R;
		R.setCase(fname, T, t, n, l, r, sz, d, folder_name);
	}
	else if(ptype == "tuple" || ptype == "101")
	{
		int nc = giveInt("	Number of elements in a tuple: ");
		vector <int> l(nc), r(nc);
		for(int i = 0; i < nc; i++)
		{
			l[i] = giveInt("	Lower limit for term " + numOp :: nts(i + 1) + ": ");
			r[i] = giveInt("	Upper limit for term " + numOp :: nts(i + 1) + ": ");
			valid(l[i], r[i]);
		}
		Rtuple R;
		R.setCase(fname, T, t, nc, l, r, folder_name);
	}
	else if(ptype == "tuple_array" || ptype == "102")
	{
		int nc = giveInt("	Number of elements in a tuple: ");
		int n = giveInt("	Number of tuples (over all test cases): ");
		vector <int> l(nc), r(nc);
		for(int i = 0; i < nc; i++)
		{
			l[i] = giveInt("	Lower limit for term " + numOp :: nts(i + 1) + ": ");
			r[i] = giveInt("	Upper limit for term " + numOp :: nts(i + 1) + ": ");
			valid(l[i], r[i]);
		}
		int d = giveInt("	Distribution key (-1 for randomized): ");
		valid(d, 'i');
		RtupleArray R;
		R.setCase(fname, T, t, nc, n, l, r, d, sz, folder_name);
	}
	else if(ptype == "paramarray" || ptype == "103")
	{
		int n = giveInt("	Number of array elements (over all test cases): ");
		int l = giveInt("	Lower limit: ");
		int r = giveInt("	Upper limit: ");
		valid(l, r);
		int nc = giveInt("	Number of parameters: ");
		vector <int> pl, pr;
		for(int i = 0; i < nc; i++)
		{
			pl.push_back(giveInt("	Lower limit for term " + numOp :: nts(i + 1) + ": ", 1));
			pr.push_back(giveInt("	Upper limit for term " + numOp :: nts(i + 1) + ": ", -1));
			valid(pl[i], pr[i]);
		}
		int d = giveInt("	Distribution key (-1 for randomized): ");
		valid(d, 'i');
		Rparamarray R;
		R.setCase(fname, T, t, n, pl, pr, l, r, d, neg, sz, folder_name);
	}
	else if(ptype == "ptuple" || ptype == "104")
	{
		int n = giveInt("	Number of array elements (over all test cases): ");
		int nc = giveInt("	Number of tuple entries in a row: ");
		vector <int> l(nc), r(nc);
		for(int i = 0; i < nc; i++)
		{
			l[i] = giveInt("	Lower limit for term " + numOp :: nts(i + 1) + ": ", 1);
			r[i] = giveInt("	Upper limit for term " + numOp :: nts(i + 1) + ": ", -1);
			valid(l[i], r[i]);
		}
		nc = giveInt("	Number of parameters: ");
		vector <int> pl, pr;
		for(int i = 0; i < nc; i++)
		{
			pl.push_back(giveInt("	Lower limit for term " + numOp :: nts(i + 1) + ": ", 1));
			pr.push_back(giveInt("	Upper limit for term " + numOp :: nts(i + 1) + ": ", -1));
			valid(pl[i], pr[i]);
		}
		int d = giveInt("	Distribution key (-1 for randomized): ");
		valid(d, 'i');
		Rptuple R;
		R.setCase(fname, T, t, n, pl, pr, l, r, d, sz, folder_name);
	}
	cout << '\n' << '\n' << "Do you want to create output files? (y/n) ";
	string c;
	getline(cin, c);
	if(c == "Y" || c == "y" || c == "Yes" || c == "yes" || c == "YES")
		GenOutput(fname, T);
}
