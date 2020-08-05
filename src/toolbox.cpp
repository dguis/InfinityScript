// my_class.cpp
#include "toolbox.h" // header in local directory
#include <iostream>	 // header in standard library
#include <vector> 

using namespace TB;
using namespace std;

vector<string> Toolbox::split(string line, string delim)
{
	vector<string> keys;
	
	size_t pos = line.find(delim);

	while (pos != std::string::npos)
	{

		pos = line.find(delim);
		keys.push_back(line.substr(0, pos));
		line = line.substr(pos+1, line.length());

	}

	return keys;
	
}