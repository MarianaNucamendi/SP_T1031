#pragma once
#include "Monster.h"

class Room{
public:
    Room();
    Room(Monster monster);
    ~Room();

    friend std::ostream& operator<<(std::ostream& os, const Room &room);
private:
    Monster monster;
};