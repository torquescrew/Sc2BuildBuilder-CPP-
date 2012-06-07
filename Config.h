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
#include <string>
//#include "build_tool.h"

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

  static void init();
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
//  static void setInstance(build_toolInstance *ins);
//  static void print(string s);
//  static void println(string s);

private:
  int timeLimit;
  int numberOfBuilds;
  int entitiesPerBuild;
  int generations;
  NameList *allowed;
  bool entityPool;

  int buildListConstructCount;
  int buildLIstDestructCount;
//  build_toolInstance *btInstance;
};

#endif	/* CONFIG_H */

