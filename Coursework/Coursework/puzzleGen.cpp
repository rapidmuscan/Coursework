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
	srand(time(0));
	ofstream MyFile("text.txt");
	for (size_t i = 0; i < cop; i++) {
		vector<int> Genvector;
		for (size_t i = 0; i < (size * size); i++)
		{
			Genvector.push_back(0);
		}
		for (int i = 0; i < ((size * size)); i++) {
			int chek = 0;
			Genvector[i] = 1 + rand() % (maxval - 1);
			while (chek != 1)
			{
				int m = 0;
				for (int j = 0; j < i; j++) {
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
	int copies = 2;
	int puzzsize = 2;
	cout << "Put 15 numbers from 1 to 20 :" << endl;
	srand(time(0));
	ofstream MyFile("text.txt");
	for (size_t i = 0; i < copies; i++) {
		vector<int> Genvector{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < ((puzzsize * puzzsize)); i++) {
			int chek = 0;
			Genvector[i] = 1 + rand() % 19;
			while (chek != 1)
			{
				int m = 0;
				for (int j = 0; j < i; j++) {
					if (Genvector[i] == Genvector[j]) {
						Genvector[i] = 1 + rand() % 19;
						m++;
					}
				}
				if (m == 0) chek = 1;
			}
			Genvector[15] = 0;
			MyFile << Genvector[i] << " ";
			if (i == 3 || i == 7 || i == 11) MyFile << endl;
		}
		MyFile << endl;
		MyFile << endl;
	}
	MyFile.close();
}


