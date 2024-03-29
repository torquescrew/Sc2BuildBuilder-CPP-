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
#include "Sc2PlannerOut.h"

BuildList::BuildList(OF *oF) {
  this->oF = oF;
  entityList = new NameList();
  fitness = 0.0;
  index = 0.0;
}

BuildList::BuildList(BuildList* bl) {
  entityList = new NameList();
  for (unsigned long i = 0; i < bl->getList()->size(); i++) {
    entityList->add(bl->get(i));
  }
  fitness = bl->getFitness();
}

BuildList::~BuildList() {
  delete entityList;
}

//TODO manage be memory in objectFact
void BuildList::evaluateBuild() {
  events.clear();
  BuildEval *be = oF->newBuildEval();
  be->setEvents(entityList, events);
  if(events.size() > 2) {
    fitness = Fitness::getFitness(be->getGameState(), events);
  }
  delete be;
}

bool BuildList::legalBuild() {
  BuildEval *be = oF->newBuildEval();
  if (be->legalBuild(entityList)) {
    delete be;
    return true;
  } else {
    delete be;
    return false;
  }
}

void BuildList::mutate() {
  unsigned long num = events.size();
  if (num == 0) {
    num++;
  }
  unsigned long p = oF->nextInt(0, num);
  unsigned long r = oF->nextInt(0, oF->getAllowed()->size());
  entityList->set(p, oF->getAllowed()->get(r));

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
  //	if (events.empty()) {
  //		return 0;
  //	}
  return events.size();
}

void BuildList::printBuild() {
}

Info BuildList::get(unsigned long i) {
  return entityList->get(i);
}

void BuildList::add(Info item) {
  entityList->add(item);
}

//void BuildList::pureRandomList() {
//	while (entityList->size() < oF->getNumEntities()) {
//		unsigned long r = oF->nextInt(0, oF->getAllowed()->size());
//		entityList->add(oF->getAllowed()->get(r));
//	}
//	if (!evaluateBuild()) {
//		delete entityList;
//		entityList = new NameList();
//		pureRandomList();
//	}
//}

void BuildList::rollBack(BuildEval* be) {
  delete be;
  be = oF->newBuildEval();
  for (unsigned i = 0; i < entityList->size(); i++) {
    be->nextInstructionUnTimed(entityList->get(i), 200);
  }
}

void BuildList::generateRandomList() {
  BuildEval *be = oF->newBuildEval();
  int failures = 0;
  while (entityList->size() < oF->getNumEntities()) {
    unsigned r = oF->nextInt(0, oF->getAllowed()->size());
    unsigned loops = oF->nextInt(1, 15);
    if (be->nextInstructionUnTimed(oF->getAllowed()->get(r), loops)) {
      entityList->add(oF->getAllowed()->get(r));
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

string BuildList::getSc2PlannerLink() {
  Sc2PlannerOut out(events);
  return out.createLink();
}

void BuildList::lengthenEntityList() {
  if (entityList->size() < oF->getNumEntities()) {
    BuildEval *be = oF->newBuildEval();
    for (unsigned i = 0; i < entityList->size(); i++) {
      be->nextInstructionUnTimed(entityList->get(i), 200);
    }
    int failures = 0;
    while (entityList->size() < oF->getNumEntities()) {
      unsigned long r = oF->nextInt(0, oF->getAllowed()->size());
      unsigned long loops = oF->nextInt(1, 15);
      if (be->nextInstructionUnTimed(oF->getAllowed()->get(r), loops)) {
        entityList->add(oF->getAllowed()->get(r));
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
//    evaluateBuild();
  }
}
