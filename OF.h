#ifndef OBJECTFACT_H
#define OBJECTFACT_H
#include "BuildEval.h"
#include "GameLoop.h"
#include "EntityPool2.h"
//#include "Crossover.h"
#include "Name.h"



class ObjectFact {
public:
  ObjectFact();
  virtual ~ObjectFact();
  BuildEval *newBuildEval();
  GameLoop *newGameLoop();
  Entity *newEntity(Info name);
//  Crossover *newCrossover();
  EntityPool2 *getEntityPool();

private:
  EntityPool2 *entityPool;
};

#endif // OBJECTFACT_H
