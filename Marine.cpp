/* 
 * File:   Marine.cpp
 * Author: Toby
 * 
 * Created on May 8, 2012, 4:19 AM
 */

#include "Marine.h"

Marine::Marine() {
  minerals = 50;
  buildTime = 25;
  supply = 1;
  name = E::MARINE;
  builtBy.push_back(E::BARRACKS);
  builtBy.push_back(E::BARRACKS_WITH_REACTOR);
  builtBy.push_back(E::BARRACKS_WITH_TECHLAB);
}


Marine::~Marine() {
}

void Marine::update(GameState *gs) {}

void Marine::complete(GameState* gs) {}
