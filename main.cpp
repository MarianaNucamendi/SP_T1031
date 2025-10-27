#include <iostream>
#include "Catalog.h"
#include "Dungeon.h"
#include "Room.h"
#include "Player.h"

#define N_ROOMS 20  

int main(){
    Catalog catalog;
    Dungeon dungeon;

    if(!catalog.loadMonsters("monsters.csv")){
        std::cerr << "No se pudo crear el catálogo\n";
        return -1;
    }

    std::cout << "Creando Dungeon...\n\n";
    for(int i = 0; i < N_ROOMS; i++){
        Monster monster = *(catalog.selectRandomMonster());
        Room room(monster);
        dungeon.loadRoom(room);
    }

    dungeon.printRooms();
    
    return 0;
}