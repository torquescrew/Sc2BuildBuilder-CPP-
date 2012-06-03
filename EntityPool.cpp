/* 
 * File:   EntityPool.cpp
 * Author: Toby
 * 
 * Created on May 12, 2012, 11:00 PM
 */

#include "EntityPool.h"
#include "Scv.h"
#include <iostream>
#include "CommandCenter.h"
#include "SupplyDepot.h"
#include "Barracks.h"
#include "Refinery.h"
#include "OrbitalCommand.h"
#include "Marine.h"
#include "Marauder.h"
#include "BarrackWithTechlab.h"
#include "BarracksWithReactor.h"

EntityPool::EntityPool() {
  producers.push_back(E::SCV);
  producers.push_back(E::COMMAND_CENTER);
  producers.push_back(E::ORBITAL_COMMAND);
  producers.push_back(E::BARRACKS);
  producers.push_back(E::BARRACKS_WITH_TECHLAB);
  producers.push_back(E::BARRACKS_WITH_REACTOR);
  producers.push_back(E::REFINERY);
}

EntityPool::~EntityPool() {
  // TODO
}

Entity* EntityPool::create(E::Name name) {
  switch (name) {
    case E::SCV:
      return new Scv();
    case E::COMMAND_CENTER:
      return new CommandCenter();
    case E::SUPPLY_DEPOT:
      return new SupplyDepot();
    case E::BARRACKS:
      return new Barracks();
    case E::REFINERY:
      return new Refinery();
    case E::ORBITAL_COMMAND:
      return new OrbitalCommand();
    case E::MARINE:
      return new Marine();
    case E::BARRACKS_WITH_TECHLAB:
      return new BarracksWithTechlab();
    case E::BARRACKS_WITH_REACTOR:
      return new BarracksWithReactor();
    case E::MARAUDER:
      return new Marauder();
    default:
      cout << "entity could not be created!" << endl;
      return 0;
  }
}

Entity* EntityPool::getAny(E::Name name) {
  int i = contains(name);
  if (i != -1) { // if already have one
      return pool[i];
  } else { // don't already have one
    Entity *e = create(name);
    pool.push_back(e);
    return e;
  }
}

Entity* EntityPool::getNew(Info name) {
  int i = contains(name.getName());
  if (i != -1) { // if already have one
    if (isProducer(name)) {
      return sendToInUseAndReturn(i);
    } else {
      return pool[i];
    }
  } else { // don't already have one
    Entity *e = create(name.getName());
    if (isProducer(name)) {
      inUse.push_back(e);
      return e;
    }
    pool.push_back(e);
    return e;
  }
}

Entity* EntityPool::sendToInUseAndReturn(int index) {
  Entity* e = pool[index];
  pool.erase(pool.begin() + index);
  inUse.push_back(e);
  return e;
}

bool EntityPool::isProducer(Info info) {
  for (unsigned int i = 0; i < producers.size(); i++) {
    if (info.getName() == producers[i]) {
      return true;
    }
  }
  return false;
}

int EntityPool::contains(E::Name name) {
  for (unsigned int i = 0; i < pool.size(); i++) {
    if (pool[i]->getName() == name) {
      return i;
    }
  }
  return -1;
}

void EntityPool::returnAllToPool() {
//  std::cout << "pool sizes (" << pool.size() << "/" << inUse.size() << ")" <<  std::endl;
  for (unsigned int i = 0; i < inUse.size(); i++) {
    pool.push_back(inUse[i]);
    inUse[i]->reset();
  }
  inUse.clear();
}

void EntityPool::returnLast() {
  Entity *e = inUse.back();
  inUse.pop_back();
  pool.push_back(e);
}

void EntityPool::printPoolContents() {
  cout << "(";
  for (unsigned int i = 0; i < pool.size(); i++) {
    cout << pool[i]->getNameStr() << ", ";
  }
  cout << ")" << endl;
  cout << "[";
  for (unsigned int i = 0; i < inUse.size(); i++) {
    cout << inUse[i]->getNameStr() << ", ";
  }
  cout << "]";
  cout << endl;
}

int EntityPool::getSize() {
  return (int) pool.size();
}
