#ifndef PUZZLESOLVE_H
#define PUZZLESOLVE_H
#include <vector>
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
	void checkcontinusrows();
	unsigned long long continusrows;
	unsigned long long cop;
	unsigned long long size;
	void possiblecontiniusrows();
	void independentcontnum(int a);
	unsigned long long independentnums;
	unsigned long long factorial(unsigned long long A);
	vector<unsigned int> myvector;
};

#endif // !PUZZLESOLVE_H
