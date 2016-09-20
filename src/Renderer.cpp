/*
 * Renderer.cpp
 *
 *  Created on: 19 giu 2016
 *      Author: adileobarone
 */

#include "Renderer.hpp"
#include "GameManager.hpp"
Renderer::Renderer(GameManager* g){
	gm = g;
}
void Renderer::renderGUI(){
	//Stampo la mappa
	VLOG(1) << "stampo la mappa" ;
	Coord currentPlayerPosition = gm->getCurrentPlayer()->getPosition();
	for(int y = (currentPlayerPosition.y - 6); y <= (currentPlayerPosition.y + 6); y++){
		for(int x = (currentPlayerPosition.x - 8); x <= (currentPlayerPosition.x + 8); x++){
			Coord p;
			p.x = x;
			p.y = y;

			if(gm->getMap()->getRoom(p)){

				std::list<Character*> players = gm->getPlayersAtPosition(p);

				if(players.size() > 0){

					if(currentPlayerPosition.x == p.x && currentPlayerPosition.y == p.y && players.size() == 1){
						std::cout << "[x]";
					}else if (currentPlayerPosition.x == p.x && currentPlayerPosition.y == p.y && players.size() > 1){
						std::cout << "[X]";
					}else if ((currentPlayerPosition.x != p.x || currentPlayerPosition.y != p.y) && players.size() == 1){
						std::cout << "[e]";
					}else if ((currentPlayerPosition.x != p.x || currentPlayerPosition.y != p.y) && players.size() > 1){
						std::cout << "[E]";
					}

				}else{
					std::cout << "[ ]";
				}
			}else{
				std::cout << "   ";
			}
		}
		std::cout << std::endl;
	}
	std::cout << "Energia: " << gm->getCurrentPlayer()->getEnergy() << std::endl;
	//Stampo i messaggi
	for (std::list<std::string>::iterator it = messages.begin(); it != messages.end(); it++){
		std::cout << *it << std::endl;
	}
	messages.clear();
}
void Renderer::addMsg(std::string s){
	messages.push_back(s);
}

