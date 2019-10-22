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
	int size =4;
	int cop = 4;
	int max = 20;
	/*cout << "Hello this is a puzzle game. Enter size n*n you prefere:";
	cin >> size;
	cout << "Enter how many copies of a puzzle you prefere:";
	cin >> cop;
	cout << "Enter maximum value you prefere to be in the puzzle:";
	cin >> max;*/

	/*puzzleGen obj(size,cop,max);
	obj.Generator();*/

	puzzlesolve obk(size);
	obk.solve();


	

<<<<<<< HEAD
=======
				if (j == 3) MyFile << endl;

			}
		MyFile << endl;
	}
	MyFile.close();
}


int main()
{
	int arr[arraysize][arraysize];

	Generator();





	ifstream Myfile("text.txt");
	
		for (int row = 0; row < arraysize; row++) {
			for (int column = 0; column < arraysize; column++) {
				Myfile >> arr[row][column];
				cout << arr[row][column] << " ";
			}
			cout << endl;
		}
<<<<<<< HEAD
		cout << endl;
	}
	
=======
		
		
		
		
>>>>>>> 010ce585aae101ebd3e5bc7c8b0fb088bff256ae
	Myfile.close();
>>>>>>> master
	
	return 0;
}
