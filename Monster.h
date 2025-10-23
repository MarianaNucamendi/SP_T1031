#pragma once
#include <string>

class Monster{
public:
    Monster(std::string name, float cr, std::string type, 
            std::string size, int ac, int hp, std::string align);
    ~Monster();

    bool operator<(const Monster &current);
    bool operator>(const Monster &current);
    friend std::ostream& operator<<(std::ostream& os, const Monster &current);


private:
    std::string name;
    float cr;
    std::string type;
    std::string size;
    int ac;
    int hp;
    std::string align;
};