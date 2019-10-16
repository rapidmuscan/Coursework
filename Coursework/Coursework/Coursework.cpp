#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;
const unsigned int arraysize = 4;
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




void up(vector<int>& myvector, unsigned int &position)
{
	myvector[position] = myvector[position - arraysize];
	myvector[position - arraysize] = 0;
	position -= arraysize;
}
void down(vector<int>& myvector, unsigned int &position)
{
	myvector[position] = myvector[position + arraysize];
	myvector[position + arraysize] = 0;
	position += arraysize;
}
void right(vector<int>& myvector, unsigned int &position)
{
	myvector[position] = myvector[position + 1];
	myvector[position + 1] = 0;
	position += 1;
}
void left(vector<int>& myvector, unsigned int &position)
{
	myvector[position] = myvector[position - 1];
	myvector[position - 1] = 0;
	position -= 1;
}

void lol(vector<int>& myvector, unsigned int& position)
{

}



void print(vector<int> myvector)
{
	for (int i = 0; i < (arraysize * arraysize); i++) {
		cout << myvector[i] << " ";
		if (i == 3 || i == 7 || i == 11) cout << endl;
	}
}

int main()
{
	vector<int> myvector;
	unsigned int position = 15;
	Generator();


	ifstream Myfile("text.txt");
	for (int i = 0; i < (arraysize*arraysize); i++) {
		int input;
		Myfile >> input;
		myvector.push_back(input);
		cout <<myvector[i] << " ";
		if (i == 3 || i == 7 || i == 11) cout << endl;
	}

	
	

	int t = 0;

	while (t != 4)
	{
		system("cls");
		print(myvector);
		up(myvector,position);

		system("cls");
		print(myvector);
		left(myvector, position);

		system("cls");
		print(myvector);
		down(myvector, position);

		system("cls");
		print(myvector);
		right(myvector, position);

	}


	
	return 0;
}
