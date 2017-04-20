// Nauka - wektory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wektor.h"

int main()
{
	wektor<int> moj({ 1,2,3 });
	moj.print();
	int wart1 = 4;
	int wart2 = 5;
	int wart3 = 6;
	int *wsk1 = &wart1;
	int *wsk2 = &wart2;
	int *wsk3 = &wart3;
	wektor<int*> moj2({ wsk1,wsk2,wsk3});
	moj2.print();
    return 0;
}

