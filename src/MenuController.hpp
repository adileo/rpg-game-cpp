/*
 * MenuController.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 *
 * Si occupa di instanziare il menù di gioco iniziale utilizzabile trabite I/O
 *
 */


#ifndef MENUCONTROLLER_HPP_
#define MENUCONTROLLER_HPP_

#include <iostream>
#include "GameManager.hpp"
#include "lib/easylogging++.hpp"
using namespace std;

class MenuController{
	GameManager* gm;
public:
	MenuController();
	void start();
private:
	void handleInput(string s);
	int inMenu;
};



#endif /* MENUCONTROLLER_HPP_ */
