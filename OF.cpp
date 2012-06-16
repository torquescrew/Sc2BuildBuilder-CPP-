#include "objectfact.h"

ObjectFact::ObjectFact() {
  entityPool = new EntityPool2();
}

ObjectFact::~ObjectFact() {
  std::cout << "~ObjectFact()" << std::endl;
  delete entityPool;
}

// could also auto delete last?
BuildEval *ObjectFact::newBuildEval() {
  return new BuildEval(entityPool);
}

GameLoop *ObjectFact::newGameLoop() {
  return new GameLoop(entityPool, true);
}

Entity *ObjectFact::newEntity(Info name) {
  return entityPool->getNew(name);
}

EntityPool2 *ObjectFact::getEntityPool() {
  return entityPool;
}

//Crossover *ObjectFact::newCrossover() {
//  return new Crossover(this);
//}

