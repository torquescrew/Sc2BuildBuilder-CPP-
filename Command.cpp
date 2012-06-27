/*
 * Command.cpp
 *
 *  Created on: May 6, 2012
 *      Author: Toby
 */
#include "Command.h"
#include <iostream>
#include "GameState.h"

Command::Command() {
  attachedRefineries = 0;
}

Command::~Command() {
//  for (unsigned long i = 0; i < workersOnMinerals.size(); i++) {
//    delete workersOnMinerals[i];
//  }
}

void Command::update(GameState* gs) {
  gs->addMinerals(mineralsMined(numberMining()));
  //	Producer::update(gs);
  if (checkForBuilt(gs->getTime())) {
    //    Entity* e = getBuiltEntity();
    
    gs->getAe()->addNew(getBuiltEntity());
  }
}

void Command::complete(GameState* gs) {
  
}

void Command::reset() {
  //  std::cout << "Command.reset" << std::endl;
  Producer::reset();
  workersOnMinerals.clear();
  attachedRefineries = 0;
}

void Command::sendToMineMinerals(Entity* scv) {
  workersOnMinerals.push_back(scv);
}

bool Command::tryAttachRefinery() {
  if (attachedRefineries < 2) {
    attachedRefineries++;
    return true;
  }
  return false;
}

Entity* Command::getScv() {
  if (workersOnMinerals.size() > 0) {
    Entity *s = workersOnMinerals.back();
    workersOnMinerals.pop_back();
    return s;
  }
  else {
    return 0;
  }
}

int Command::numberMining() {
  return (int)workersOnMinerals.size();
}

void Command::setAttachedRefineries(int n) {
  attachedRefineries = n;
}

int Command::getAttachedRefineries() {
  return attachedRefineries;
}

std::vector<Entity*> & Command::getWorkersOnMinerals() {
  return workersOnMinerals;
}

void Command::transferWorkers(std::vector<Entity *> &workersOnMinerals) {
  for (unsigned long i = 0; i < this->workersOnMinerals.size(); i++) {
    workersOnMinerals.push_back(this->workersOnMinerals[i]);
  }
  this->workersOnMinerals.clear();
}

int Command::getProvidedSupply() {
  return providedSupply;
}

double Command::mineralsMined(int workers) {
  double mined = 0.0;
  if (workers <= 16) {
    mined = (40.0 * workers) / 60.0;
  } else {
    int n = workers - 16;
    if (n >= 8) {
      mined = 816.0 / 60.0;
    } else {
      mined += 672.0 / 60.0;
      mined += (n * 18.0) / 60.0;
    }
  }
  return mined;
}
