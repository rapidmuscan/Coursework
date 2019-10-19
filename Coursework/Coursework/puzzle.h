#ifndef PUZZLEGEN_H
#define PUZZLEGEN_H


class puzzleGen
{
public:
	puzzleGen(int a,int b);
	void Generator(int puzzsize, int copies);
	void Manualinput(int puzzsize, int copies);
protected:
private:
	int cop;
	int size;
};



#endif // !PUZZLEGEN_H