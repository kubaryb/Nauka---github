#pragma once
#ifndef BIGN_H
#define BIGN_H

#include <string>
#include <iostream>
#include <sstream>

#define m_n 4294967296
typedef uint32_t uint;
typedef uint64_t ulong;

class bigN
{
	uint* num;
	int cap;
	int len;
public:
	bigN(const std::string &str)
	{
		cap = 10;
		num = new uint[cap];
		len = 2;
		while (1)
		{
			int ind(str.length() - 10);
			ulong temp = std::stoll(str.substr(ind,10), nullptr);
			std::cout << temp << "\n";
			num[1] = 0;
			while (temp>=m_n)
			{
				++num[1];
				temp -= m_n;
			}
			num[0] = temp;

			break;
		}
		for (int i = 0;i < len;++i)
			std::cout << num[i] << "\n";
	}
	~bigN()
	{
		if (cap > 1)
			delete num;
		else
			delete[]num;
	}
	
};

#endif // !BIGN_H
