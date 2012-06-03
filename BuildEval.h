/* 
 * File:   BuildEval.h
 * Author: Toby
 *
 * Created on May 10, 2012, 2:03 PM
 */

#ifndef BUILDEVAL_H
#define	BUILDEVAL_H
#include "GameState.h"
#include "Name.h"
#include "Event.h"
#include <vector>

using namespace std;

class BuildEval {
public:
  BuildEval();
  virtual ~BuildEval();
  void setEvents(NameList *list, vector<Event> &events);
  GameState* getGameState();
  bool runInstructions(NameList *list);
//  bool runInstructionsUnTimed(NameList *list);
  bool legalBuild(NameList *list);
  bool nextInstruction(Info info);
  bool nextInstructionUnTimed(Info info, int loops);
protected:
  GameState *gs;
  int trys();
  virtual bool tryAdd(Entity *e, int i);
};

#endif	/* BUILDEVAL_H */

