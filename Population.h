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
#include "OF.h"

class Population {
public:
  Population();
  Population(OF *oF);
	virtual ~Population();
  void init();
  void initOneList();
	void initLists();
  void crossover();
  void mutate();
	void normalise();
  void checkLength();
  BuildList* getHighest();
	void printHighest();
  vector<BuildList* > getListOfBuilds();
  void addBuild(BuildList *bl);
	void run();
  int getSize();
  OF *getOF();
private:
	BuildList* selectParent();
	void printBuilds();
	void checkHighest();
  BuildList* fittestBuild;
	vector<BuildList* > listOfBuilds;
//  EntityPool2 *entityPool;
  OF *oF;
};

#endif /* POPULATION_H_ */
