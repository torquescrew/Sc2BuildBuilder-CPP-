/*
 * AllEntities.cpp
 *
 *  Created on: May 5, 2012
 *      Author: Toby
 */

#include "AllEntities.h"
#include "F.h"
#include "Producer.h"
#include "GameState.h"
#include "E.h"
#include "Scv.h"
#include "Config.h"
//#include "ObjectPool.h"
#include <iostream>
#include "OF.h"

AllEntities::AllEntities(OF *oF) {
  this->oF = oF;
//  std::cout << "AllEntities() entityPool address: " << this->entityPool << std::endl;
}

AllEntities::~AllEntities() {
//  ObjectPool::retrieveAll();
  oF->retrieveAllEntities();
}

void AllEntities::update(GameState* gs) {
  for (unsigned i = 0; i < entities.size(); i++) {
    entities[i]->update(gs);
  }
//  for (Entity *e : entities) {
//    e->update(gs);
//  }
  transferNewEntities(gs);
  gatherIdleWorkers();
}

bool AllEntities::contains(E::Name name) {
  for (unsigned i = 0; i < entities.size(); i++) {
    if (entities[i]->getName() == name) {
      return true;
    }
  }
  return false;
}

vector<Entity*>& AllEntities::getEntities() {
  return entities;
}

void AllEntities::addNew(Entity *e) {
  newEntities.push_back(e);
}

void AllEntities::directAdd(Entity* e) {
  entities.push_back(e);
}

bool AllEntities::tryAddEntity(Entity *e, int time) {
  for (unsigned i = 0; i < e->getBuiltBy().size(); i++) {
    if (e->getBuiltBy()[i] == E::SCV) {
      takeScvOffMining();
    }
    for (unsigned j = 0; j < entities.size(); j++) {
      if (e->getBuiltBy()[i] == entities[j]->getName()) {
        if (((Producer*) entities[j])->tryBuildEntity(e, time)) {
          return true;
        }
      }
    }
  }
  return false;
}

//bool AllEntities::inert(E::Name name) {
//  if (name == E::MARINE || name == E::SUPPLY_DEPOT || name == E::MARAUDER) {
//    return true;
//  }
//  return false;
//}

void AllEntities::transferNewEntities(GameState *gs) {
  for (unsigned i = 0; i < newEntities.size(); i++) {
    newEntities[i]->complete(gs);
    //      entities.push_back(newEntities[i]);
  }
  newEntities.clear(); //Entity pointers persist in entities
}

void AllEntities::printEntities() {
  for (unsigned i = 0; i < entities.size(); i++) {
//    std::cout << entities[i]->getNameStr() << ", ";
    F::print(entities[i]->getNameStr() + ", ");
  }
  F::println();
//  std::cout << std::endl;
}

int AllEntities::idleWorkerIndex() {
  for (unsigned i = 0; i < entities.size(); i++) {
    if (entities[i]->getName() == E::SCV) {
      Scv *s = (Scv*) entities[i];
      if (!s->busy()) {
        return i;
      }
    }
  }
  return -1;
}

void AllEntities::gatherIdleWorkers() {
  int idleIndex = idleWorkerIndex();
  while (idleIndex != -1) {
    sendToMine(entities[idleIndex]);
    entities.erase(entities.begin() + idleIndex);
    idleIndex = idleWorkerIndex();
  }
}

vector<Command*> AllEntities::getCommands() {
  std::vector<Command*> CCs;
  for (unsigned i = 0; i < entities.size(); i++) {
    if (entities[i]->isCommand()) {
      Command *c = (Command*) entities[i];
      CCs.push_back(c);
    }
  }
  return CCs;
}

int AllEntities::getNumOf(Entity* e) {
  int c = 0;
  for (unsigned i = 0; i < entities.size(); i++) {
    if (entities[i]->getName() == e->getName()) {
      c++;
    }
  }
  return c;
}

void AllEntities::sendToMine(Entity *scv) {
  vector<Command*> CCs = getCommands();
  int index = 0;
  for (unsigned i = 1; i < CCs.size(); i++) {
    if (CCs[i]->numberMining() < CCs[index]->numberMining()) {
      index = i;
    }
  }
  CCs[index]->sendToMineMinerals(scv);
}

Entity* AllEntities::getScvOffMining() {
  vector<Command*> CCs = getCommands();
  for (unsigned i = 0; i < CCs.size(); i++) {
    if (CCs[i]->numberMining() > 1) {
      return CCs[i]->getScv();
    }
  }
  return 0;
}

bool AllEntities::takeScvOffMining() {
  Entity *scv = getScvOffMining();
  if (scv != 0) {
    entities.push_back(scv);
    return true;
  }
  return false;
}
