// Nauka - wektory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
//#include "wektor.h"
//#include "wektor2d.h"
//#include "randomVector.h"
//#include "bigN.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <utility>

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

int getRand(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);  // static used for efficiency, so we only calculate this value once
																				 // evenly distribute the random number across our range
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

int main()
{
	try
	{
		
		
		srand(static_cast<unsigned int>(time(0)));
		rand();
		int x;
		int sum(0);
		while (std::cin >> x)
		{
			int tab[16]{ 1 };
			for (int i = 0;i < 16;++i)
			{
				tab[i] = 1;
				for (int j = 0;j < i;++j)
					tab[i] *= 2;
				//std::cout << tab[i] << " ";
			}
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			int num = getRand(0, 16);
			std::cout << "Number: " << num << "\n";
			int rand;
			for (int i = 0;i < num;++i)
			{
				rand = getRand(0, 15-i);
				int temp = tab[rand];
				if (rand < 15 - i)
				{
					tab[rand] = tab[15 - i];
					tab[15 - i] = temp;
				}
				sum += temp;
				std::cout << temp << " ";
			}
			num = tab[getRand(0, 15)];
			std::cout << "Suma: " << sum << " - Liczba: " << num;
		}


		//char strBuf[11];
		//// Read up to 10 characters
		//std::cin.getline(strBuf, 11);
		//std::cout << std::cin.gcount() << " : " << strBuf << std::endl;

		//// Read up to 10 more characters
		//std::cin.getline(strBuf, 11);
		//std::cout << std::cin.gcount() << " : " << strBuf << std::endl;

		//wektor<int> moj({ 1,2,3 });
		//moj.print();
		//int wart1 = 4;
		//int wart2 = 5;
		//int wart3 = 6;
		//int *wsk1 = &wart1;
		//int *wsk2 = &wart2;
		//int *wsk3 = &wart3;
		//wektor<int*> moj4({ wsk1,wsk2,wsk3 });
		//moj4.print();
		//std::cout << "Operator<<: " << moj << "\n";

		//wektor2d<int> moj5{ { 1,2,3,4,5 },{ 6,7,8 },{ 9,10,11,12 },{ 13,14 } };
		//moj5.print();
		//wektor2d<int> moj6(std::move(moj5));
		//std::cout << "moj 5:\n";
		//moj5.print();
		//std::cout << "moj 6:\n";
		//moj6.print();

		//wektor<bool> moj7{ 1,1,0,0,1,1,0,1 };
		//moj7.print();

		//randomVector<int> moj8{ 10,2,8 };
		//moj8.print();

		//randomVector<char> moj9{ 10,'a','d' };
		//moj9.print();

		//randomVector<double> moj10{ 10,1.0,3.0 };
		//moj10.print();

		//int c;
		////wczytaj(std::cin, c);
		////std::cout << c << '\n';

		//bigN num{ "14100654080" };
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

