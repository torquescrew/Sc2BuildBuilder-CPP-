#include "Config.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include "F.h"

Config::Config() {
  timeLimit = 600;
  numberOfBuilds = 200;
  entitiesPerBuild = 200;
  generations = 200;
  entityPool = true;

  buildListConstructCount = 0;
  buildLIstDestructCount = 0;
}

void Config::addToConstructCount() {
  instance()->buildListConstructCount++;
}

void Config::addToDestructCount() {
  instance()->buildLIstDestructCount++;
}

void Config::printCDCounts() {
  stringstream ss;
  ss << "CD counts: (" << instance()->buildListConstructCount
            << "/" << instance()->buildLIstDestructCount << ")";
  F::println(ss.str());
}

NameList* Config::getAllowed() {
  return instance()->allowed;
}

bool Config::isEntityPool() {
  return instance()->entityPool;
}

void Config::setEntityPoolOption(bool entityPool) {
  instance()->entityPool = entityPool;
}

void Config::setAllowed(NameList *allowed) {
  instance()->allowed = allowed;
}

void Config::setTimeLimit(int t) {
  instance()->timeLimit = t;
}

int Config::getTimeLimit() {
  return instance()->timeLimit;
}

unsigned int Config::getNumberOfBuilds() {
  return instance()->numberOfBuilds;
}

string Config::getNumberOfBuildsStr() {
  stringstream ss;
  ss << instance()->numberOfBuilds;
  return ss.str();
}

unsigned int Config::getEntitiesPerBuild() {
  return instance()->entitiesPerBuild;
}

unsigned int Config::getNumOfGenerations() {
  return instance()->generations;
}
