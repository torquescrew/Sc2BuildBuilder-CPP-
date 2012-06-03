/* 
 * File:   EntityPool2.cpp
 * Author: Toby
 *
 * Created on May 16, 2012, 9:32 AM
 */

#include "EntityPool2.h"
#include "Entity.h"
#include "Config.h"
#include "CommandCenter.h"
#include "Scv.h"
#include "SupplyDepot.h"
#include "Barracks.h"
#include "Refinery.h"
#include "OrbitalCommand.h"
#include "Marine.h"
#include "BarrackWithTechlab.h"
#include "BarracksWithReactor.h"
#include "Marauder.h"
#include "ProducerStack.h"
#include "EntityStack.h"
#include "F.h"
#include <iostream>

EntityPool2::EntityPool2() {
  init();
}

EntityPool2::~EntityPool2() {
//  for (unsigned int i = 0; i < pool.size(); i++) {
//    delete pool[i];
//  }
  for (Stack* s : pool) {
    delete s;
  }
}

Entity* EntityPool2::getNew(Info name) {
  for (unsigned int i = 0; i < pool.size(); i++) {
    if (pool[i]->equals(name.getName())) {
      return pool[i]->getEntity();
    }
  }
  cout << "couldn't create new entity! ";
  name.print();
  cout << endl;
  exit(1);
}

void EntityPool2::init() {
  for (unsigned int i = 0; i < Config::getAllowed()->size(); i++) {
    E::Name n = Config::getAllowed()->get(i).getName();
    switch (n) {
    case E::SCV:
      pool.push_back(new ProducerStack<Scv > (n));
      break;
    case E::COMMAND_CENTER:
      pool.push_back(new ProducerStack<CommandCenter > (n));
      break;
    case E::SUPPLY_DEPOT:
      pool.push_back(new ProducerStack<SupplyDepot > (n));
      break;
    case E::BARRACKS:
      pool.push_back(new ProducerStack<Barracks > (n));
      break;
    case E::REFINERY:
      pool.push_back(new ProducerStack<Refinery > (n));
      break;
    case E::ORBITAL_COMMAND:
      pool.push_back(new ProducerStack<OrbitalCommand > (n));
      break;
    case E::MARINE:
      pool.push_back(new EntityStack<Marine > (n));
      break;
    case E::BARRACKS_WITH_TECHLAB:
      pool.push_back(new ProducerStack<BarracksWithTechlab > (n));
      break;
    case E::BARRACKS_WITH_REACTOR:
      pool.push_back(new ProducerStack<BarracksWithReactor > (n));
      break;
    case E::MARAUDER:
      pool.push_back(new EntityStack<Marauder > (n));
      break;
    default:
      cout << "entity could not be created!" << endl;
    }
  }
}

Entity* EntityPool2::getAny(E::Name name) {
  for (unsigned int i = 0; i < pool.size(); i++) {
    if (pool[i]->equals(name)) {
      return pool[i]->getEntity();
    }
  }
  cout << "couldn't create new entity! " << F::toString(name) <<  cout << endl;
  exit(1);
}

int EntityPool2::getSize() {
  int size = 0;
  for (unsigned int i = 0; i < pool.size(); i++) {
    size += pool[i]->getSize();
  }
  return size;
}

void EntityPool2::returnAllToPool() {
  //  cout << "************** RETRIEVE ENTITIES **************************" << endl;
  for (unsigned int i = 0; i < pool.size(); i++) {
    pool[i]->retrieveEntities();
  }
}

void EntityPool2::printPoolContents() {
  for (unsigned int i = 0; i < pool.size(); i++) {
    pool[i]->print();
  }
  cout << endl;
}
