//Alexander  Sablin aslablino@yandex.ru
#ifndef PUZZLESOLVE_H
#define PUZZLESOLVE_H
#include <vector>
#include "InfInt.h"
using namespace std;
class puzzlesolve
{
public:
	puzzlesolve(unsigned long long a);
	void printfromfile();
	void print();
	void solve();
protected:
private:
	
	InfInt continusrows;
	unsigned long long cop;
	unsigned long long size;
	void possiblecontiniusrows();
	void independentcontnum(int a);
	InfInt independentnums;
	InfInt factorial(InfInt A);
	vector<unsigned int> myvector;
};

#endif // !PUZZLESOLVE_H
