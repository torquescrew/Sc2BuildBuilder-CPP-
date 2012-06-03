#include "Config.h"
#include <cstdio>
#include <iostream>

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
  std::cout << "CD counts: (" << instance()->buildListConstructCount
            << "/" << instance()->buildLIstDestructCount
            << ")" << std::endl;
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

unsigned int Config::getEntitiesPerBuild() {
  return instance()->entitiesPerBuild;
}

unsigned int Config::getNumOfGenerations() {
  return instance()->generations;
}
