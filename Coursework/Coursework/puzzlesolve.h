#ifndef PUZZLESOLVE_H
#define PUZZLESOLVE_H
#include <vector>
using namespace std;
class puzzlesolve
{
public:
	puzzlesolve(int a);
	void printfromfile();
	void print();
	void solve();
protected:
private:
	void up();
	void down();
	void right();
	void left();
	void circle(int number);
	void checkerofparts();
	void refresh();
	void refresh2();
	unsigned int cop;
	unsigned int size;
	unsigned int position;
	vector<unsigned int> myvector;
	unsigned int combin;
	unsigned int newcombin;
};

#endif // !PUZZLESOLVE_H
