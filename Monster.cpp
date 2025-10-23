#include <string>
#include "Monster.h"

Monster::Monster(
    std::string name, 
    float cr, 
    std::string type, 
    std::string size,
    int ac, 
    int hp, 
    std::string align) 
    
    : name(name), 
    cr(cr),
    type(type),
    size(size), 
    ac(ac), 
    hp(hp), 
    align(align) {}

Monster::~Monster(){}

bool Monster::operator<(const Monster &current){
    return name < current.name;
}

bool Monster::operator>(const Monster &current){
    return name > current.name;
}

std::ostream& operator<<(std::ostream& os,const Monster &current){
    os << current.name;
    return os;
}