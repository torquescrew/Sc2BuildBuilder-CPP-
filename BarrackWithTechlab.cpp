/* 
 * File:   BarracksWithTechlab.cpp
 * Author: Toby
 * 
 * Created on May 9, 2012, 9:49 AM
 */

#include <iostream>

#include "BarrackWithTechlab.h"
#include "AllEntities.h"
#include "GameState.h"

BarracksWithTechlab::BarracksWithTechlab() {
  minerals = 50;
  gas = 25;
  buildTime = 25;
  name = E::BARRACKS_WITH_TECHLAB;
  builtBy.push_back(E::BARRACKS);
  required.push_back(E::REFINERY);
}

BarracksWithTechlab::~BarracksWithTechlab() {
}

// TODO needs testing
void BarracksWithTechlab::complete(GameState* gs) {
  std::vector<Entity *> *ents = &gs->getAe()->getEntities();
  for (unsigned int i = 0; i < ents->size(); i++) {
    if (ents->at(i)->getName() == E::BARRACKS && !((Producer*)(ents->at(i)))->busy()) {
//      Entity *b = ents->at(i);
      ents->erase(ents->begin() + i);
//      gs->getAe()->directAdd(this);
      Entity::complete(gs);
//      delete b;
//      cout << "should now have techlab" << endl;
    }
  }
}