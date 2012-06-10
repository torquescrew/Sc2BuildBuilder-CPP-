//
//  main.cpp
//  BuildTool
//
//  Created by Toby Suggate on 6/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
#include "Config.h"
#include "NameList.h"
#include "Population.h"
//#include "ObjectPool.h"
#include "TestRuns.h"
//#include "Random.h"
#include "F.h"
#include "RandomSingleton.h"
#include "SearchParallel.h"

using namespace std;


void setConfig();

int main() {
//  TestRuns t;
//  t.memTest();

  setConfig();

//  F::println("Config set");

  SearchParallel sp;
//  F::println("contructed sp");
  sp.run();

  //  for (int i = 0; i < 500; i++) {
//      Population p;
//      p.run();
  //  }
}

void setConfig() {
  NameList* allowed = new NameList();
  vector<E::Name> names;

  names.push_back(E::SCV);
  names.push_back(E::SUPPLY_DEPOT);
  names.push_back(E::COMMAND_CENTER);
  names.push_back(E::BARRACKS);
  names.push_back(E::ORBITAL_COMMAND);
  names.push_back(E::REFINERY);
  names.push_back(E::MARINE);
  names.push_back(E::MARAUDER);
  names.push_back(E::BARRACKS_WITH_TECHLAB);
  names.push_back(E::BARRACKS_WITH_REACTOR);

  for (E::Name n : names) {
    allowed->add(Info(n));
  }

  Config::setAllowed(allowed);
  Config::setEntityPoolOption(true);
}



