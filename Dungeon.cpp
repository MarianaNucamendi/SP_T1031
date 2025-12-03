#include "Dungeon.h"
#include "Room.h"
#include "DoubleLinkedList.h"
#include "Monster.h"

#include <iostream>
#include <climits>

Dungeon::Dungeon() : currentRoomIndex(UINT_MAX), counter(0){}

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

bool Dungeon::createDungeon(std::string fileName){
    return roomGraph.loadFile(fileName);
}

bool Dungeon::traceRoute(unsigned int start, unsigned int end){
    return roomGraph.bsfPath(start, end, &roomPath);
    
}

unsigned int Dungeon::getSize(){
    return roomGraph.getVertexCount();
}

Room* Dungeon::getCurrentRoom(){
    if(currentRoomIndex == UINT_MAX)
        return nullptr;

    auto it = roomList.begin();

    for(unsigned int i = 0; i < currentRoomIndex; i++){
        if(it == roomList.end())
            return nullptr;
        it++;
    }
    return &(*it);
}

bool Dungeon::advanceRoute(){
    if(counter >= roomPath.getSize())
        return false;

    auto it = roomPath.begin();

    for(unsigned int i = 0; i < counter; i++){
        if(it == roomPath.end())
            return false;
        it++;
    }

    currentRoomIndex = *it;
    counter++;
    return true;
}