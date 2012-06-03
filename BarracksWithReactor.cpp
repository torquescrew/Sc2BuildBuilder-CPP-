/* 
 * File:   BarracksWithReactor.cpp
 * Author: Toby
 * 
 * Created on May 9, 2012, 11:16 AM
 */

#include "BarracksWithReactor.h"
#include "AllEntities.h"
#include "GameState.h"

BarracksWithReactor::BarracksWithReactor() {
  name = E::BARRACKS_WITH_REACTOR;
  builtBy.push_back(E::BARRACKS);
  required.push_back(E::REFINERY);
}

BarracksWithReactor::~BarracksWithReactor() {
}

void BarracksWithReactor::complete(GameState* gs) {

  std::vector<Entity *> *ents = &gs->getAe()->getEntities();
  for (unsigned long i = 0; i < ents->size(); i++) {
    if (ents->at(i)->getName() == E::BARRACKS && !((Producer*)(ents->at(i)))->busy()) {
      ents->erase(ents->begin() + i);
      Entity::complete(gs);
    }
  }

//  for (Entity *e : gs->getAe()->getEntities()) {
//    if (e->getName() == E::BARRACKS && !((Producer*)e)->busy()) {
//      e = this;
//    }
//  }
}
