#include "StringOperation.h"
#include <set>

std::vector<std::vector<std::string>> StringOperation::groupAnagrams(std::vector<std::string>& strs)
{
	return std::vector<std::vector<std::string>>();
}

std::vector<int> StringOperation::findNumOfValidWords(std::vector<std::string>& words, std::vector<std::string>& puzzles)
{
	std::vector<int>ret(puzzles.size(),0);
	std::vector<std::set<char>>setArray(puzzles.size(),std::set<char>());
	for (int i=0;i<puzzles.size();i++)
	{
		for (int j=0;j<puzzles[i].size();j++)
		{
			setArray[i].insert(puzzles[i][j]);
		}
	}

	for (int i=0;i<words.size();i++)
	{
		for (int j=0;j<puzzles.size();j++)
		{
			bool containPuzzlesFirstChar = false;
			bool containAllChar = true;
			for (int k = 0; k < words[i].size(); k++)
			{
				if (setArray[j].find(words[i][k])==setArray[j].end())
				{
					containAllChar = false;
					break;
				}
				if (!containPuzzlesFirstChar && words[i][j] == puzzles[j][0])
				{
					containPuzzlesFirstChar = true;
				}
			}
			if (containPuzzlesFirstChar && containAllChar)
			{
				ret[j]++;
			}
		}
	}
	return ret;
}

//int StringOperation::genarateHashCodeFromString(std::string str)
//{
//    int hashNUmber = 0;
//    for (int i=0;i<str.size();i++)
//    {
//        int bitNim = 1;
//        int bitLocation = (str[i] - 'a');
//        bitNim << bitLocation;
//        hashNUmber += bitNim;
//    }
//}
//
//std::string StringOperation::sortString(std::string str)
//{
//    int charNum[26] = { 0 };
//    for (int i=0;i<str.size();i++)
//    {
//        charNum[(str[i] - 'a')]++;
//    }
//    std::string ret = { 0 };
//    for (int i=0;i<26;i++)
//    {
//        for(int j=0;i<charNum[i])
//    }
//}
