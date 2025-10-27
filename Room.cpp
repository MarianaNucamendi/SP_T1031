#include "Room.h"
#include "Catalog.h"
#include "Monster.h"

#include <iostream>

Room::Room(){}

Room::Room(Monster monster): monster(monster){}

Room::~Room(){}

std::ostream& operator<<(std::ostream& os, const Room &room){
    os << "Cuarto con:" << room.monster;
    return os;
}