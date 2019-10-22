#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include "puzzleGen.h"
#include "puzzlesolve.h"
using namespace std;

int main()
{
	unsigned long long size =5;
	unsigned long long cop = 4;
	unsigned long long max = 26;
	/*cout << "Hello this is a puzzle game. Enter size n*n you prefere:";
	cin >> size;
	cout << "Enter how many copies of a puzzle you prefere:";
	cin >> cop;
	cout << "Enter maximum value you prefere to be in the puzzle:";
	cin >> max;*/

	puzzleGen obj(size,cop,max);
	obj.Generator();

	puzzlesolve obk(size);
	obk.solve();
	
	return 0;
}
