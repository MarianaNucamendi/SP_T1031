#pragma once
#include "BinaryTree.h"
#include "Monster.h"

class Catalog{
public:
    Catalog();
    ~Catalog();

    bool loadMonsters(std::string csv);
    Monster* selectRandomMonster();
private:
    BinaryTree<Monster> monsterTree;
};