/*
 * CommandCenter.cpp
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#include "CommandCenter.h"

CommandCenter::CommandCenter() {
	minerals = 400;
	buildTime = 100;
	providedSupply = 11;
	name = E::COMMAND_CENTER;
	builtBy.push_back(E::SCV);
}

CommandCenter::~CommandCenter() {

}

void CommandCenter::update(GameState *gs) {
  Command::update(gs);
}

void CommandCenter::complete(GameState* gs) {
  Entity::complete(gs);
//  Supplier::complete(gs);
  gs->addSupplyMax(providedSupply);
}