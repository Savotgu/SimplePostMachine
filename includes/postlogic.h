#ifndef POSTLOGIC_H
#define POSTLOGIC_H

#include <iostream>
#include <string>
#include <stdlib.h>

class PostLogic{
public:
    int sum(std::string &text);
    int sub(std::string &text);
    int mul(std::string &text);
    int div(std::string &text);
};

#endif // POSTLOGIC_H

