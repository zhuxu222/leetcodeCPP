#include <iostream>

#include "Sequence/StringToFibonacciSequence.h"


void testSort()
{
	std::vector<std::vector<int>> envelopes = { {5,4},{6,7},{6,4},{2,3} };
	maxEnvelopes(envelopes);
	std::cout << &envelopes << std::endl;
}

void tempTest()
{
	uint8_t* m_buffer = new uint8_t(1000);
	uint32_t bits = 8;
	int64_t value = 0;
	int	m_size = 0;
	int	m_readPos= 0;
	uint8_t	m_bitIndex= 0;
	for (int i = 0; i < bits; ++i)
	{
		int bitval = (m_buffer[m_readPos] >> (7 - m_bitIndex)) & 1;
		value <<= 1;
		value += bitval;
		++m_bitIndex;
		if (m_bitIndex == 8)
		{
			++m_readPos;
			m_bitIndex = 0;
		}
	}
}

void main()
{
	//tempTest();
	//testSort();
	//std::string s = "12324";
	//int num = subStringToInt(s, 1, 3);

	//std::cout << "string " << s << " to num " << num << std::endl;

	//std::cout << "main end" << std::endl;
	//std::vector<int>stones = {0,1,3,5,6,8,12,17};
	//canCross(stones);
	std::vector<std::string> ret = letterCombinations("");
	return;
}