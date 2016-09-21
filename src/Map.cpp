/*
 * Map.cpp
 *
 *  Created on: 19 giu 2016
 *      Author: adileobarone
 */


#include "Map.hpp"
#include "GameManager.hpp"
#include <stdlib.h>
#include <time.h>

/*
 * RoomList
 */

RoomList::RoomList(){
    head = NULL;
    tail = NULL;
    size = 0;
}
void RoomList::push(Room* rm){
    RoomNode* n = new RoomNode;
    n->value = rm;
    n->next = NULL;
    if(head == NULL){
        head = n;
        tail = n;
    }else{
        tail->next = n;
        tail = n;
    }
    size++;
}
RoomNode* RoomList::getHead(){
    return head;
}
RoomNode* RoomList::getBack(){
    return tail;
}
int RoomList::length(){
    return size;
}
void RoomList::destroy(){
    RoomNode* node = getHead();
    while(node != NULL){
        RoomNode* next = node->next;
        
        delete node->value;
        delete node;
        
        node = next;
    }

}

/*
 * Map
 */
Map::Map(GameManager* g){
	gm = g;
}

Map::~Map () {
	VLOG(1) << "Map Destructor";
	//roomList.clear();
    rmlist.destroy();
}

/**
 * restituisce una stanza nelle coordinate specificate, se non esiste la crea e la linka alle altre
 */
Room* Map::getRoomOrCreate(Coord coord){
	VLOG(1) << "getRoomOrCreate (" << coord.x << ", " << coord.y << ")" ;
	/* IMPLEMENTAZIONE TRAMITE STD LIST
    for (std::list<Room>::iterator it = roomList.begin(); it != roomList.end(); it++){
		if( it->getCoord().x == coord.x && it->getCoord().y == coord.y){
			VLOG(1) << "room found return it" ;
			return &*it;
		}
	}
     */
    
    RoomNode* node = rmlist.getHead();
    while(node != NULL){
        if( node->value->getCoord().x == coord.x && node->value->getCoord().y == coord.y){
            VLOG(1) << "room found return it" ;
            return node->value;
        }
        node = node->next;
    }
    


	//Se la stanza non esiste la creo e linko le stanze adiacenti a vicenda
	VLOG(1) << "room not found creating it" ;

    /* IMPLEMENTAZIONE TRAMITE STD LIST
	//Room rm = Room(coord); //Oggetto locale temporaneo che poi viene clonato nella lista
	Room rmpt = Room(coord);
	//pushando in lista l'oggetto viene clonato nell'heap, mentre rmpt va out of scope quando questo metodo fa il return
	roomList.push_back(rmpt);

	Room* insertedRoom = &roomList.back();

	//Linko la stanza alle adiacenti, non posso farlo prima del push_back altrimenti le referenza alla stanza rmpt non hanno senso in quanto va out of scope
	VLOG(1) << "linking room with adjacent" ;
	for (std::list<Room>::iterator it = roomList.begin(); it != roomList.end(); it++){
			if( it->getCoord().x == coord.x-1 && it->getCoord().y == coord.y){
				it->setAdjRoom(insertedRoom, East);
				insertedRoom->setAdjRoom(&*it, West);
			}
			if( it->getCoord().x == coord.x+1 && it->getCoord().y == coord.y){
				it->setAdjRoom(insertedRoom, West);
				insertedRoom->setAdjRoom(&*it, East);
			}
			if( it->getCoord().x == coord.x && it->getCoord().y == coord.y-1){
				it->setAdjRoom(insertedRoom, South);
				insertedRoom->setAdjRoom(&*it, North);
			}
			if( it->getCoord().x == coord.x && it->getCoord().y == coord.y+1){
				it->setAdjRoom(insertedRoom, North);
				insertedRoom->setAdjRoom(&*it, South);
			}
	}

	//Se la cella non è 0,0 c'è una probabilità del 5% di trovare l'oggetto della vittoria
	//Casto esplicitamente l'INT poichè time è un float
    srand ((unsigned int) time(NULL));
	if(insertedRoom->getCoord().x != 0 && insertedRoom->getCoord().y != 0 && (rand() % 100 + 1) <= 15){
		gm->win();
	}

	return &roomList.back();
    */
    
    Room* rm = new Room(coord);
    rmlist.push(rm);
    Room* insertedRoom = rmlist.getBack()->value;
    VLOG(1) << "linking room with adjacent" ;

    RoomNode* node2 = rmlist.getHead();
    while(node2 != NULL){
        if( node2->value->getCoord().x == coord.x-1 && node2->value->getCoord().y == coord.y){
            node2->value->setAdjRoom(insertedRoom, East);
            insertedRoom->setAdjRoom(node2->value, West);
        }
        if( node2->value->getCoord().x == coord.x+1 && node2->value->getCoord().y == coord.y){
            node2->value->setAdjRoom(insertedRoom, West);
            insertedRoom->setAdjRoom(node2->value, East);
        }
        if( node2->value->getCoord().x == coord.x && node2->value->getCoord().y == coord.y-1){
            node2->value->setAdjRoom(insertedRoom, South);
            insertedRoom->setAdjRoom(node2->value, North);
        }
        if( node2->value->getCoord().x == coord.x && node2->value->getCoord().y == coord.y+1){
            node2->value->setAdjRoom(insertedRoom, North);
            insertedRoom->setAdjRoom(node2->value, South);
        }
        node2 = node2->next;
    }
    
    //Se la cella non è 0,0 c'è una probabilità del 5% di trovare l'oggetto della vittoria
    //Casto esplicitamente l'INT poichè time è un float
    srand ((unsigned int) time(NULL));
    if(insertedRoom->getCoord().x != 0 && insertedRoom->getCoord().y != 0 && (rand() % 100 + 1) <= 15){
        gm->win();
    }

    return rmlist.getBack()->value;
}
Room* Map::getRoom(Coord coord){
	VLOG(1) << "getRoom (" << coord.x << ", " << coord.y << ")" ;



    /* IMPLEMENTAZIONE TRAMITE STD LIST

	for (std::list<Room>::iterator it = roomList.begin(); it != roomList.end(); ++it){
		//@TODO segmentation fault se esco dal gioco e rientro


		if( it->getCoord().x == coord.x && it->getCoord().y == coord.y){

			return &*it;
		}
	}
     */
    RoomNode* node = rmlist.getHead();
    while(node != NULL){
        if( node->value->getCoord().x == coord.x && node->value->getCoord().y == coord.y){
            VLOG(1) << "room found return it" ;
            return node->value;
        }
        node = node->next;
    }

    
    
	return NULL;
}

//std::list<Room>* Map::getRooms(){
RoomList* Map::getRooms(){
	VLOG(1) << "getRooms" ;
	//return &roomList;
    return &rmlist;
}
