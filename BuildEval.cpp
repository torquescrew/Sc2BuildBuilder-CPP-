
/* 
 * File:   BuildEval.cpp
 * Author: Toby
 *
 * Created on May 10, 2012, 2:03 PM
 */

#include <iostream>

#include "BuildEval.h"
#include "F.h"
#include "Config.h"
#include "ObjectPool.h"

BuildEval::BuildEval() {
  gs = new GameState();
}

BuildEval::~BuildEval() {
  delete gs;
}

int BuildEval::trys() {
  unsigned int t = Config::getTimeLimit() - gs->getTime();
  if (t > 100)
    return 100;
  else
    return t;
}

//bool BuildEval::tryAdd(Entity* e, int attemptsRemaining) {
//  if (attemptsRemaining <= 0) {
//    return false;
//  } else if (gs->tryAddEntity(e)) {
//    return true;
//  } else {
//    gs->incrementTime();
//    tryAdd(e, attemptsRemaining - 1);
//  }
//}

bool BuildEval::tryAdd(Entity *e, int loops) {
  for (int i = 0; i < loops; i++) {
    if (gs->tryAddEntity(e)) {
      return true;
    }
    else {
      gs->incrementTime();
    }
  }
  return false;
}

bool BuildEval::nextInstruction(Info info) {
//  Entity *e = F::create(info);
  Entity *e = ObjectPool::get(info);
  return tryAdd(e, trys());
}

bool BuildEval::nextInstructionUnTimed(Info info, int loops) {
//  Entity *e = F::create(info);
  Entity *e = ObjectPool::get(info);
  return tryAdd(e, loops);
}

//bool BuildEval::runInstructionsUnTimed(NameList *list) {
//  for (unsigned int i = 0; i < list->size(); i++) {
//    if (!nextInstructionUnTimed(list->get(i), 200)) {
//      return false;
//    }
//  }
//  return true;
//}

bool BuildEval::runInstructions(NameList *list) {
  for (unsigned int i = 0; i < list->size(); i++) {
    if (!nextInstruction(list->get(i))) {
      return false;
    }
  }
  return true;
}

bool BuildEval::legalBuild(NameList *list) {
  for (unsigned int i = 0; i < list->size(); i++) {
    if (!nextInstructionUnTimed(list->get(i), 200)) {
      return false;
    }
  }
  return true;
  //return runInstructionsUnTimed(list); // || gs->getTime() > (Config::getTimeLimit() - 2);
}

void BuildEval::setEvents(NameList *list, vector<Event> &events) {
  unsigned int i = 0;
  while (i < list->size() && nextInstruction(list->get(i))) {
    events.push_back(Event(list->get(i), gs->getTime()));
    i++;
  }
}

GameState* BuildEval::getGameState() {
  return gs;
}
