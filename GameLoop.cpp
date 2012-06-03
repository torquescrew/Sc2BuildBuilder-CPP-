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

GameLoop::GameLoop() {
  displayOption = false;
}

GameLoop::GameLoop(bool displayOption) {
  this->displayOption = displayOption;
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
