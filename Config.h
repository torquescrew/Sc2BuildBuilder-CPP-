/* 
 * File:   Config.h
 * Author: Toby
 *
 * Created on May 10, 2012, 5:13 PM
 */

#ifndef CONFIG_H
#define	CONFIG_H

// Singleton Configuration file
//#include <vector>
#include "NameList.h"
#include "E.h"
#include "string"

using namespace std;

class Config {
  static Config* s_instance;

  Config();

public:

  static Config* instance() {
    if (!s_instance)
      s_instance = new Config;
    return s_instance;
  }

//  static MTRand mt(int i);
  static NameList* getAllowed();
  static bool isEntityPool();
  static void setEntityPoolOption(bool entityPool);
  static void setAllowed(NameList *allowed);
  static void setTimeLimit(int t);
  static int getTimeLimit();
  static unsigned int getNumberOfBuilds();
  static string getNumberOfBuildsStr();
  static unsigned int getEntitiesPerBuild();
  static unsigned int getNumOfGenerations();
  static unsigned int getRandomInt();

  static void addToConstructCount();
  static void addToDestructCount();
  static void printCDCounts();

private:
  int timeLimit;
  int numberOfBuilds;
  int entitiesPerBuild;
  int generations;
  NameList *allowed;
  bool entityPool;

  int buildListConstructCount;
  int buildLIstDestructCount;
};

#endif	/* CONFIG_H */

