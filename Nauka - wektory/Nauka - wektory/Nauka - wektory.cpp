// Nauka - wektory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wektor.h"
#include "wektor2d.h"
#include "randomVector.h"
#include <string>

template <class typ>
int wczytaj(std::istream &a, typ &x)
{
	a >> x;
	while (a.fail())
	{
		std::cout << "Type again: ";
		a.clear();
		a.ignore(1000, '\n');
		a >> x;
	}
	return 1;
}

int main()
{
	try
	{
		wektor<int> moj({ 1,2,3 });
		moj.print();
		int wart1 = 4;
		int wart2 = 5;
		int wart3 = 6;
		int *wsk1 = &wart1;
		int *wsk2 = &wart2;
		int *wsk3 = &wart3;
		wektor<int*> moj4({ wsk1,wsk2,wsk3 });
		moj4.print();

		wektor2d<int> moj5{ { 1,2,3,4,5 },{ 6,7,8 },{ 9,10,11,12 },{ 13,14 } };
		moj5.print();
		wektor2d<int> moj6(std::move(moj5));
		std::cout << "moj 5:\n";
		moj5.print();
		std::cout << "moj 6:\n";
		moj6.print();

		wektor<bool> moj7{ 1,1,0,0,1,1,0,1 };
		moj7.print();

		randomVector<int> moj8{ 10,2,8 };
		moj8.print();

		randomVector<char> moj9{ 10,'a','d' };
		moj9.print();

		randomVector<double> moj10{ 10,1.0,3.0 };
		moj10.print();

		int c;
		wczytaj(std::cin, c);
		std::cout << c << '\n';

	}
	catch (const std::exception &exception)
	{
		std::cout << "Error occured: " << exception.what() << "\n";
	}
	catch (...)
	{
		std::cout << "Undefined error occured";
	}
    return 0;
}

