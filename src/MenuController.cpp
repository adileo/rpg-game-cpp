/*
 * MenuController.cpp
 *
 *  Created on: 19 giu 2016
 *      Author: adileobarone
 */

#include "MenuController.hpp"

using namespace std;

MenuController::MenuController(){
	gm = new GameManager();
	inMenu = 1;
}

void MenuController::start(){
	string s;
	while(inMenu){
		getline(cin, s);
		handleInput(s);
	}
}

void MenuController::handleInput(string s){
	if(s == "exit"){
		cout << "Esco dal Gioco" << endl;
		inMenu = 0;
	}else if(s == "new game"){
		gm->start();
		//Per ricominciare una partita
		delete gm;
		gm = new GameManager();
	}else if(s == "help"){
		cout << "Lista dei comandi Menu:" << endl;
		cout << "new game" << endl;
		cout << "exit" << endl;
	}else{
		cout << "Comando non trovato, digita 'help' per la guida." << endl;
	}

}

