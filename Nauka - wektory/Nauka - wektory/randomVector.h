#pragma once
#ifndef RANDOMVECTOR_H
#define RANDOMVECTOR_H

#include "wektor.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

template <class typ>
typ getRand(typ p_min, typ p_max)
{
	static const double fr = 1.0/(static_cast<double>(RAND_MAX)+1.0);
	return static_cast<typ>(rand()*fr*(p_max-p_min+1) + p_min);
}

template <class typ>
class randomVector : public wektor<typ>
{
	int m_min;
	int m_max;
public:
	randomVector(const int &d, const typ &min, const typ &max);
};

template <class typ>
randomVector<typ>::randomVector(const int &d, const typ &min, const typ &max)
	:wektor<typ>(d)
{
	srand(static_cast<unsigned int>(time(0)));
	rand();
	for (int i = 0;i < d;++i)
		wart[i] = getRand<typ>(min,max);
}

#endif // !RANDOMVECTOR_H
