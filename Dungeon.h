#pragma once

#include "DoubleLinkedList.h"
#include "Room.h"
#include "Monster.h"

class Dungeon{
public:
    Dungeon();
    ~Dungeon();
    bool createRoom(Monster monster);
    void printRooms();

private:
    DoubleLinkedList<Room> roomList;
};