/*
 * Character.cpp
 *
 *  Created on: 19 giu 2016
 *      Author: adileobarone
 */

/*
 * Character.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 */

#include "Coord.hpp"
#include "Character.hpp"
#include "GameManager.hpp"

using namespace std;


Character::Character(GameManager* gm, string character_name)
: WorldObject(gm)
{
	name = character_name;
	energy = 0;
}

string Character::getName(){
	return name;
}

void Character::setEnergy(int x){
	energy = x;
}

int Character::getEnergy(){
	return energy;
}

void Character::move(Directions dir){
	Coord ps;
	if(dir == North){
		ps.x = position.x;
		ps.y = position.y-1;
	}else if(dir == South){
		ps.x = position.x;
		ps.y = position.y+1;
	}else if(dir == West){
		ps.x = position.x-1;
		ps.y = position.y;
	}else if(dir == East){
		ps.x = position.x+1;
		ps.y = position.y;
	}

	if(gm->getMap()->getRoomOrCreate(ps)->walkable()){
		VLOG(1) << "i can walk there x:"<< ps.x << " y:" << ps.y ;
		if(energy >= 50){
			position = ps;
			gm->getRenderer()->addMsg("Giocatore mosso in posizione ( "+std::to_string(ps.x)+", "+std::to_string(ps.y)+" )");
			energy -= 50;
		}else{
			gm->getRenderer()->addMsg("Non hai abbastanza energia per muoverti");
		}
	}

}

void Character::move(Coord coord){
	if(gm->getMap()->getRoomOrCreate(coord)->walkable()){

			position = coord;
			gm->getRenderer()->addMsg("Giocatore teletrasportato in posizione ( "+std::to_string(coord.x)+", "+std::to_string(coord.y)+" )");

	}

}


int Character::handleInput(string s){
	if(s == "move n"){
		move(North);
		return 1;
	}else if(s == "move s"){
		move(South);
		return 1;
	}else if(s == "move w"){
		move(West);
		return 1;
	}else if(s == "move e"){
		move(East);
		return 1;
	}else{
		return 0;
	}
	return 0;
}


