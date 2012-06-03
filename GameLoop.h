//
//  GameLoop.h
//  BuildTool
//
//  Created by Toby Suggate on 7/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//

#ifndef BuildTool_GameLoop_h
#define BuildTool_GameLoop_h
#include "GameState.h"
#include <vector>
//#include "Cnfg.h"
#include "NameList.h"
#include "BuildEval.h"

class GameLoop : public BuildEval {
public:
  GameLoop();
  GameLoop(bool displayOption);
  virtual ~GameLoop();
//  bool runInstructions(NameList &list);
protected:
  bool tryAdd(Entity *e, int i);
  bool displayOption;
};

#endif
