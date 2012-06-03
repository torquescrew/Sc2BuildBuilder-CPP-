/* 
 * File:   OrbitalCommand.cpp
 * Author: Toby
 * 
 * Created on May 8, 2012, 5:54 PM
 */


#include <iostream>

#include "OrbitalCommand.h"
#include "AllEntities.h"
#include "Config.h"
#include "GameState.h"

OrbitalCommand::OrbitalCommand() {
  minerals = 150;
  buildTime = 35;
  name = E::ORBITAL_COMMAND;
  builtBy.push_back(E::COMMAND_CENTER);
  required.push_back(E::BARRACKS);
  energy = new Energy();
  mules = new Mules();
  //  providedSupply = 11;
}

OrbitalCommand::~OrbitalCommand() {
  delete energy;
  delete mules;
}

void OrbitalCommand::update(GameState* gs) {
  Command::update(gs);
  updateMules(gs);
}

// TODO this can be rewritten now

void OrbitalCommand::complete(GameState* gs) {
  std::vector<Entity *> *ents = &gs->getAe()->getEntities();
  for (unsigned int i = 0; i < ents->size(); i++) {
    if (ents->at(i)->getName() == E::COMMAND_CENTER && !((Command*) (ents->at(i)))->busy()) {
      Command *cc = ((Command*) (ents->at(i)));
      attachedRefineries = cc->getAttachedRefineries();
      cc->transferWorkers(workersOnMinerals);
      
      ents->at(i) = this;
//      ents->erase(ents->begin() + i);

      //      std::cout << cc->getProvidedSupply() << std::endl;

//      Entity::complete(gs);
      //      if (!Config::isEntityPool()) {
      //        delete cc;
      //      }
    }
  }
}

void OrbitalCommand::reset() {
  Command::reset();
  mules->reset();
  energy->reset();
}

void OrbitalCommand::updateMules(GameState* gs) {
  energy->update();
  if (energy->trySpend()) {
    mules->addMule(gs->getTime());
  }
  gs->addMinerals(mules->getMineralsFromMules(gs->getTime()));
}

bool OrbitalCommand::meetsRequired(GameState *gs) {
  if (gs->getAe()->contains(E::BARRACKS)
          || gs->getAe()->contains(E::BARRACKS_WITH_REACTOR)
          || gs->getAe()->contains(E::BARRACKS_WITH_TECHLAB)) {
    return true;
  }
  return false;
  //  return true;/
}