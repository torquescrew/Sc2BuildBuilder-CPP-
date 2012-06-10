//#ifndef TESTRUNS_H
//#define TESTRUNS_H

//#include "Config.h"
//#include "GameLoop.h"
//#include "NameList.h"

//class TestRuns {
//public:

//  void runBuild(bool option) {
//    GameLoop *gl = new GameLoop(option);

//    NameList *list = new NameList();

//    Info scv(E::SCV);
//    Info supplyDepot(E::SUPPLY_DEPOT);
//    Info barracks(E::BARRACKS);
//    Info refinery(E::REFINERY);
//    Info orbital(E::ORBITAL_COMMAND);
//    //  Info marine(E::MARINE);

//    list->add(scv);
//    list->add(scv);
//    list->add(scv);
//    list->add(scv);
//    list->add(supplyDepot);
//    list->add(scv);
//    list->add(scv);
//    list->add(barracks);
//    list->add(scv);
//    list->add(refinery);
//    list->add(scv);
//    list->add(scv);
//    list->add(orbital);

//    gl->runInstructions(list);

//    delete list;
//    delete gl;
//  }

//  void memTest() {
//    Config::setEntityPoolOption(true);

//    for (int i = 0; i < 100000; i++) {
//      runBuild(false);
//    }
//  }
//};

//#endif // TESTRUNS_H
