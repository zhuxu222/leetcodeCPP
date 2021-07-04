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

int largestRectangleArea(std::vector<int>& heights) {
	int len = heights.size();
	std::vector<int> lefeLine(len,-1);
	std::vector<int>rightLine(len,len);
	std::stack<int>noReduceStack;
	noReduceStack.push(-1);
	for(int i = 1; i < len;i++) {
		int j = i - 1;
		while (heights[i]<heights[j])
		{
			noReduceStack.pop();
			rightLine[j] = i;
			j++;
		}

	}
	return 0;
}

bool canCross(std::set<int>& stonesSet,
			  std::map<int,std::set<int>>& filedStep,
			  int i,
			  int step,
			  int finishPoint) {
	if (step<=0 || i> finishPoint){
		return false;
	}
	if (i == finishPoint){
		return true;
	}
	if (stonesSet.find(i) == stonesSet.end()){
		return false;
	}
	if (filedStep[i].find(step)!= filedStep[i].end()){
		return false;
	}
	for(int nextStep = step - 1; nextStep < step + 2; nextStep++) {
        int nextPoint = i + nextStep;
        if (canCross(stonesSet,filedStep,nextPoint,nextStep,finishPoint)){
			return true;
        }
	}
	filedStep[i].insert(step);
	return false;
}

bool canCross(std::vector<int>& stones) {
	std::set<int>stonesSet;
	for(int i = 0; i < stones.size();i++) {
		stonesSet.insert(stones[i]);
	}
	std::map<int,std::set<int>> filedStep;
	return canCross(stonesSet,filedStep,1,1,stones[stones.size() - 1]);
}

int singleNumber(std::vector<int>& nums) {
	return 0;
}

std::vector<int> decode(std::vector<int>& encoded,int first) {
	int len = encoded.size();
	std::vector<int> arr(len + 1, 0);
	arr[0] = first;
	for(size_t i=0; i < len; i++){
		arr[i + 1] = encoded[i] ^ arr[i];
	}
	return arr;
}

void nextPermutation(std::vector<int>& nums) {
	size_t i = nums.size() - 1;
	while (i > 0 && nums[i] <= nums[i - 1]) {
		i--;
	}
	if (i > 0) {
		size_t j = nums.size() - 1;
		while (j >= i && nums[j] <= nums[i - 1]) {
			j--;
		}
		std::swap(nums[j], nums[i - 1]);
	}
	reverse(nums.begin() + i, nums.end());
}

bool nextPermutation(std::string& s) {
	bool hasNextPermutation = false;
	size_t i = s.size() - 1;
	while (i > 0 && s[i] <= s[i - 1]) {
		i--;
	}
	if (i > 0) {
		size_t j = s.size() - 1;
		while (j >= i && s[j] <= s[i - 1]) {
			j--;
		}
		std::swap(s[j], s[i - 1]);
		hasNextPermutation = true;
	}
	reverse(s.begin() + i, s.end());
	return hasNextPermutation;
}

std::vector<std::string> permutation(std::string s) {
	sort(s.begin(), s.end());
	std::vector<std::string> ret;
	do 	{
		ret.push_back(s);
	} while (nextPermutation(s));
	return ret;
}

int hammingWeight(uint32_t n) {
	int ret = 0;
	while (n) 	{
		n = n & (n - 1);
		ret++;
	}
	return ret;
}

static std::vector<std::string>mapOfDigits = {
	"",
	"",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz",
};

bool nextLetterCombinations(std::string& last, std::string digits) {
	int carry = 1;
	int i = last.size() - 1;
	while (i >= 0 && carry) 	{
		int key = digits[i] - '0';
		std::string subMap = mapOfDigits[key];
		char sumRet = last[i]  + carry;
		if (sumRet > subMap[subMap.size() - 1]) {
			carry = 1;
			last[i] = subMap[0];
		} else 	{
			last[i] = sumRet;
			carry = 0;
		}
		i--;
	}
	return carry == 0;
}

std::vector<std::string> letterCombinations(std::string digits) {
	std::vector<std::string>ret;
	if (digits.size()<=0) 	{
		return ret;
	}
	std::string retElement(digits.size(), '\0');
	for (size_t i = 0; i < digits.size(); i++) 		{
		int key = digits[i] - '0';
		retElement[i] = mapOfDigits[key][0];
	}
	do 
	{
		ret.push_back(retElement);
	} while (nextLetterCombinations(retElement, digits));
	return ret;
}

int numBusesToDestination(std::vector<std::vector<int>>& routes, int source, int target)
{
	std::map<int, std::set<int>>mapOfIndexOfVector;
	for (size_t i = 0; i < routes.size(); i++)
	{
		for (size_t j = 0; j < routes[i].size(); j++)
		{
			mapOfIndexOfVector[routes[i][j]].insert(i);
		}
	}
	std::stack<int>stackOfIndex;
	int numOfLastLevelElements = 0;
	std::set<int>setOfUniqueElement;
	std::set<int>setOfUniqueVector;
	stackOfIndex.push(source);
	numOfLastLevelElements = 1;
	setOfUniqueElement.insert(source);
	//do{

	//} while ();
	return 0;
}

int maxIceCream(std::vector<int>& costs, int coins)
{
	return 0;
}

