#include "Dungeon.h"
#include "Room.h"
#include "DoubleLinkedList.h"
#include "Monster.h"

#include <iostream>

Dungeon::Dungeon(){}

Dungeon::~Dungeon(){
    roomList.clear();
}

bool Dungeon::createRoom(Monster monster){
    Room room(monster);
    if(!roomList.insertTail(room))
        return false;
    return true;
}

void Dungeon::printRooms(){
    roomList.printList();
}