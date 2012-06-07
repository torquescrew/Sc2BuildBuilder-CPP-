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

//class build_toolInstance;

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
	void run();
  int getSize();
//  void print(string s);
//  void println(string s);
private:
	BuildList* selectParent();
	void printBuilds();
	void checkHighest();
  BuildList* fittestBuild;
	vector<BuildList* > listOfBuilds;
//  build_toolInstance *btIns;
};

#endif /* POPULATION_H_ */
