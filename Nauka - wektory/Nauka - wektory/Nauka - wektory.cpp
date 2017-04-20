// Nauka - wektory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "wektor.h"

int main()
{
	wektor<int> moj({ 1,2,3 });
	moj.print();
    return 0;
}

