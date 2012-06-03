/*
 * Entity.cpp
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#include "Entity.h"
#include "AllEntities.h"
#include "GameState.h"
#include "F.h"
#include <string>
#include <iostream>

Entity::Entity() {
  minerals = 0;
  gas = 0;
  buildTime = 0;
  supply = 0;
  providedSupply = 0;
  name = E::EMPTY;
}

Entity::~Entity() {
}

int Entity::getBuildTime() const {
  return buildTime;
}

int Entity::getGas() const {
  return gas;
}

int Entity::getMinerals() const {
  return minerals;
}

E::Name Entity::getName() const {
  return name;
}

bool Entity::meetsRequired(GameState *gs) {
  if (this->getRequired().size() == 0) {
    return true;
  } else {
    std::vector<E::Name>::iterator it;
    for (unsigned int i = 0; i < this->getRequired().size(); i++) {
      if (gs->getAe()->contains(this->getRequired()[i])) {
        return true;
      }
    }
  }
  return false;
}

bool Entity::meetsCosts(GameState* gs) {
  if (gs->getMinerals() >= minerals && gs->getGas() >= gas && meetsRequired(gs)) {
    if (supply > 0) {
      if ((gs->getSupplyMax() - gs->getSupply()) < supply) {
        return false;
      }
    }
    return true;
  }
  return false;
}

int Entity::getSupply() const {
  return supply;
}

int Entity::getProvidedSupply() const {
  return providedSupply;
}

const std::vector<E::Name>&
Entity::getBuiltBy() const {
  return builtBy;
}

void Entity::payCosts(GameState* gs) {
  gs->spendMinerals(minerals);
  gs->spendGas(gas);
  gs->addSupply(supply);
}

const std::vector<E::Name>&
Entity::getRequired() const {
  return required;
}

//void Entity::update(GameState* gs) {
//}

void Entity::complete(GameState* gs) {
  gs->getAe()->directAdd(this);
}

void Entity::reset() {
  
}

std::string Entity::getNameStr() {
  return F::toString(name);
}

bool Entity::isCommand() {
  return name == E::COMMAND_CENTER || name == E::ORBITAL_COMMAND || name == E::PLANETARY_FORTRESS;
}
