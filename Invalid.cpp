# include "Invalid.h"

// A function to set the error code
void Invalid :: setCaseError(int n)
{
	eno = n;
}

// A function to obtain the error code
int Invalid :: retError()
{
	return eno;
}
