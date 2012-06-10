/*
 * Population.h
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#ifndef POPULATION_H_
#define POPULATION_H_

#include "E.h"
#include "BuildList.h"
#include <vector>
#include <string>
#include "EntityPool2.h"
#include "objectfact.h"

class Population {
public:
  Population();
	virtual ~Population();
  void init();
  void initOneList();
	void initLists();
  void crossover();
  void mutate();
	void normalise();
  BuildList* getHighest();
	void printHighest();
  vector<BuildList* > getListOfBuilds();
  void addBuild(BuildList *bl);
	void run();
  int getSize();
  ObjectFact *getObjectFact();
private:
	BuildList* selectParent();
	void printBuilds();
	void checkHighest();
  BuildList* fittestBuild;
	vector<BuildList* > listOfBuilds;
//  EntityPool2 *entityPool;
  ObjectFact *objectFact;
};

#endif /* POPULATION_H_ */
