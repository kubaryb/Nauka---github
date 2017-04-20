#pragma once
#ifndef WEKTOR2D_H
#define WEKTOR2D_H

#include <iostream>
#include <initializer_list>
#include <utility>

template <class typ>
class wektor2d
{
protected:
	int dlg;
	int* dlg_w;
	typ** wart;
public:
	wektor2d(const std::initializer_list<std::initializer_list<typ>>&);
	virtual ~wektor2d();
	virtual void print() const;
	wektor2d& operator=(const wektor2d<typ>&) = delete;
	wektor2d& operator=(wektor2d<typ>&&);
	wektor2d(const wektor2d<typ>&) = delete;
	wektor2d(wektor2d<typ>&&);
};

template <class typ>
wektor2d<typ>::wektor2d(const std::initializer_list<std::initializer_list<typ>>&x)
{
	dlg = x.size();
	wart = new typ*[dlg];
	dlg_w = new typ[dlg];
	int it = 0;
	for (auto el : x)
	{
		dlg_w[it] = el.size();
		wart[it] = new typ[dlg_w[it]];
		int i = 0;
		for (auto el2 : el)
		{
			wart[it][i] = el2;
			++i;
		}
		++it;
	}
}

template <class typ>
wektor2d<typ>::~wektor2d()
{
	for (int i = 0;i < dlg;++i)
		delete[]wart[i];
	delete[] wart;
	delete[]dlg_w;
}

template <class typ>
void wektor2d<typ>::print() const
{
	for (int i = 0;i < dlg;++i)
	{
		for (int j = 0;j<dlg_w[i];++j)
			std::cout << wart[i][j] << " ";
		std::cout << "\n";
	}
	std::cout << "\n";
}

template <class typ>
wektor2d<typ>& wektor2d<typ>::operator=(wektor2d<typ>&&x)
{
	if (x == this)
		return *this;

	dlg = x.dlg;
	wart = new typ*[dlg];
	dlg_w = new typ[dlg];
	for (int i = 0;i < dlg;++i)
	{
		wart[i] = x.wart[i];
		dlg_w[i] = x.dlg_w[i];
	}
	for (int i = 0;i < dlg;++i)
		delete[]x.wart[i];
	delete[]x.wart;
	delete[]x.dlg_w;

	return *this;
}

template <class typ>
wektor2d<typ>::wektor2d(wektor2d<typ>&&x)
{
	dlg = x.dlg;
	wart = x.wart;
	dlg_w = x.dlg_w;
	x.dlg = 0;
	x.wart = nullptr;
	x.dlg_w = nullptr;
}

#endif // !WEKTOR2D_H
