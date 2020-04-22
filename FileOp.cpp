# include "FileOp.h"
# include "numOp.h"

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
