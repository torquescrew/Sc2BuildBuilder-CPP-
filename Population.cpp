/*
 * Population.cpp
 *
 *  Created on: Feb 23, 2012
 *      Author: Toby
 */

#include "Population.h"
#include "Crossover.h"
#include "GameLoop.h"
#include "BuildList.h"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include "F.h"
//#include "ObjectPool.h"
#include "Config.h"
#include "E.h"
#include "RandomSingleton.h"
#include "OF.h"
//#include "build_tool.h"


//Config *Config::s_instance = 0;
//ObjectPool *ObjectPool::s_instance = 0;
//RandomSingleton *RandomSingleton::s_instance = 0;

Population::Population() {
  init();
}

void Population::init() {

//  NameList* allowed = new NameList();
//  vector<E::Name> names;

//  names.push_back(E::SCV);
//  names.push_back(E::SUPPLY_DEPOT);
//  names.push_back(E::COMMAND_CENTER);
//  names.push_back(E::BARRACKS);
//  names.push_back(E::ORBITAL_COMMAND);
//  names.push_back(E::REFINERY);
//  names.push_back(E::MARINE);
//  names.push_back(E::MARAUDER);
//  names.push_back(E::BARRACKS_WITH_TECHLAB);
//  names.push_back(E::BARRACKS_WITH_REACTOR);

//  for (unsigned i = 0; i < names.size(); i++) {
//    allowed->add(Info(names[i]));
//  }

//  Config::setAllowed(allowed);
//  Config::setEntityPoolOption(true);
  oF = new OF();
  fittestBuild = new BuildList(oF);
}

void Population::initOneList() {
  BuildList *bl = new BuildList(oF);
  bl->generateRandomList();
  listOfBuilds.push_back(bl);
}

Population::~Population() {
  //  cout << "~Population" << endl;

  delete fittestBuild;
  for (unsigned int i = 0; i < listOfBuilds.size(); i++) {
    delete listOfBuilds[i];
  }

  delete oF;
}

void Population::initLists() {
  while (listOfBuilds.size() < oF->getNumBuilds()) {
    BuildList *bl = new BuildList(oF);
    bl->generateRandomList();
    //    bl->genBuild();
    //    bl->pureRandomList();
    listOfBuilds.push_back(bl);
    //    cout << "entity pool size: " << ObjectPool::getPoolSize() << endl;
    F::printInit(this);
  }
  stringstream ss;
  ss << "Successfully created " << oF->getNumBuilds() << " builds";
  F::println(ss.str());
}

void Population::run() {
  initLists();
  normalise();
  for (unsigned i = 0; i < oF->getNumGenerations(); i++) {
    crossover();
    mutate();
    normalise();
    F::printGen(i, this);
  }
  printHighest();
}

bool compare(BuildList* b1, BuildList* b2);
bool compare(BuildList* b1, BuildList* b2) {
  return b1->getIndex() < b2->getIndex();
}

BuildList* Population::selectParent() {
  //	double r = ((double) (rand() % RAND_MAX)) / RAND_MAX;
  double r = oF->nextDouble();
  BuildList* bl = new BuildList(oF);

  bl->setIndex(r);
  vector<BuildList*>::iterator it;
  it = lower_bound(listOfBuilds.begin(), listOfBuilds.end(), bl, compare); //TODO test this

  delete bl;
  return *it;
}

void Population::mutate() {
  unsigned long build = oF->nextInt(0, listOfBuilds.size());
  listOfBuilds.at(build)->mutate();
}

void Population::crossover() {
  //  cout << "entity pool size: " << ObjectPool::getPoolSize() << endl;
  vector<BuildList*> newBuilds;

  while (newBuilds.size() < oF->getNumBuilds()) {
    BuildList* parent1 = selectParent();
    BuildList* parent2 = selectParent();
//    Crossover *crossover = objectFact->newCrossover();
    Crossover crossover(oF);
    BuildList* child = crossover.createChild(parent1, parent2);
    newBuilds.push_back(child);
  }
  for (unsigned long i = 0; i < listOfBuilds.size(); i++) {
    delete listOfBuilds[i];
  }
  listOfBuilds.clear();
  listOfBuilds.insert(listOfBuilds.end(), newBuilds.begin(), newBuilds.end());
}

void Population::normalise() {
  double sum = 0;
  for (unsigned int i = 0; i < listOfBuilds.size(); i++) {
    sum += listOfBuilds.at(i)->getFitness();
  }
  for (unsigned int i = 0; i < listOfBuilds.size(); i++) {
    listOfBuilds.at(i)->setIndex(listOfBuilds.at(i)->getFitness() / sum);
  }
  sort(listOfBuilds.begin(), listOfBuilds.end(), compare);
  sum = 0;
  for (unsigned int i = 0; i < listOfBuilds.size(); i++) {
    sum += listOfBuilds.at(i)->getIndex();
    listOfBuilds.at(i)->setIndex(sum);
  }
  checkHighest();
}

BuildList *Population::getHighest() {
  checkHighest();
  return fittestBuild;
}

void Population::printBuilds() {
  for (unsigned int i = 0; i < listOfBuilds.size(); i++) {
    listOfBuilds.at(i)->printBuild();
  }
}

void Population::checkHighest() {
  if (listOfBuilds.back()->getFitness() > fittestBuild->getFitness()) {
    delete fittestBuild;
    fittestBuild = new BuildList(listOfBuilds.back());
  }
}

void Population::printHighest() {
//  GameLoop* gl = new GameLoop(true);
  GameLoop* gl = oF->newGameLoop();
  gl->runInstructions(fittestBuild->getList());
  delete gl;
}

vector<BuildList *> Population::getListOfBuilds() {
  return listOfBuilds;
}

void Population::addBuild(BuildList *bl) {
  listOfBuilds.push_back(bl);
}

int Population::getSize() {
  return (int) listOfBuilds.size();
}

OF *Population::getOF() {
  return oF;
}



