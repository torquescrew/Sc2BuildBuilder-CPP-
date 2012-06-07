#include "Config.h"
#include <cstdio>
#include <iostream>
#include <sstream>
#include "F.h"

Config::Config() {
  timeLimit = 600;
  numberOfBuilds = 800;
  entitiesPerBuild = 40;
  generations = 20;
  entityPool = true;

  buildListConstructCount = 0;
  buildLIstDestructCount = 0;
  //  init();
}

//void Config::init() {
//  NameList* a = new NameList();
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

//  for (E::Name n : names) {
//    a->add(Info(n));
//  }

//  Config::setAllowed(a);
//  Config::setEntityPoolOption(true);
//}

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

//void Config::setInstance(build_toolInstance *ins) {
//  instance()->btInstance = ins;
//}

//void Config::print(string s) {
//  pp::Var var_reply = pp::Var(s);
//  instance()->btInstance->PostMessage(var_reply);
//}

//void Config::println(string s) {
//  pp::Var var_replay = pp::Var(s);
//  instance()->btInstance->PostMessage(var_replay);
//}
