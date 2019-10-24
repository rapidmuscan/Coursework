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
	void presentindcontnumrow(int a);
	void presentindcontnumcol(int a);
	InfInt continusrows;
	unsigned long long cop;
	unsigned long long size;
	void possiblecontiniusrows();
	void independentcontnum(int a);
	InfInt presentcontnums;
	InfInt independentnums;
	InfInt factorial(InfInt A);
	vector<int> myvector;
	vector<int> secvector;
};

#endif // !PUZZLESOLVE_H
