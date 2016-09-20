/*
 * Map.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 *
 *  La mappa è composta solo da stanze, non si deve occupare degli oggetti che ci sono sopra,
 *  poichè sono altre entità gestite da altre classi, l'unico link che c'è è quello che ogni oggetto
 *  punta a una posizione della mappa in cui si trova.
 *
 */


#ifndef MAP_HPP_
#define MAP_HPP_
#include <iostream>
#include <list>
#include "Room.hpp"

#include "lib/easylogging++.hpp"

//Faccio una forward declaration per evitare le dipendenze circolari
class GameManager;

class Map{
private:
	std::list<Room> roomList;
	GameManager* gm;
public:
	Map(GameManager* g);
	~Map();
	Room* getRoom(Coord coord);
	Room* getRoomOrCreate(Coord coord);
	std::list<Room>* getRooms();
};



#endif /* MAP_HPP_ */
