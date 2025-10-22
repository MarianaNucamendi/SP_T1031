#pragma once
#include <string>

class Monster{
public:
    Monster(std::string name, float cr, std::string type, 
            int ac, int hp, std::string align);
    ~Monster();

private:
    std::string name;
    float cr;
    std::string type;
    int ac;
    int hp;
    std::string align;
};