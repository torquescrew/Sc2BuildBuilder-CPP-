/* 
 * File:   Refinery.cpp
 * Author: Toby
 * 
 * Created on May 8, 2012, 3:52 PM
 */

#include <iostream>
#include "Refinery.h"

Refinery::Refinery() {
  minerals = 75;
  gas = 0;
  buildTime = 30;
  name = E::REFINERY;
  builtBy.push_back(E::SCV);
  wantedScvs = 3;
  attachedToCommand = false;
}

Refinery::~Refinery() { // TODO needs deleting?
//  if (!Config::isEntityPool()) {
//    for (unsigned long i = 0; i < workers.size(); i++) {
//      delete workers[i];
//    }
//  }
}

void Refinery::update(GameState* gs) {
  if (isAttachedToCommand(gs)) {
    gs->addGas(gasMined());
  }
  if (workers.size() < wantedScvs) {
    sendToMine(gs->getAe()->getScvOffMining());
  }
}

void Refinery::reset() {

  attachedToCommand = false;
  workers.clear();
}

bool Refinery::isAttachedToCommand(GameState* gs) {
  if (attachedToCommand) {
    return true;
  } else if (tryAttachToCommand(gs)) {
    return true;
  }
  return false;
}

bool Refinery::tryAttachToCommand(GameState* gs) {
  std::vector<Command*> CCs = gs->getAe()->getCommands();
  for (unsigned long i = 0; i < CCs.size(); i++) {
    if (CCs[i]->tryAttachRefinery()) {
      attachedToCommand = true;
      return true;
    }
  }
  return false;
}

double Refinery::gasMined() {
  if (workers.size() == 1) {
    return 0.625;
  } else if (workers.size() == 2) {
    return 1.258;
  } else if (workers.size() == 3) {
    return 1.792;
  } else {
    return 0.0;
  }
}

void Refinery::sendToMine(Entity* e) {
  if (e != 0) {
    workers.push_back(e);
  }
//  else {
//    std::cout << "e == 0" << std::endl;
//  }
}

bool Refinery::meetsRequired(GameState *gs) {
  unsigned CcNum = gs->getAe()->getCommands().size();
  unsigned refNum = gs->getAe()->getNumOf(this);

  if (gs->getSupply() <= (3 * (refNum + 1)+1)) {
    return false;
  }
  if (refNum >= (CcNum * 2)) {
    return false;
  }
  return true;
}
