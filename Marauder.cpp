/* 
 * File:   Marauder.cpp
 * Author: Toby
 * 
 * Created on May 9, 2012, 9:46 AM
 */

#include "Marauder.h"

Marauder::Marauder() {
  minerals = 100;
  gas = 25;
  buildTime = 30;
  supply = 2;
  name = E::MARAUDER;
  builtBy.push_back(E::BARRACKS_WITH_TECHLAB);
}

Marauder::~Marauder() {
}

void Marauder::update(GameState *gs) {}

void Marauder::complete(GameState* gs) {
  
}
