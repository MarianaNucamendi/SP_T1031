#include <string>
#include "Monster.h"

Monster::Monster(
    std::string name, 
    float cr, 
    std::string type, 
    int ac, 
    int hp, 
    std::string align) 
    
    : name(name), 
    cr(cr),
    type(type), 
    ac(ac), 
    hp(hp), 
    align(align) {}

Monster::~Monster(){}