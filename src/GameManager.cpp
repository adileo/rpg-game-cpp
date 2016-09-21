/*
 * GameManager.cpp
 *
 *  Created on: 19 giu 2016
 *      Author: adileobarone
 */



#include "GameManager.hpp"

using namespace std;

GameManager::GameManager()
: renderer(this), map(this)
{

	turn = 0;
	inGame = 0;

}

void GameManager::start(){

	int n_players = 0;

	cout << "Quanti giocatori (numero)?" << endl;
	cin >> n_players;
	//cin.ignore(); //Rimuovo il trailing /n
	while(std::cin.fail() || n_players == 0) {
		std::cout << "Errore, inserisci un numero maggiore di 0" << std::endl;
		std::cin.clear();
		std::cin.ignore(256,'\n');
		std::cin >> n_players;
	}
	cin.ignore();
	string p_name;

	for (int i = 1; i <= n_players; i++){
		cout << "Nome giocatore "<< i << ":" << endl;
		getline(cin, p_name);
		addPlayer(p_name);
	}
	cout << "Inizio del gioco" << endl;
	currentPlayer = characterList.begin();

	nextTurn();
	inGame = 1;
	string s;
	while(inGame){
		getline(cin, s);
		handleInput(s);
	}
	cout << "Ritorno al menù principale" << endl;



}

void GameManager::nextTurn(){
	//Vado al prossimo giocatore
	if(turn > 0){
		if(std::next(currentPlayer) == characterList.end()){
			currentPlayer = characterList.begin();
		}else{
			currentPlayer = std::next(currentPlayer);
		}
	}

	turn++;
    cout << endl << endl << endl << endl << endl;
    cout << "--------------------------" << endl;
	cout << "Turno "<< turn << " - Gioca " << currentPlayer->getName() << endl;
	
	currentPlayer->setEnergy(100);
    renderer.renderGUI();
}

void GameManager::addPlayer(string s){
	Coord cd = {0,0};
	map.getRoomOrCreate(cd);
	Character player = Character(this, s);
	player.setPosition(cd);
	//worldObjectList.push_back(player);
	characterList.push_back(player);
	worldObjectList.push_back(&characterList.back());
}

//passo l'input a tutti i player
void GameManager::handleInput(string s){

	//passo tutti i vari input al player attuale
	if(currentPlayer->handleInput(s)){
		renderer.renderGUI();
		if(currentPlayer->getEnergy() == 0){
			cout << "Energia terminata, passo il turno automaticamente" << endl;
			nextTurn();
		}
        if(gameWon == 1){
            cout << "+++++++ Vince " << getCurrentPlayer()->getName() << " +++++++" << endl;
            inGame = 0;
        }
		//Dopo ogni input renderizzo la scena
	}else if(s == "end turn"){
		nextTurn();
	}else if(s == "exit"){
		cout << "Esco dalla partita" << endl;
		inGame = 0;
	}else if(s == "help"){
		cout << "Lista Comandi in Game:" << endl;
		cout << "move [n,e,s,w]" << endl;
		cout << "end turn" << endl;
	}else{
		cout << "Comando non trovato, digita 'help' per la guida" << endl;
	}


}
GameManager::~GameManager () {
	VLOG(1) << "GameManager Destructor";

}
Map* GameManager::getMap(){
	return &map;
}
Renderer* GameManager::getRenderer(){
	return &renderer;
}
Character* GameManager::getCurrentPlayer(){
	return &*currentPlayer;
}

std::list<Character*> GameManager::getPlayersAtPosition(Coord pos){
	std::list<Character*> li;
	for (std::list<Character>::iterator it = characterList.begin(); it != characterList.end(); it++){
			if( it->getPosition().x == pos.x && it->getPosition().y == pos.y){
				li.push_back(&*it);
			}
	}
	return li;
}

void GameManager::win(){
	gameWon = 1;
	inGame = 0;
}



