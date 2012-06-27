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
#include "OF.h"

using namespace std;

class BuildList {
public:
  BuildList(OF *oF);
  BuildList(BuildList *bl);
  virtual ~BuildList();
  void evaluateBuild();
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
  void lengthenEntityList();
  void generateRandomList();
//  void pureRandomList();
  void rollBack(BuildEval *be);
  void add(Info item);
private:
//  EntityPool2 *entityPool;
  OF *oF;
  NameList *entityList;
  vector<Event> events;
//  NameList *allowed;
  double fitness;
  double index;
};

#endif /* BUILDLIST_H_ */
