/*
 * Room.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 */


#ifndef ROOM_HPP_
#define ROOM_HPP_
#include "Coord.hpp"
#include "lib/easylogging++.hpp"

class Room{
private:
	Coord coord;
	Room* north;
	Room* east;
	Room* west;
	Room* south;
public:
	Room(Coord c);
	~Room();
	void setAdjRoom(Room* room, Directions dir);
	Room* getAdjRoom(Directions dir);
	void setCoord(int x, int y);
	Coord getCoord();
	int walkable();
};



#endif /* ROOM_HPP_ */
