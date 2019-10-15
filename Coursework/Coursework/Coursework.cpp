#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;
const int arraysize = 4;
int copies = 15;


class Number
{
public:
	Number(int arra[arraysize][arraysize], int val);
	~Number();
	int arr[arraysize][arraysize];
	int checker();
	int value;
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;
	int e = 0;
	int f = 0;
	int g = 0;
	int h = 0;
	int i = 0;
	int k = 0;
	int p = 0;
	int m = 0;
	int n = 0;
	int v = 0;
	int x = 0;
	int z = 0;

private:

};

Number::Number(int arra[arraysize][arraysize], int val)
{
	for (size_t i = 0; i < arraysize; i++)
	{
		for (size_t j = 0; j < arraysize; j++)
		{
			arr[i][j] = arra[i][j];
		}
	}
	value = val;
}

Number::~Number()
{
}

int Number::checker()
{
	if (value == arr[0][0]) a = 1;
	if (value == arr[0][1]) b = 1;
	if (value == arr[0][2]) c = 1;
	if (value == arr[0][3]) d = 1;
	if (value == arr[1][0]) e = 1;
	if (value == arr[1][1]) f = 1;
	if (value == arr[1][2]) g = 1;
	if (value == arr[1][3]) h = 1;
	if (value == arr[2][0]) i = 1;
	if (value == arr[2][1]) k = 1;
	if (value == arr[2][2]) p = 1;
	if (value == arr[2][3]) m = 1;
	if (value == arr[3][0]) n = 1;
	if (value == arr[3][1]) v = 1;
	if (value == arr[3][2]) x = 1;
	if (value == arr[3][3]) z = 1;

	if ((a + b + c + d + e + f + g + h + i + k + p + m + n + v + x + z) == 16)
	{
		return 1;
	}
	return 0;
}

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

void print(int arr[arraysize][arraysize])
{
	for (int row = 0; row < arraysize; row++) {
		for (int column = 0; column < arraysize; column++) {
			cout << arr[row][column] << " ";
		}
		cout << endl;
	}
}

int test(int** arr[arraysize][arraysize])
{

}

int main()
{
	int arr[arraysize][arraysize];
	int currentr = 3;
	int currentc = 3;
	Generator();


	ifstream Myfile("text.txt");
	for (int row = 0; row < arraysize; row++) {
		for (int column = 0; column < arraysize; column++) {
			Myfile >> arr[row][column];
			cout << arr[row][column] << " ";
		}
		cout << endl;
	}
	Myfile.close();

	int t = 0;
	test(&arr);
	/*while (t != 4)
	{
		system("cls");
		print(arr);
		arr[currentr][currentc] = arr[currentr - 1][currentc];
		arr[currentr - 1][currentc] = 0;
		currentr -= 1;

		system("cls");
		print(arr);
		arr[currentr][currentc] = arr[currentr][currentc - 1];
		arr[currentr][currentc - 1] = 0;
		currentc -= 1;

		system("cls");
		print(arr);
		arr[currentr][currentc] = arr[currentr + 1][currentc];
		arr[currentr + 1][currentc] = 0;
		currentr += 1;
		
		system("cls");
		print(arr);
		arr[currentr][currentc] = arr[currentr][currentc + 1];
		arr[currentr][currentc + 1] = 0;
		currentc += 1;


	}*/


	
	return 0;
}
