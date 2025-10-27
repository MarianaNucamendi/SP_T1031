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
        int counter = 0;

        Monster newMonster;

        while(std::getline(ss, cell, ',')){
            counter++;
            switch(counter){
                case 1:
                    newMonster.setName(cell);
                    break;
                case 2:
                    newMonster.setCr(std::stof(cell));
                    break;      
                case 3:
                    newMonster.setType(cell);
                    break;
                case 4:
                    newMonster.setSize(cell);
                    break;
                case 5:
                    newMonster.setAc(std::stoi(cell));
                    break;
                case 6:
                    newMonster.setHp(std::stoi(cell));
                    break;
                case 7:
                    newMonster.setAlign(cell);
                    break;
            }
        }
       
        if(counter == 7){
            monsterTree.insert(newMonster);
        }
    }
    file.close();
    return true;
}

Monster* Catalog::selectRandomMonster(){
    return monsterTree.randomNode();
}