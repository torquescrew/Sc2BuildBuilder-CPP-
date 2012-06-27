
/* 
 * File:   BuildEval.cpp
 * Author: Toby
 *
 * Created on May 10, 2012, 2:03 PM
 */

#include <iostream>
#include "BuildEval.h"
#include "F.h"
#include "OF.h"

BuildEval::BuildEval(OF *oF) {
  this->oF = oF;
  gs = new GameState(this->oF);
}

BuildEval::~BuildEval() {
  delete gs;
}

int BuildEval::trys() {
  unsigned int t = oF->getTimeLimit() - gs->getTime();
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
  Entity *e = oF->newEntity(info);
  return tryAdd(e, trys());
}

bool BuildEval::nextInstructionUnTimed(Info info, int loops) {
  Entity *e = oF->newEntity(info);
  return tryAdd(e, loops);
}

bool BuildEval::runInstructions(NameList *list) {
  for (unsigned i = 0; i < list->size(); i++) {
    if (!nextInstruction(list->get(i))) {
      return false;
    }
  }
  return true;
}

bool BuildEval::legalBuild(NameList *list) {
  for (unsigned i = 0; i < list->size(); i++) {
    if (!nextInstructionUnTimed(list->get(i), 200)) {
      return false;
    }
  }
  return true;
}

void BuildEval::setEvents(NameList *list, vector<Event> &events) {
  unsigned i = 0;
  while (i < list->size() && nextInstruction(list->get(i))) {
    events.push_back(Event(list->get(i), gs->getTime()));
    i++;
  }
}

GameState* BuildEval::getGameState() {
  return gs;
}
