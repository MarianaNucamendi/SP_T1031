#include "Dungeon.h"
#include "Room.h"
#include "DoubleLinkedList.h"

#include <iostream>

Dungeon::Dungeon(){}

Dungeon::~Dungeon(){
    roomList.clear();
}

void Dungeon::loadRoom(Room room){
    roomList.insertTail(room);
}

void Dungeon::printRooms(){
    roomList.printList();
}