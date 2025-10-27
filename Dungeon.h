#pragma once

#include "DoubleLinkedList.h"
#include "Room.h"

class Dungeon{
public:
    Dungeon();
    ~Dungeon();
    void loadRoom(Room room); // bool
    void printRooms();

private:
    DoubleLinkedList<Room> roomList;
};