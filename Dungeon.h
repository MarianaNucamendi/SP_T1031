#pragma once

#include "DoubleLinkedList.h"
#include "Room.h"
#include "Monster.h"
#include "Graph.h"

class Dungeon{
public:
    Dungeon();
    ~Dungeon();
    bool createRoom(Monster monster);
    bool createDungeon(std::string fileName);
    bool traceRoute(unsigned int start, unsigned int end);
    unsigned int getSize();
    void printRooms();
    bool advanceRoute();
    Room *getCurrentRoom();

private:
    DoubleLinkedList<Room> roomList;
    Graph<Room> roomGraph;
    LinkedList<unsigned int> roomPath;
    unsigned int currentRoomIndex;
    unsigned int counter;
};