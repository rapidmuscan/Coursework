//Alexander  Sablin aslablino@yandex.ru
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include "puzzleGen.h"
using namespace std;

puzzleGen::puzzleGen(int a, int b, int c)
{
	size = a;
	cop = b;
	maxval = c;
}

void puzzleGen::Generator()
{
	//srand(time(0));
	ofstream MyFile("text.txt");
	MyFile << cop << endl;
	
	for (size_t l = 0; l < cop; l++) {
		vector<unsigned long long> Genvector;
		for (size_t f = 0; f < (size * size); f++)
		{
			Genvector.push_back(0);
		}
		for (unsigned long long i = 0; i < ((size * size)); i++) {

			unsigned long long chek = 0;
			Genvector[i] = 1 + rand() % (maxval - 1);
			
			while (chek != 1)
			{
				unsigned long long m = 0;
				for (unsigned long long j = 0; j < i; j++) {
					if (Genvector[i] == Genvector[j]) {
						Genvector[i] = 1 + rand() % (maxval - 1);
						m++;
					}
				}
				if (m == 0) chek = 1;
			}

			Genvector[(size*size)-1] = 0;
			
			MyFile << Genvector[i] << " ";
			
			if ((((i + 2) % size) == true)) MyFile << endl;
			
		}
		MyFile << endl;
		MyFile << endl;
		
	}
	MyFile.close();
}

void puzzleGen::ManualInput()
{
	cout << "Put "<< (size * size) - 1 <<" numbers from 1 to " << maxval << " :" << endl;
	srand(time(0));
	ofstream MyFile("text.txt");
	MyFile << cop << endl;
	for (size_t l = 0; l < cop; l++) {
		vector<int> Genvector;
		for (int f = 0; f < (size * size); f++)	Genvector.push_back(0);
		cout << "New puzzle" << endl;
		for (int i = 0; i < (((size * size)) - 1); i++) {
			int chek = 0;
			cin >> Genvector[i];
			while (chek != 1)
			{
				int m = 0;
				if (Genvector[0] <= 0 || cin.fail())
				{
					cin.clear();
					cin.ignore(256, '\n');
					cout << "Enter int value from 1. And do not repeat!!!!!" << endl;
					cin >> Genvector[0];
					m++;
				}
				for (int j = 0; j < i ; j++) {
					if (Genvector[i] == Genvector[j] || Genvector[i] <= 0 || cin.fail()) {
						cin.clear();
						cin.ignore(256, '\n');
						cout << "Enter int value from 1. And do not repeat!!!!!" << endl ;
						cin >> Genvector[i];
						m++;
					}
				}
				if (m == 0) chek = 1;
			}
			
			MyFile << Genvector[i] << " ";
			if ((((i + 2) % size) == true)) MyFile << endl;
		}
		Genvector[(size * size) - 1] = 0;
		MyFile << Genvector[(size * size) - 1];
		MyFile << endl;
		MyFile << endl;
	}
	MyFile.close();
	
}


