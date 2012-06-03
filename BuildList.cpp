/*
 * BuildList.cpp
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#include "BuildList.h"
#include "Fitness.h"
#include "F.h"
#include <iostream>
#include "Config.h"
#include "ObjectPool.h"

BuildList::BuildList() {
  entityList = new NameList();
  fitness = 0.0;
  index = 0.0;
  allowed = Config::getAllowed();
}

BuildList::BuildList(BuildList* bl) {
  allowed = Config::getAllowed();
  entityList = new NameList();
  for (unsigned long i = 0; i < bl->getList()->size(); i++) {
    entityList->add(bl->get(i));
  }
  fitness = bl->getFitness();
}

BuildList::~BuildList() {
  delete entityList;
}

bool BuildList::evaluateBuild() {
  events.clear();
  BuildEval be;
  be.setEvents(entityList, events);
  if (events.size() > 2) {
    //    cout << "events: " << events.size() << endl;
    fitness = Fitness::getFitness(be.getGameState(), events);
    return true;
  }
  return false;
}

bool BuildList::legalBuild() {
  BuildEval be;
  return be.legalBuild(entityList);
}

void BuildList::mutate() {
  //  NameList *mutant = new NameList();
  //  for (int i = 0; i < entityList->size(); i++) {
  //    mutant->add(entityList->get(i));
  //  }
  unsigned long num = events.size();
  if (num == 0) {
    num++;
  }

  unsigned long p = F::nextInt(0, num);
  unsigned long r = F::nextInt(0, allowed->size());
  entityList->set(p, allowed->get(r));

  //  if (!evaluateBuild()) {
  //    delete entityList;
  //    entityList = mutant;
  //  }
  evaluateBuild();
}

NameList* BuildList::getList() const {
  return entityList;
}

void BuildList::setIndex(double i) {
  index = i;
}

double BuildList::getFitness() const {
  return fitness;
}

double BuildList::getIndex() const {
  return index;
}

unsigned long BuildList::size() {
  return entityList->size();
}

unsigned long BuildList::getEventNum() {
  return events.size();
}

void BuildList::printBuild() {
  //  cout << "[Fitness: " << fitness << "] ";
  //  for (unsigned int i = 0; i < entityList.size(); i++) {
  //    cout << F::toString(entityList.at(i)) << " ";
  //  }
  //  cout << endl;
}

Info BuildList::get(unsigned long i) {
  return entityList->get(i);
}

void BuildList::add(Info item) {
  entityList->add(item);
}

void BuildList::pureRandomList() {
  while (entityList->size() < Config::getEntitiesPerBuild()) {
    unsigned long r = F::nextInt(0, allowed->size());
    entityList->add(allowed->get(r));
  }
  if (!evaluateBuild()) {
    delete entityList;
    entityList = new NameList();
    pureRandomList();
  }
}

void BuildList::rollBack(BuildEval* be) {
  delete be;
  be = new BuildEval();
  for (unsigned int i = 0; i < entityList->size(); i++) {
    be->nextInstructionUnTimed(entityList->get(i), 200);
  }
}

void BuildList::generateRandomList() {
  BuildEval *be = new BuildEval();
  int failures = 0;
  while (entityList->size() < Config::getEntitiesPerBuild()) {
    unsigned long r = F::nextInt(0, allowed->size());
    unsigned int loops = F::nextInt(1, 15);
    if (be->nextInstructionUnTimed(allowed->get(r), loops)) {
      entityList->add(allowed->get(r));
      failures = 0;
    } else {
      failures++;
      if (failures >= 30) {
        entityList->removeLast();
        rollBack(be);
        failures = 0;
      }
    }
  }
  delete be;
  evaluateBuild();
}
