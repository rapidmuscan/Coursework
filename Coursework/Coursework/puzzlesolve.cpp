//Alexander  Sablin aslablino@yandex.ru
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include <thread>
#include "puzzlesolve.h"
#include "InfInt.h"
using namespace std;



puzzlesolve::puzzlesolve(unsigned long long a)
{
	size = a;	
	continusrows = 0;
}

void puzzlesolve::print()
{
	for (unsigned long long i = 0; i < (size * size); i++) {
		cout << myvector[i] << " ";
		if ((((i + 2) % size) == true)) cout << endl;
	}
}

void puzzlesolve::printfromfile()
{
	ifstream Myfile("text.txt");
	Myfile >> cop;
	cout << cop << endl;
	for (size_t i = 0; i < cop; i++)
	{
		vector<unsigned long long> pvector;
		for (unsigned long long i = 0; i < (size * size); i++) {
			unsigned long long input;
			Myfile >> input; // puting everything in to a vector
			pvector.push_back(input);
			cout << pvector[i] << " ";
			if ((((i + 2) % size) == true)) cout << endl;
		}
		cout << endl;
		cout << endl;
	}
	Myfile.close();
	cout << endl;
}


void puzzlesolve::independentcontnum(int a)
{
	InfInt _size = size;
	
	for (unsigned long long i = 0; i < ((size * size) - (a - 1)); i++)
	{
		if (myvector[i] + (a - 1) == myvector[i + (a - 1)])
		{
			independentnums += (_size * _size - 1 - _size) * ((factorial((_size * _size) - a - 1)) / 2);
		}
	}
}


InfInt puzzlesolve::factorial(InfInt A)
{
	InfInt B = 1,i = 2;
		for (; i <= A; i++) {
			B = B * i;
		}
		return B;	
}

void puzzlesolve::possiblecontiniusrows()
{
	InfInt _size = size;
	
	for (unsigned long long i = 0; i < ((size * size) - (size - 1)); i++)
	{
		if (myvector[i] + (size - 1) == myvector[i + (size - 1)])
		{
			continusrows += (_size - 1) * ((factorial(((_size * _size) - _size) - 1))/2);
		}
	}
}

void puzzlesolve::solve()
{
	unsigned long long percentdone = 0;
	ifstream Myfile("text.txt");
	ofstream SolFile("solution.txt");
	Myfile >> cop;
	for (unsigned long long i = 0; i < (size * size); i++)	myvector.push_back(0);

	for (size_t i = 0; i < cop; i++)
	{
		cout << "Puzzle number: " << i + 1 << endl << endl;
		SolFile << "Puzzle number: " << i + 1 << endl << endl;
		for (unsigned long long i = 0; i < (size * size); i++)	Myfile >> myvector[i];
		print();

		for (unsigned long long i = 0; i < (size * size); i++) {
			SolFile << myvector[i] << " ";
			if ((((i + 2) % size) == true)) SolFile << endl;
		}
		
		sort(myvector.begin(), myvector.end() - 1);
		possiblecontiniusrows();
		
		cout << "Continius rows :" << continusrows << endl;
		SolFile << "Continius rows :" << continusrows << endl;
		
		for (size_t i = 2; i < size; i++) {
			independentcontnum(i);
			cout << i << " : " << independentnums << endl;
			SolFile << i << " : " << independentnums << endl;
			independentnums *= 0;
		}
		
		cout << endl;
		SolFile << endl;
		continusrows *= 0;
	}

	Myfile.close();
}







