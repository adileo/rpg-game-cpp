/*
 * Character.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 */

#ifndef CHARACTER_HPP_
#define CHARACTER_HPP_
#include <iostream>
#include "WorldObject.hpp"
#include "lib/easylogging++.hpp"

using namespace std;


class Character : public WorldObject{
private:
	string name;
	int energy;
public:
	Character(GameManager* gm, string character_name);
	string getName() const;
	void setEnergy(int x);
	int getEnergy() const;
	void move(Directions dir);
	void move(Coord coord);
	int handleInput(string s);

};



#endif /* CHARACTER_HPP_ */
