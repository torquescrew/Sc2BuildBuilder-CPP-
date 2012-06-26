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
#include "EntityPool2.h"
#include <string>

class OF;

class GameLoop : public BuildEval {
public:
  explicit GameLoop(OF *oF);
  explicit GameLoop(OF *oF, bool displayOption);
  virtual ~GameLoop() {}
  std::string createHtmlTable(NameList *list);


//  bool runInstructions(NameList &list);
protected:
  bool tryAdd(Entity *e, int i);
  bool displayOption;
private:
  std::string htmlTableRow(Info info);
  bool nextEntity(Entity *e, int i);
  GameLoop();
  OF *oF;
};

#endif
