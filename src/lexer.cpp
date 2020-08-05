// my_class.cpp
#include "lexer.h"  // header in local directory
#include <iostream> // header in standard library
#include "toolbox.h"
#include <vector>

using namespace LEX;
using namespace TB;
using namespace std;

vector<string> Lexer::lexline(string line)
{
    Toolbox toolbox;
    vector<string> lexed = toolbox.split(line, " ");
    return lexed;
}