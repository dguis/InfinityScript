// my_class.h
#ifndef TB_H // include guard
#define TB_H
#include <string>
#include <vector> 

namespace TB
{
    class Toolbox
    {
    public:
        std::vector<std::string> split(std::string line, std::string delim);
    };
} // namespace TB

#endif /* TB_H */