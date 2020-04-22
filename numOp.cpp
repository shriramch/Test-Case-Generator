# include "numOp.h"

// A function that converts a given valid string to an integer
pair <int, bool> numOp :: ctnum(string s)
{
	int ans = 0;
	bool neg = false;
	int i = 0;
	if(s[0] == '-')
	{
		if(s.size() == 1)
			return make_pair(-1, false);
		neg = true;
		i++;
	}
	else if(s[0] == '+')
	{
		if(s.size() == 1)
			return make_pair(-1, false);
		i++;
	}
	for(; i < (int)s.size(); i++)
	{
		if(s[i] < 48 || s[i] > 57)
			return make_pair(-1, false);
		ans = 10 * ans + (s[i] - 48);
	}
	if(neg)
		ans = -1 * ans;
	return make_pair(ans, true);
}

// A function that converts a given valid string to a floating point number
pair <float, bool> numOp :: ctf(string s)
{
	float ans = 0;
	bool neg = false;
	int i = 0;
	if(s[0] == '-')
	{
		if(s.size() == 1)
			return make_pair(-1, false);
		neg = true;
		i++;
	}
	else if(s[0] == '+')
	{
		if(s.size() == 1)
			return make_pair(-1, false);
		i++;
	}
	int ii = i;
	while(i < (int)s.size() && s[i] != '.')
	{
		if(s[i] < 48 || s[i] > 57)
			return make_pair(-1, false);
		ans = 10 * ans + (s[i] - 48);
		i++;
	}
	if(ii == i)
		return make_pair(-1, false);
	float temp = 0.1;
	i++;
	while(i < (int)s.size())
	{
		if(s[i] < 48 || s[i] > 57)
			return make_pair(-1, false);
		ans += (temp * (s[i] - 48));
		temp /= 10;
		i++;
	}
	if(neg)
		ans = -1 * ans;
	return make_pair(ans, true);
}

// A function that converts a given integer to a string
string numOp :: nts(int n)
{
	if(n == 0)
		return "0";
	string s;
	while(n)
	{
		s = (char)(n % 10 + '0') + s;
		n /= 10;
	}
	return s;
}

// A function to generate a random integer close to t in the range (0, t].
int numOp :: giveRint(int t)
{
	default_random_engine generator(system_clock :: now().time_since_epoch().count());
	binomial_distribution <int> distribution(t, 0.995);
	int out = distribution(generator);
	return out;
}

// A function to generate a set of atmost t integers that sum to almost n
vector <int> numOp :: giveRints(int t, int n, int sz)
{
	n = max(n, t);
	default_random_engine generator(system_clock :: now().time_since_epoch().count());
	if(sz == 0)
	{
		vector <int> num(t);
		int mnum = n / t;
		uniform_int_distribution <int> d2(1, mnum);
		for(int i = 0; i < t; i++)
			num[i] = d2(generator);
		return num;
	}
	else
	{
		if(t == 1)
		{
			vector <int> num;
			num.push_back(n);
			return num;
		}
		array <float, 3> intervals {1.0, max(0.15 * t, 1.0), 1.0 * t};
		array <float, 3> weights {30.0, 20.0, 0.5};
		piecewise_linear_distribution <float> distribution(intervals.begin(), intervals.end(), weights.begin());
		int times = distribution(generator);
		int mnum = n / times;
		vector <int> num(times);
		binomial_distribution <int> d2(mnum, 0.99);
		for(int i = 0; i < times; i++)
			num[i] = max(1ll, d2(generator) % (mnum + 1));
		return num;	
	}
}
