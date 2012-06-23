#ifndef OBJECTFACT_H
#define OBJECTFACT_H
#include "BuildEval.h"
#include "GameLoop.h"
#include "EntityPool2.h"
#include "Name.h"
#include "Random.h"
#include <string>

class OF {
public:
  OF();
  virtual ~OF();
  void init();
  BuildEval *newBuildEval();
  GameLoop *newGameLoop();
  Entity *newEntity(Info name);
  void retrieveAllEntities();
  EntityPool2 *getEntityPool();
  unsigned getNumBuilds();
  unsigned getNumEntities();
  unsigned getNumGenerations();
  unsigned getTimeLimit();
  unsigned nextInt(unsigned min, unsigned max);
  double nextDouble();
  NameList* getAllowed();
  void updateSetting(std::string s);
private:
  NameList *allowed;
  EntityPool2 *entityPool;

  unsigned timeLimit;
  unsigned num_builds;
  unsigned num_entities;
  unsigned num_generations;

  unsigned seed;
  Random *random;
};

#endif // OBJECTFACT_H
