#pragma once
#ifndef WEKTOR_H
#define WEKTOR_H

#include <initializer_list>
#include <iostream>
#include <string>

//normal 11-D array

template <class typ>
class wektor
{
protected:
	int dlg;
	typ* wart;
public:
	wektor(const std::initializer_list<typ>&);
	wektor(const int &x) :dlg(x) { wart = new typ[dlg]{ 0 }; };
	virtual ~wektor();
	virtual void print() const;
	friend std::ostream& operator<<(std::ostream &out, wektor<typ> &wek)
	{
		for (int i = 0;i < wek.dlg;++i)
			out << wek[i] << " ";
		out <<  "\n";
		return out;
	}
	typ& operator[](const int &ind);
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

template <class typ>
typ& wektor<typ>::operator[](const int &ind)
{
	return wart[ind];
}

//Pointer array

template <class typ>
class wektor<typ*>
{
protected:
	int dlg;
	typ** wart;
public:
	wektor(const std::initializer_list<typ*>&);
	virtual ~wektor();
	virtual void print() const;
};

template <class typ>
wektor<typ*>::wektor(const std::initializer_list<typ*> &x)
{
	dlg = x.size();
	wart = new typ*[dlg];
	int it = 0;
	for (auto el : x)
	{
		wart[it] = el;
		++it;
	}
}

template <class typ>
wektor<typ*>::~wektor()
{
	delete[]wart;
}

template <class typ>
void wektor<typ*>::print() const
{
	for (int i = 0;i < dlg;++i)
		std::cout << *wart[i] << " ";
	std::cout << "\n";
}

//bool array

template <>
class wektor<bool>
{
protected:
	int dlg;
	int8_t* wart;
public:
	wektor(const std::initializer_list<int>&x)
	{
		dlg = (x.size() % 8) ? (x.size() / 8 + 1) : x.size()/8;
		wart = new int8_t[dlg]{ 0 };
		int i = 0, it = 0;
		for (auto el:x)
		{
			wart[it] |= el << i;
			++i;
			if (i == 8)
			{
				i = 0;
				++it;
			}
		}
	}
	virtual ~wektor()
	{
		if (wart)
			delete[]wart;
	}
	virtual void print() const
	{
		for (int it = 0;it < dlg;++it)
		{
			for (int i = 7;i >= 0;--i)
				std::cout << ((wart[it] & (1 << i))? 1:0);
			std::cout << "\n";
		}
	}
};

#endif // !WEKTOR_H
