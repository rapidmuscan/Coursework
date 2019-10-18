#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <time.h>
#include "puzzleGen.h"

using namespace std;





//this is random generator that puts 15 puzzles in to a file 




//moves that i am doing
//void up(vector<int>& myvector, unsigned int &position)
//{
//	myvector[position] = myvector[position - arraysize];
//	myvector[position - arraysize] = 0;
//	position -= arraysize;
//}
//
//void down(vector<int>& myvector, unsigned int &position)
//{
//	myvector[position] = myvector[position + arraysize];
//	myvector[position + arraysize] = 0;
//	position += arraysize;
//}
//
//void right(vector<int>& myvector, unsigned int &position)
//{
//	myvector[position] = myvector[position + 1];
//	myvector[position + 1] = 0;
//	position += 1;
//}
//
//void left(vector<int>& myvector, unsigned int &position)
//{
//	myvector[position] = myvector[position - 1];
//	myvector[position - 1] = 0;
//	position -= 1;
//}
//
//void print(vector<int> myvector)
//{
//	system("cls");
//	for (int i = 0; i < (arraysize * arraysize); i++) {
//		cout << myvector[i] << " ";
//		if (i == 3 || i == 7 || i == 11) cout << endl;
//	}
//}
//
//
//void circle(vector<int>& myvector, unsigned int& position,int number)//look at the added pictures
//{	
//	for (int i = 0; i < number; i++){
//		up(myvector, position);
//	}
//	
//	for (int i = 0; i < number; i++){
//		left(myvector, position);
//	}
//
//	for (int i = 0; i < number; i++){
//		down(myvector, position);
//	}
//
//	for (int i = 0; i < number; i++){
//		right(myvector, position);
//	}
//	
//}
//
//void refresh(vector<int>& myvector, unsigned int& position)//look at the added pictures 
//{
//	up(myvector, position);
//	for (int i = 0; i < arraysize - 2; i++ )left(myvector, position);
//	up(myvector, position);
//	for (int i = 0; i < arraysize - 2; i++)right(myvector, position);
//	up(myvector, position);
//	for (int i = 0; i < arraysize - 1; i++)left(myvector, position);
//	for (int i = 0; i < arraysize - 1; i++)down(myvector, position);
//	for (int i = 0; i < arraysize - 1; i++)right(myvector, position);
//}
//
//void checkerofparts(vector<int> myvector, int& combin, int& newval)
//{
//	vector<int> datavector;
//	//read and check
//	int ch = 0;
//	int same = 0;
//	ifstream Myfile("data.txt");
//	for (int j = 0; j < combin; j++) {
//		for (int i = 0; i < (arraysize * arraysize); i++) {
//			int input;
//			Myfile >> input; // puting everything in to a vector
//			datavector.push_back(input);
//			if (myvector[i] == datavector[i])ch++;
//		}
//		if (ch == (arraysize * arraysize))
//		{
//			same++;
//		}
//		ch = 0;
//	}
//	Myfile.close();
//
//	if (same == 0)
//	{
//		//input
//		ofstream MyFile;
//		MyFile.open("data.txt", ios::app);
//		for (size_t i = 0; i < (arraysize * arraysize); i++)
//		{
//			MyFile << myvector[i] << " ";
//		}
//		MyFile << endl;
//		MyFile.close();
//		combin++;
//		newval++;
//	}
//	
//}



int main()
{
	int size = 4;
	int cop = 10;
	int max = 20;
	puzzleGen obj(size,cop,max);
	obj.Generator();

	//puzzle obj;
	//int combin = 0;
	//vector<int> myvector;
	//unsigned int position = 15;
	////Generator();
	//int newval = 0;


	//ifstream Myfile("text.txt"); 
	//for (int i = 0; i < (arraysize*arraysize); i++) {
	//	int input;
	//	Myfile >> input; // puting everything in to a vector
	//	myvector.push_back(input);
	//	cout << myvector[i] << " ";
	//	if (i == 3 || i == 7 || i == 11) cout << endl;
	//}
	//Myfile.close();
	//cout << endl;

	//
	//
	//

	//int t = 0;
	////I am trying to find all combinations oviusly it is wrong
	//for (size_t f = 0; f < 15; f++)
	//{
	//	for (size_t k = 0; k < 11; k++)
	//	{
	//		for (size_t i = 0; i < 7; i++)
	//		{
	//			for (size_t j = 0; j < 3; j++)
	//			{
	//				circle(myvector, position, 1);
	//				checkerofparts(myvector,combin, newval);
	//				t++;
	//			}
	//			circle(myvector, position, 2);
	//			print(myvector);
	//		}
	//		circle(myvector, position, 3);
	//		print(myvector);
	//	}
	//	refresh(myvector, position);
	//	print(myvector);
	//}
	//







	//
	//	cout << endl;
	//	cout << newval << endl;
	//	cout << t;


	
	return 0;
}
