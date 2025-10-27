#include <string>
#include "Monster.h"

Monster::Monster(){}

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

void Monster::setName(std::string newName){
    name = newName;
}

void Monster::setCr(float newCr){
    cr = newCr;
}

void Monster::setType(std::string newType){
    type = newType;
}

void Monster::setSize(std::string newSize){
    size = newSize;
}

void Monster::setAc(int newAc){
    ac = newAc;
}

void Monster::setHp(int newHp){
    hp = newHp;
}

void Monster::setAlign(std::string newAlign){
    align = newAlign;
}

bool Monster::operator<(const Monster &monster){
    return name < monster.name;
}

bool Monster::operator>(const Monster &monster){
    return name > monster.name;
}

std::ostream& operator<<(std::ostream& os,const Monster &monster){
    os << monster.name;
    return os;
}