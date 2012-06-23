//
//  GameLoop.cpp
//  BuildTool
//
//  Created by Toby Suggate on 7/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include "GameLoop.h"
#include "F.h"
#include "OF.h"
#include <string>

GameLoop::GameLoop(OF *oF) : BuildEval(oF) {
//  BuildEval::BuildEval(entityPool);
  Info scv(E::SCV);
F::print("************************************************");
  Entity *e = oF->newEntity(scv);

  F::println(e->getNameStr());


  displayOption = false;
}

GameLoop::GameLoop(OF *oF, bool displayOption) : BuildEval(oF) {
  this->displayOption = displayOption;

  Info scv(E::SCV);
  F::print("************************************************");
  Entity *e = oF->newEntity(scv);

  F::println(e->getNameStr());

}

GameLoop::~GameLoop() {
}

bool GameLoop::tryAdd(Entity* e, int attemptsRemaining) {
  if (attemptsRemaining == 0) {
    return false;
  }
  else {
    if (gs->tryAddEntity(e)) {
      if (displayOption) {
        F::printNewUnit(e->getName(), gs);
      }
      return true;
    } else {
      gs->incrementTime();
      return tryAdd(e, attemptsRemaining - 1);
    }
  }
}
