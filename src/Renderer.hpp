/*
 * Renderer.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 *
 *  Classe che si occupa di renderizzare la mappa, l'interfaccia ed i messaggi in output
 */

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include <list>
#include "Map.hpp"
#include "lib/easylogging++.hpp"

class GameManager;

class Renderer{
private:
	GameManager* gm;
	std::list<std::string> messages;
public:
	Renderer(GameManager* g);
	void renderGUI();
	void addMsg(std::string s);

};



#endif /* RENDERER_HPP_ */
