#include <iostream>
#include "lexer.h"
using namespace LEX;
using namespace std;

int main()
{
	Lexer lexer;
	string myLine;
	cout << "Input line to test lexer: ";
	getline(cin, myLine);
	//string keysptr;
	//keysptr = lexer.lexline(myLine);
	vector<string> keys = lexer.lexline(myLine);

	for (auto key: keys)
	{

		cout << key << endl;

	}
	system("pause");
	return 0;
}