// my_class.h
#ifndef LEXER_H // include guard
#define LEXER_H
#include <string>
#include <vector>

namespace LEX
{
    class Lexer
    {
    public:
        std::vector<std::string> lexline(std::string line);
    };
} // namespace LEX

#endif /* LEXER_H */