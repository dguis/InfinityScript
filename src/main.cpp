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
	vector<string> keysptr = lexer.lexline(myLine);
	//string (&ref)[3] = keysptr;
	cout << keysptr[0];
	//string keysptrDeref;
	//keysptrDeref = keysptr;
	//cout << keysptrDeref.c_str();
	return 0;
}