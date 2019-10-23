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
	unsigned long long size =100;
	unsigned long long cop = 1;
	unsigned long long max = 10001;
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
