#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
#include <set>
#include <iostream>

#include<algorithm>
#include <memory>

int subStringToInt(std::string& s, int start, int end);
std::vector<int> splitIntoFibonacci(std::string S);

std::vector<int> countBits(int num);

int maxEnvelopes(std::vector<std::vector<int>>& envelopes);

int largestRectangleArea(std::vector<int>& heights);


bool canCross(std::vector<int>& stones);

int singleNumber(std::vector<int>& nums);

std::vector<int> decode(std::vector<int>& encoded,int first);

void nextPermutation(std::vector<int>& nums);

bool nextPermutation(std::string& s);
std::vector<std::string> permutation(std::string s);

int hammingWeight(uint32_t n);

std::string convertNumsToStr(std::vector<uint8_t>numsQue, std::string digits);
std::vector<std::string> letterCombinations(std::string digits);

int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target);

int maxIceCream(std::vector<int>& costs, int coins);
