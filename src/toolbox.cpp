// my_class.cpp
#include "toolbox.h" // header in local directory
#include <iostream>	 // header in standard library
#include <vector> 

using namespace TB;
using namespace std;

vector<string> Toolbox::split(string line)
{
	vector<string> keys;
	keys.push_back("hello");
	keys.push_back("goodbye");
	return keys;
	/*string word = "";
	string whole = "";
	int counter = 0;
	for (char x : line)
	{
		if (x == ' ')
		{
			whole = whole + word;
			word = ":";
			counter += 1;
		}
		else
		{
			word = word + x;
		}
	}
	string colthing = whole + word;

	string keys[counter];
	word = "";
	counter = 0;
	for (char x : line)
	{
		if (x == ' ')
		{
			keys[counter] = word;
			word = "";
			counter++;
		}
		else
		{
			word = word + x;
		}
	}
	return keys;*/
}