/*
 * GameManager.hpp
 *
 *  Created on: 18 giu 2016
 *      Author: adileobarone
 *
 *	Il GameManager gestisce la partita di gioco, i turni, la mappa, i player e gli oggetti presenti.
 *	Il testo in input viene passato al currentPlayer.
 */



#ifndef GAMEMANAGER_HPP_
#define GAMEMANAGER_HPP_
#include <list>
#include "WorldObject.hpp"
#include "Map.hpp"
#include "Character.hpp"
#include "Renderer.hpp"
#include "lib/easylogging++.hpp"

class GameManager {
private:
	//Elenca tutti gli oggetti presenti nel mondo puntandoli
	std::list<WorldObject*> worldObjectList;
	//Elenca tutti i player
	std::list<Character> characterList;
	std::list<Character>::iterator currentPlayer;

	Map map;
	Renderer renderer;

	int turn;
	int inGame;

public:
	GameManager();
	~GameManager();
	void start();
	void nextTurn();
	void addPlayer(std::string s);

	//passo l'input a tutti i world objects, o solo quelli di una categoria, poi loro vedono come gestirli
	void handleInput(std::string s);
	void reset();
	void win();
	Map* getMap();
	Renderer* getRenderer();
	Character* getCurrentPlayer();
	std::list<Character*> getPlayersAtPosition(Coord pos);
};


#endif /* GAMEMANAGER_HPP_ */
