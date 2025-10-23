#pragma once
#include "BinaryTree.h"
#include "Monster.h"

class Catalog{
public:
    Catalog();
    ~Catalog();

    bool loadMonsters();
private:
    BinaryTree<Monster> monsterTree;
};