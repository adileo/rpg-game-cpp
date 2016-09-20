/*
 * WorldObject.cpp
 *
 *  Created on: 19 giu 2016
 *      Author: adileobarone
 */






#include "WorldObject.hpp"

WorldObject::WorldObject(GameManager* g){
	gm = g;

}

WorldObject::~WorldObject(){
	//std::cout << "WorldObject Destructor" << std::endl;
}

Coord WorldObject::getPosition(){
	return position;
}

void WorldObject::setPosition(Coord c){
	position = c;
}


void WorldObject::handleStartTurn(){}

void WorldObject::handleEndTurn(){}
