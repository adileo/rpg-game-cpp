/*
 * WorldObject.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 */

#ifndef WORLDOBJECT_HPP_
#define WORLDOBJECT_HPP_
#include <iostream>
#include "Coord.hpp"
#include "lib/easylogging++.hpp"


//Faccio una forward declaration per evitare le dipendenze circolari
class GameManager;

class WorldObject{
protected:
	Coord position;
	GameManager* gm;
	std::string name;
public:
	WorldObject(GameManager* g);
	~WorldObject();
	Coord getPosition();
	void setPosition(Coord c);
	int handleInput(std::string s);
	void handleStartTurn();
	void handleEndTurn();
};



#endif /* WORLDOBJECT_HPP_ */
