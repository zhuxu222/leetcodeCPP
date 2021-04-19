#include "StringToFibonacciSequence.h"

int subStringToInt(std::string& s, int start, int end)
{
	int retNum = 0;
	int base = 1;
	for (int i=end ;i>=start;i--)
	{
		retNum += (s[i] - '0') * base;
		base *= 10;
	}
	return retNum;
}

//std::vector<int> splitIntoFibonacci(std::string S)
//{
//	std::vector<int> sequence;
//	for (int i=0;i<S.length();i++){}
//	{
//		for (int j=0;j<S.length();j++)
//		{
//
//		}
//	}
//}

std::vector<int> countBits(int num)
{
	std::vector<int> ret(num, 0);
	if (num<=0)
	{
		return ret;
	}
	ret[1] = 1;
	int d = 2;
	int nd = 4;
	for (int i=2;i<num;i++)
	{
		if (i==nd)
		{
			d = nd;
			nd *= 2;
		}
		ret[i] = 1 + ret[i - d];
	}
	return ret;
}

bool vectorSortompare(std::vector<int>& a, std::vector<int>& b)
{
	return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
}

int maxEnvelopes(std::vector<std::vector<int>>& envelopes)
{
	std::sort(envelopes.begin(), envelopes.end(), vectorSortompare);

	return 0;
}

