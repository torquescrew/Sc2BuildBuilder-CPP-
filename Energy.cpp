/* 
 * File:   Energy.cpp
 * Author: Toby
 * 
 * Created on May 8, 2012, 6:03 PM
 */

#include "Energy.h"

Energy::Energy() {
  energy = 50.0;
  spellCost = 50.0;
  maxEnergy = 199.4375;
}

Energy::Energy(double startEnergy, double spellCost, double maxEnergy) {
  energy = startEnergy;
  this->spellCost = spellCost;
  this->maxEnergy = maxEnergy;
}

Energy::~Energy() {
}

bool Energy::trySpend() {
  if (this->energy >= spellCost) {
    this->energy -= spellCost;
    return true;
  }
  return false;
}

void Energy::update() {
  if (energy < maxEnergy) {
    energy += 0.5625;
  }
}

void Energy::reset() {
  energy = 50.0;
}