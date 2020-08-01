# include "FileOp.h"

// A function that sets a test case file and a file pointer
void FileOp :: setFile(string &folder_name, string &s, int t, fstream &fout)
{
	string tnum = numOp :: nts(t);
	string f = "./" + folder_name + "/" + s + tnum;
	f += ".txt";
	cout << "Generating file " << f << "." << '\n';
	fout.open(f, ios :: out);
}

// A function that sets precision on test case files
void FileOp :: fixOutprecision(fstream &fout)
{
	fout.precision(6);
	fout << fixed;
}

// A function to modify output format
int FileOp :: printT(int t)
{
	int pt = 1;
	if(t == 1)
	{
		cout << "	Do you want to print number of test cases? (1 for yes, 0 for no): ";
		string ss;
		getline(cin, ss);
		auto X = numOp :: ctnum(ss);
		if(!(X.second != 0 && (X.first == 1 || X.first == 0)))
			throw(111);
		pt = X.first;
	}
	return pt;
}