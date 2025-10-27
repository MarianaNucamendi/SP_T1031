#include "Catalog.h"
#include "BinaryTree.h"
#include "Monster.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

Catalog::Catalog(){}

Catalog::~Catalog(){
    monsterTree.clear();
}

bool Catalog::loadMonsters(std::string csv){
    std::ifstream file(csv);

    if(!file.is_open())
        return false;

    std::string line;

    if(!std::getline(file, line)){
        file.close();
        return false;
    }

    while(std::getline(file, line)){
        std::stringstream ss(line);
        std::string name;
        float cr;
        std::string type;
        std::string size;
        int ac;
        int hp;
        std::string align; 

        std::string cell;

        std::getline(ss, name, ',');
        std::getline(ss, cell, ',');
        cr = std::stof(cell);
        std::getline(ss, type, ',');
        std::getline(ss, size, ',');
        std::getline(ss, cell, ',');
        ac = std::stoi(cell);
        std::getline(ss, cell, ',');
        hp = std::stoi(cell);
        std::getline(ss, align, ',');

        Monster newMonster(name, cr, type, size, ac, hp, align);

        monsterTree.insert(newMonster);
    }

    file.close();
    return true;
}

Monster* Catalog::selectRandomMonster(){
    return monsterTree.randomNode();
}