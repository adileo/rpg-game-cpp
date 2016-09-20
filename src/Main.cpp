//============================================================================
// Name        : StateMachineRPG.cpp
// Author      : Adileo Barone
// Version     :
// Copyright   : All rights reserved
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "MenuController.hpp"
#include "lib/easylogging++.hpp"

INITIALIZE_EASYLOGGINGPP

using namespace std;



int main(int argc, char* argv[]) {
	START_EASYLOGGINGPP(argc, argv);
	//el::Loggers::setVerboseLevel(1);
	//LOG(INFO) << "Avvio RPG";
	cout << "Gioco avviato, in qualunque momento digita 'help' per la lista dei comandi disponibili." <<endl;
	cout << "Per avviare un nuovo gioco: new game" << endl;
	MenuController mc = MenuController();
	mc.start();

	return 0;
}
