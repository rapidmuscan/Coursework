#ifndef PUZZLEGEN_H
#define PUZZLEGEN_H


class puzzleGen
{
public:
	puzzleGen(int a,int b, int c);
	void Generator();
	void ManualInput();
protected:
private:
	int cop;
	int size;
	int maxval;
};



#endif // !PUZZLEGEN_H