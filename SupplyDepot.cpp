/* 
 * File:   SupplyDepot.cpp
 * Author: Toby
 * 
 * Created on May 8, 2012, 1:46 AM
 */

#include <iostream>
#include "SupplyDepot.h"
#include "GameState.h"

SupplyDepot::SupplyDepot() {
  minerals = 100;
  gas = 0;
  providedSupply = 8;
  name = E::SUPPLY_DEPOT;
  buildTime = 30;
  builtBy.push_back(E::SCV);
}

SupplyDepot::~SupplyDepot() {
}

void SupplyDepot::update(GameState* gs) {}

void SupplyDepot::complete(GameState* gs) {
  gs->addSupplyMax(providedSupply);
  Entity::complete(gs);
}
