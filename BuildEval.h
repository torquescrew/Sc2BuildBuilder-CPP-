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
#include "EntityPool2.h"
//#include "OF.h"

using namespace std;

class OF;

class BuildEval {
public:
  BuildEval(OF *oF);
  virtual ~BuildEval();
  void setEvents(NameList *list, vector<Event> &events);
  GameState* getGameState();
  bool runInstructions(NameList* list);
//  bool runInstructionsUnTimed(NameList *list);
  bool legalBuild(NameList *list);
  bool nextInstruction(Info info);
  bool nextInstructionUnTimed(Info info, int loops);
protected:
  GameState *gs;
  int trys();
  virtual bool tryAdd(Entity *e, int i);
private:
  BuildEval() {}
  OF *oF;
};

#endif	/* BUILDEVAL_H */

