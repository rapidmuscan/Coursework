#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include "puzzlesolve.h"



puzzlesolve::puzzlesolve(int a)
{
	size = a;
	position = (size * size) - 1;
	combin = 0;
}

void puzzlesolve::print()
{
	system("cls");
	for (int i = 0; i < (size * size); i++) {
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
		vector<int> pvector;
		for (int i = 0; i < (size * size); i++) {
			int input;
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

void puzzlesolve::up()
{
	myvector[position] = myvector[position - size];
	myvector[position - size] = 0;
	position -= size;
}

void puzzlesolve::down()
{
	myvector[position] = myvector[position + size];
	myvector[position + size] = 0;
	position += size;
}

void puzzlesolve::right()
{
	myvector[position] = myvector[position + 1];
	myvector[position + 1] = 0;
	position += 1;
}

void puzzlesolve::left()
{
	myvector[position] = myvector[position - 1];
	myvector[position - 1] = 0;
	position -= 1;
}

void puzzlesolve::circle(int number)//look at the added pictures
{
	for (int i = 0; i < number; i++) {
		up();
	}

	for (int i = 0; i < number; i++) {
		left();
	}

	for (int i = 0; i < number; i++) {
		down();
	}

	for (int i = 0; i < number; i++) {
		right();
	}
}

void puzzlesolve::checkerofparts()
{
	vector<int> datavector;
	//read and check
	int ch = 0;
	int same = 0;
	ifstream Myfile("data.txt");
	for (int j = 0; j < combin; j++) {
		for (int i = 0; i < (size * size); i++) {
			int input;
			Myfile >> input; // puting everything in to a vector
			datavector.push_back(input);
			if (myvector[i] == datavector[i])ch++;
		}
		if (ch == (size * size))
		{
			same++;
		}
		ch = 0;
	}
	Myfile.close();

	if (same == 0)
	{
		//input
		ofstream MyFile;
		MyFile.open("data.txt", ios::app);
		for (size_t i = 0; i < (size * size); i++)
		{
			MyFile << myvector[i] << " ";
		}
		MyFile << endl;
		MyFile.close();
		combin++;
		
	}
	
}

void puzzlesolve::refresh()
{
	up();
	for (int i = 0; i < size - 2; i++ )left();
	up();
	for (int i = 0; i < size - 2; i++)right();
	up();
	for (int i = 0; i < size - 1; i++)left();
	for (int i = 0; i < size - 1; i++)down();
	for (int i = 0; i < size - 1; i++)right();
}

void puzzlesolve::solve()
{
	ifstream Myfile("text.txt");
	Myfile >> cop;
	for (int i = 0; i < (size * size); i++) {
		int input;
		Myfile >> input; // puting everything in to a vector
		myvector.push_back(input);
	}
	Myfile.close();

	print();
	int a;
	cin >> a;
	int t = 0;

	for (size_t f = 0; f < 15; f++)
	{
		for (size_t k = 0; k < 11; k++)
		{
			for (size_t i = 0; i < 7; i++)
			{
				for (size_t j = 0; j < 3; j++)
				{
					circle(1);
					checkerofparts();
					t++;
				}
				circle(2);
				print();
			}
			circle(3);
			print();
		}
		refresh();
		print();

	}

}







