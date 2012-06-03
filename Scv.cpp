/*
 * Scv.cpp
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#include "Scv.h"
#include "GameState.h"
#include <iostream>

Scv::Scv() {
	minerals = 50;
	gas = 0;
	buildTime = 17;
	name = E::SCV;
	supply = 1;
  builtBy.push_back(E::COMMAND_CENTER);
  builtBy.push_back(E::ORBITAL_COMMAND);
  builtBy.push_back(E::PLANETARY_FORTRESS);
}

Scv::~Scv() {
}

void Scv::complete(GameState* gs) {
  gs->getAe()->sendToMine(this);
}
//void Scv::update(GameState *gs) {
//  std::cout << "called from Scv" << std::endl;
//}