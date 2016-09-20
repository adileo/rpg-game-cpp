/*
 * Room.cpp
 *
 *  Created on: 19 giu 2016
 *      Author: adileobarone
 */




/*
 * Room.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 */

#include <iostream>
#include "Room.hpp"


Room::Room(Coord c){
	north = NULL;
	east = NULL;
	west = NULL;
	south = NULL;
	coord = c;
}
Room::~Room(){
	VLOG(1) << "Room Destructor";
	//std::cout << "Room Destructor" << std::endl;
}
void Room::setAdjRoom(Room* room, Directions dir){

	if (dir == North){
		north = room;
	}
	if (dir == East){
		east = room;
	}
	if (dir == West){
		west = room;
	}
	if (dir == South){
		south = room;
	}

}
Room* Room::getAdjRoom(Directions dir){

	if (dir == North){
		return north;
	}
	if (dir == East){
		return east;
	}
	if (dir == West){
		return west;
	}
	if (dir == South){
		return south;
	}
	return NULL;
}
void Room::setCoord(int x, int y){
	coord.x = x;
	coord.y = y;
}
Coord Room::getCoord(){

	return coord;
}

int Room::walkable(){
	return 1;
}
