#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;
const int arraysize = 4;
int copies = 15;

int check(int arr[arraysize][arraysize], int value, int curentr, int currentc)
{
	int curplace = ((curentr * arraysize) + currentc);

	vector<int> myvector;

	for (int row = 0; row < arraysize; row++) 
		for (int column = 0; column < arraysize; column++) 
			myvector.push_back(arr[row][column]);
	
	for (int i = 0; i < curplace; i++) if (value == myvector[i]) return 0;

	if (value == 0) return 0;
	
	
	return 1;
}

void Generator ()
{
	
	int arr[arraysize][arraysize];
	ofstream MyFile("text.txt");
	for (size_t i = 0; i < copies; i++) {
		for (int i = 0; i < arraysize; i++)
			for (int j = 0; j < arraysize; j++) {
				arr[i][j] = rand() % 20;

				while (check(arr, arr[i][j], i, j) == 0) arr[i][j] = 1 + rand() % 19;

				arr[3][3] = 0;

				MyFile << arr[i][j] << " ";

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
	
	return 0;
}
