/* 
 * File:   Reactor.cpp
 * Author: Toby
 * 
 * Created on May 9, 2012, 11:18 AM
 */

#include "Reactor.h"
#include "AllEntities.h"
#include "GameState.h"

Reactor::Reactor() {
  minerals = 50;
  gas = 50;
  buildTime = 50;
  bs2 = new BuildSlot();
}

Reactor::~Reactor() {
  delete bs2;
}

bool Reactor::checkForBuilt(int time) {
  checkTime = time;
  return bs->checkForFinished(time) || bs2->checkForFinished(time);
}

bool Reactor::tryBuildEntity(Entity* e, int time) {
  return bs->tryBuild(e, time) || bs2->tryBuild(e, time);
}

Entity* Reactor::getBuiltEntity() {
  if (bs->checkForFinished(checkTime)) {
    return bs->getNewEntity();
  }
  return bs2->getNewEntity();
}

bool Reactor::busy() const {
  return bs->isBusy() && bs2->isBusy();
}

void Reactor::update(GameState* gs) {
  if (checkForBuilt(gs->getTime())) {
    gs->getAe()->addNew(getBuiltEntity());
  }
  if (checkForBuilt(gs->getTime())) {
    gs->getAe()->addNew(getBuiltEntity());
  }
}
