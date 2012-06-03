/*
 * BuildSlot.cpp
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */

#include "BuildSlot.h"
#include "Config.h"
#include "ObjectPool.h"
#include <iostream>

BuildSlot::BuildSlot() {
  e = 0;
  busy = false;
  finishTime = 0;
}

BuildSlot::~BuildSlot() {
  if (!Config::isEntityPool()) {
    if (busy) {
      delete e;
    }
  }
}

void BuildSlot::reset() {
  busy = false;
}

bool BuildSlot::isBusy() const {
  return busy;
}

int BuildSlot::getFinishTime() const {
  return finishTime;
}

bool BuildSlot::tryBuild(Entity *e, int time) {
  if (!busy) {
    this->e = e;
    busy = true;
    finishTime = time + e->getBuildTime();
    return true;
  }
  return false;
}

bool BuildSlot::checkForFinished(int time) {
  return (busy && finishTime <= time);
}

Entity* BuildSlot::getNewEntity() {
  busy = false;
  return e;
}

bool BuildSlot::eIsUnit() {
  if (e->getSupply() > 0) {
    return true;
  }
  return false;
}