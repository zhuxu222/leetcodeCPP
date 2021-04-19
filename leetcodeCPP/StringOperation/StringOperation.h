#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>

class StringOperation
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs);

    int genarateHashCodeFromString(std::string str);

    std::string sortString(std::string str);

    bool wordPattern(std::string pattern, std::string s)
    {
        std::map<char, std::string>psMap;
        std::map<std::string, char>spMap;
        int i = 0;
        int j = 0;

        for (int k=0;k<pattern.size();k++)
        {
            if (j>=s.size() || i>=s.size())
            {
                return false;
            }
            char pSub = pattern[k];
            while (j<s.size() && s[j]!=' ')
            {
                j++;
            }
            std::string sSubStr = s.substr(i, (j - i));
            if (psMap.find(pSub)==psMap.end() && spMap.find(sSubStr)==spMap.end())
            {
                psMap[pSub] = sSubStr;
                spMap[sSubStr] = pSub;
            }
            else
            {
                if (psMap[pSub]!=sSubStr || spMap[sSubStr] != pSub)
                {
                    return false;
                }
            }
            j++;
            i = j;
        }
        if (j<s.size())
        {
            return false;
        }
        return true;
    }

    bool wordPatternMatch(std::string pattern, std::string s)
    {

    }

    int maxProfit(std::vector<int>& prices, int fee)
    {

    }

	char findTheDifference(std::string s, std::string t)
	{
        int ret = 0;
        for (int i=0;i<s.size();i++)
        {
            ret += t[i];
            ret -= s[i];
        }
        ret += t[t.size() + 1];
        return (char)ret;
	}

    std::vector<int> findNumOfValidWords(std::vector<std::string>& words, std::vector<std::string>& puzzles);
};