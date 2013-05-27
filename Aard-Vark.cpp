//
//  main.cpp
//  BuildTool
//
//  Created by Toby Suggate on 6/05/12.
//  Copyright (c) 2012 __MyCompanyName__. All rights reserved.
//
//#include "Config.h"
#include "NameList.h"
#include "Population.h"
//#include "TestRuns.h"
//#include "F.h"
//#include "SearchParallel.h"

//for test()
#include "OF.h"
#include "GameLoop.h"
#include "NameList.h"
#include "Name.h"
#include <iostream>

using namespace std;

void test() {
  NameList *nl = new NameList();
  nl->add(Info(E::SCV));
  nl->add(Info(E::SCV));
  nl->add(Info(E::SCV));
  nl->add(Info(E::SCV));
  nl->add(Info(E::SUPPLY_DEPOT));

  OF *of = new OF();
  GameLoop *gl = of->newGameLoop();
  gl->runInstructions(nl);

  cout << gl->getGameState()->getAe()->getCommands().at(0)->getWorkersOnMinerals().size() << endl;
}

int main() {
//  test();

  Population p;
  p.run();
}




