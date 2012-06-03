/*
 * Producer.cpp
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#include "Producer.h"
#include "GameState.h"
#include "AllEntities.h"
#include "F.h"
#include <iostream>

Producer::Producer() {
	bs = new BuildSlot();
}

Producer::~Producer() {
	delete bs;
}

bool Producer::checkForBuilt(int time) {
	return bs->checkForFinished(time);
}

bool Producer::tryBuildEntity(Entity *e, int time) {
	return bs->tryBuild(e, time);
}

Entity* Producer::getBuiltEntity() {
	return bs->getNewEntity();
}

void Producer::acknowledgeBuilt() {
  bs->reset();
}

bool Producer::busy() const {
	return bs->isBusy();
}

bool Producer::buildingAddon() {
  if (busy() && !bs->eIsUnit()) {
    return true;
  }
  return false;
}

void Producer::reset() {
//  std::cout << "Producer.reset()" << std::endl;
  bs->reset();
}

void Producer::update(GameState* gs) {
	if (checkForBuilt(gs->getTime())) {
		gs->getAe()->addNew(getBuiltEntity());
	}
}
