//Alexander  Sablin aslablino@yandex.ru
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <thread> 
#include <algorithm>
#include <time.h>
#include "puzzleGen.h"
#include "puzzlesolve.h"
#include "Launcher.h"
using namespace std;


Launcher::Launcher() {

}

void Launcher::printfromSolfile()
{
	string line;
	ifstream myfile("solution.txt");
	if (myfile.is_open())
	{
		while (!myfile.eof())
		{
			getline(myfile, line);
			cout << line << endl;
		}
		myfile.close();
	}
	else
		cout << " Unable to open file." << endl;
	cout << line << endl << endl;

	system("pause");
}

int Launcher::Launch()
{
	cout << "Do you want to print previus solution? If Yes print 1 or watever you want" << endl;


	int c;
	cin >> c;
	switch (c)
	{
	case 1:
		printfromSolfile();
		break;
	default:
		return 0;
		break;
	}


	


	
	unsigned long long size = 4;
	unsigned long long cop = 4;
	unsigned long long max = 5;
	int deside = 0;
	cout << "Hello this is a puzzle game. Enter size n*n you prefere:";

	cin >> size;

	while (size <= 1 || cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "You r inout is invalid Enter size > 1: " << endl;
		cin >> size;
	}
	

	cout << endl << "1. Auto generate puzzle and solve" << endl << "2. Manual input" << endl << "3. Read from file and solve" << endl;

	cin >> deside;

	while ((deside != 1 && deside != 2 && deside != 3) || cin.fail()) {
		cin.clear();
		cin.ignore(256, '\n');
		cout << "You r inout is invalid Enter size > 1: " << endl;
		cin >> deside;
	}

	switch (deside)
	{
	case 1: {
		cout << "Enter how many copies of a puzzle you prefere:";
		cin >> cop;
		while (cop < 1 || cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "You r inout is invalid Enter size >= 1: " << endl;
			cin >> cop;
		}
		cout << "Enter maximum value you prefere to be in the puzzle:";
		cin >> max;
		while (max <= (size * size) || cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Your inout is invalid Enter size > (size * size + 1): " << endl;
			cin >> max;
		}
		puzzleGen obj(size, cop, max);
		obj.Generator();
		puzzlesolve obk(size);
		obk.solve();
	}
			break;
	case 2: {
		cout << "Enter how many copies of a puzzle you prefere:";
		cin >> cop;
		while (cop < 1 || cin.fail()) {
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Your inout is invalid Enter size > 1: " << endl;
			cin >> cop;
		}
		puzzleGen obj(size, cop, max);
		obj.ManualInput();
		puzzlesolve obk(size);
		obk.solve();
	}
			break;
	case 3: {
		puzzlesolve obk(size);
		obk.solve();
	}
			break;
	default:
		break;
	}
	

	cout << "Do you wish to start again? if yes press 1 if enter watever you want." << endl;
	int a;
	cin >> a;
	switch (a)
	{
	case 1:
		return Launch();
		break;
	default:
		return 0;
		break;
	}

}