#pragma once

#include "LinkedList.h"
#include "Monster.h"

class Player{
public:
    Player();
    Player(std::string username, int ac, int hp);
    ~Player();

    bool insertDefeated(Monster *monster);
private:
    std::string username;
    int ac;
    int hp;
    LinkedList<Monster*> defeatedMonsters;
};