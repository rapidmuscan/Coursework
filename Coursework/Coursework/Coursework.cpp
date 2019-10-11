#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>



using namespace std;

const int arraysize = 4;

int check(int arr[arraysize][arraysize], int value, int curentr, int currentc)
{
	int curplace = (curentr * arraysize) + currentc;
	vector<int> myvector;
	for (int row = 0; row < arraysize; row++) {
		for (int column = 0; column < arraysize; column++)
		{
			myvector.push_back(arr[row][column]);
		}
		
	}
	sort(myvector.begin(), myvector.end(), greater<int>());
	for (int i = 0; i < curplace; i++)
	{
		if (value == myvector[i])
		{
			return 0;
		}
	}
	

	return 1;
}


int main()
{
	
	
	int arr[arraysize][arraysize];
	int printtracker = 0;
	ofstream MyFile("text.txt");
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = 1 + rand() % 19;
			int m = 0;
			while (m == 0)
			{
				if (check(arr, arr[i][j], i, j) == 1) m = 1;
				arr[i][j] = 1 + rand() % 19;
				
			}

			MyFile << arr[i][j] << " ";
			

			if (j == 3)
			{
				MyFile << endl;
				printtracker++;
			}
		}
	}
	MyFile.close();

		ifstream Myfile("text.txt");
		for (int row = 0; row < arraysize; row++) {
			for (int column = 0; column < arraysize; column++) {
				Myfile >> arr[row][column];
				cout << arr[row][column] << " ";
			}
			cout << endl;
		}
		MyFile.close();



		return 0;
}
