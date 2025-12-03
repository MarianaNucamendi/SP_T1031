#include <iostream>
#include "Catalog.h"
#include "Dungeon.h"
#include "Room.h"
#include "Player.h"
#include "Graph.h" 

int main(){
    unsigned int start = 0, end = 0;

    Catalog catalog;
    Dungeon dungeon;

    if(!catalog.loadMonsters("monsters.csv")){
        std::cerr << "No se pudo crear el catálogo\n";
        return -1;
    }

    std::cout << "Creando Dungeon...\n\n";
    
    if(!dungeon.createDungeon("dungeon.txt")){
        std::cerr << "No se pudo cargar el archivo con la dungeon\n";
        return -1;
    }

    for(unsigned int i = 0; i < dungeon.getSize(); i++){
        Monster *monster = catalog.selectRandomMonster();
        if(!monster){
            std::cerr << "No se pudo obtener un monstruo del catálogo\n";
            return -1;
        }
        Monster monsterCopy = *monster;

        if(!dungeon.createRoom(monsterCopy)){
            std::cerr << "No se puso insertar el cuarto al calabozo\n";
            return -1;
        }
    }

    dungeon.printRooms();

    std::cout << "Elige una ruta:\n";

    do{
        std::cout << "Dame el cuarto incial: ";
        std::cin >> start;
        
        std::cout << "Dame el cuarto final: ";
        std::cin >> end;
    }while(end > dungeon.getSize() || start > dungeon.getSize() || start == end);
   
    if(!dungeon.traceRoute(start, end)){
        std::cerr << "No existe ruta de " << start << " a " << end << std::endl;
        return -1;
    }
  
    do {
        Room *current = nullptr;
        current = dungeon.getCurrentRoom();
        
        if(current)
            std::cout << *current << "\n";
        
    } while (dungeon.advanceRoute());
    return 0;
}