/*
 * BuildList.h
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#ifndef BUILDLIST_H_
#define BUILDLIST_H_

#include "E.h"
#include "NameList.h"
#include "Event.h"
#include "GameState.h"
#include "BuildEval.h"
//#include "EntityPool2.h"
#include "objectfact.h"

using namespace std;

class BuildList {
public:
  BuildList(ObjectFact *objectFact);
  BuildList(BuildList *bl);
  virtual ~BuildList();
  bool evaluateBuild();
  bool legalBuild();
  void mutate();
  NameList* getList() const;
  void setPossible(GameState *gs);
  Info get(unsigned long i);
  void setIndex(double i);
  double getFitness() const;
  double getIndex() const;
  unsigned long size();
  unsigned long getEventNum();
  void printBuild();
  void generateRandomList();
  void pureRandomList();
  void rollBack(BuildEval *be);
  void add(Info item);
private:
//  EntityPool2 *entityPool;
  ObjectFact *objectFact;
  NameList *entityList;
  vector<Event> events;
  NameList *allowed;
  double fitness;
  double index;
};

#endif /* BUILDLIST_H_ */
