#pragma once
#ifndef WEKTOR_H
#define WEKTOR_H

#include <initializer_list>
#include <iostream>

template <class typ>
class wektor
{
protected:
	int dlg;
	typ* wart;
public:
	wektor(const std::initializer_list<typ>&);
	virtual ~wektor();
	virtual void print() const;
};

template <class typ>
wektor<typ>::wektor(const std::initializer_list<typ> &x)
{
	dlg = x.size();
	wart = new typ[dlg];
	int it = 0;
	for (auto el : x)
	{
		wart[it] = el;
		++it;
	}
}

template <class typ>
wektor<typ>::~wektor()
{
	delete[]wart;
}

template <class typ>
void wektor<typ>::print() const
{
	for (int i = 0;i < dlg;++i)
		std::cout << wart[i] << " ";
	std::cout << "\n";
}
#endif // !WEKTOR_H
